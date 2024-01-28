#include "s21_decimal.h"

int s21_from_decimal_to_longdecimal(s21_decimal src, s21_longdecimal *dst) {
  s21_longdecimal dec = {0};
  *dst = dec;
  for (int i = 0; i < 3; i++) {
    dst->bits[i] &= 0x00000000;
    dst->bits[i] = src.bits[i] & MAX4BITS;
  }
  dst->data = src.bits[3];
  return dst != NULL ? 0 : CONVERTION_ERR;
}

int s21_get_scale_float(double num) {
  int count_figures = 0, scale = 0, find_figures = 0;
  double temp = 0;
  num = fabs(num);
  modf(num, &temp);
  for (int i = 1; temp; i++) {
    count_figures = i;
    temp = round(temp / 10);
  }
  for (int i = 1; num && count_figures < 7 && i < 29; i++) {
    num = modf(num * 10, &temp);
    num = round(num * pow(10, 28)) / pow(10, 28);
    find_figures = !count_figures && temp ? 1 : find_figures;
    count_figures += count_figures || find_figures ? 1 : 0;
    temp += round(num * 10) / 10;
    scale = (round(temp)) && (round(temp) < 10) ? i : scale;
  }
  return scale;
}

double s21_round_float(double num) {
  double result = num;
  int power = 0;
  while (fabs(num) >= pow(10, 7)) {
    num /= 10;
    power++;
  }
  //  num = power ? round(num) : num;
  //  num = power ? modf(num, &result) : num;
  result *= pow(10, power);
  return result;
}

int s21_get_exp_double(double num) {
  converter_double conv = {num};
  return ((conv.int64_value >> 52) & 0x7FF) - 1023;
}

void s21_set_sign_neg(s21_decimal *dst, int is_negative) {
  converter conv = {dst->bits[3]};
  conv.bytes[3] = is_negative ? 128 : 0;
  dst->bits[3] = conv.num;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error = (!dst);
  if (!error && fabsf(src) < MIN_FLOAT && fabsf(src) > 0) {
    s21_decimal_clear(dst);
    error = 1;
  } else if (!error && (isinf(fabsf(src)) || isnan(src))) {
    error = 1;
  } else {
    int scale = s21_get_scale_float(src);
    double long_src = scale ? src : s21_round_float(src);
    long_src = round(long_src * pow(10, scale));
    int exp = s21_get_exp_double(long_src);
    error = exp > 96 ? 1 : error;
    if (exp < 96) {
      converter_double conv = {long_src};
      int sign = conv.int64_value >> 63;
      s21_decimal_clear(dst);
      s21_setbit(dst, exp--, 1);
      for (int i = 51; i >= 0 && exp >= 0; i--, exp--) {
        int bit = conv.int64_value & ((int64_t)1 << i) ? 1 : 0;
        s21_setbit(dst, exp, bit);
      }
      s21_setscale(dst, scale);
      //      s21_setsign(dst, sign);
      s21_set_sign_neg(dst, sign);
    }
  }
  return error;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (dst == NULL || src == NAN) return CONVERTION_ERR;
  null_decimal(dst);
  dst->bits[0] &= 0x00000000;
  if (src < 0) {
    dst->bits[3] |= MINUS;
    src = abs(src);
  }
  dst->bits[0] = src;
  return OK;
}

int check_long_overflow(s21_longdecimal dec) {
  return (dec.bits[5] || dec.bits[4] || dec.bits[3]);
}

void div_ten(s21_longdecimal *dec) {
  s21_longdecimal one = {0};
  one.bits[0] = 1;
  unsigned a = dec->bits[5];
  unsigned long long numberer = a;
  int last_number;
  for (int i = 5; i >= 0; i--) {
    last_number = numberer % 10;
    dec->bits[i] = numberer / 10;
    a = dec->bits[i - 1];
    numberer = last_number * (4294967296) + a;
  }
  if (!check_long_overflow(*dec) || get_long_scale(*dec) < 29) {
    if (last_number > 5) {
      unsigned_add(one, *dec, dec);
    } else if (last_number == 5) {
      a = dec->bits[0];
      if (a % 2 == 1) unsigned_add(one, *dec, dec);
    }
  }
}

int s21_from_longdecimal_to_decimal(s21_longdecimal src, s21_decimal *dst) {
  s21_decimal dec = {0};
  *dst = dec;

  if (check_long_overflow(src)) {
    int scale = get_long_scale(src);
    for (; (scale > 0) && check_long_overflow(src); scale--) {
      div_ten(&src);
    }
    set_long_scale(&src, scale);
  }
  if (get_long_scale(src) > 28) {
    int scale = get_long_scale(src);
    for (; scale > 28; scale--) {
      div_ten(&src);
    }
    set_long_scale(&src, scale);
  }

  for (int i = 0; i < 3; i++) {
    dst->bits[i] = src.bits[i];
  }

  dst->bits[3] = src.data;

  return check_long_overflow(src);
}

int s21_from_decimal_to_longdouble(s21_decimal src, long double *dst) {
  long double sum = 0;
  int errorNumber = OK;
  if (dst != NULL) {
    *dst = 0;
    for (int i = 0; i < 96; i++) {
      sum = sum + s21_getbit(src, i) * pow(2, i);
    }
    int scale = s21_getscale(src);
    sum = sum * pow(10, -scale);
    if (s21_getbit(src, 127)) {
      sum = sum * (-1);
    }
    *dst = sum;
  } else {
    errorNumber = CONVERTION_ERR;
  }
  return errorNumber;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  double sum = 0;
  int scale = s21_getscale(src);
  int errorNumber = OK;
  if (dst != NULL || scale <= 28) {
    for (int i = 0; i < 96; i++) {
      sum = sum + s21_getbit(src, i) * pow(2, i);
    }
    sum = sum * pow(10, -scale);
    if (s21_getbit(src, 127)) {
      sum = sum * (-1);
    }
    *dst = sum;
  } else {
    errorNumber = CONVERTION_ERR;
  }
  return errorNumber;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int errorNumber = OK;
  int sum = 0;
  if ((src.bits[1] || src.bits[2])) {
    errorNumber = CONVERTION_ERR;
  } else {
    for (int i = 0; i < 32; i++) {
      sum = sum + s21_getbit(src, i) * pow(2, i);
    }
  }
  if (s21_getbit(src, 127)) {
    sum = sum * (-1);
  }
  if (s21_getscale(src) > 0 && s21_getscale(src) <= 28) {
    sum = sum / pow(10, s21_getscale(src));
  } else {
    errorNumber = CONVERTION_ERR;
  }
  *dst = sum;
  return errorNumber;
}
