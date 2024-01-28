#include "s21_decimal.h"

// сложение двух чисел
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!result) return 1;
  s21_decimal_clear(result);
  int error = 0;
  if (is_null_dec(value_1)) {
    *result = value_2;
  } else if (is_null_dec(value_2)) {
    *result = value_1;
  } else {
    if (is_null_dec(value_1)) s21_decimal_clear(&value_1);
    if (is_null_dec(value_2)) s21_decimal_clear(&value_2);
    int precision = s21_getscale(value_1) > s21_getscale(value_2)
                        ? s21_getscale(value_1)
                        : s21_getscale(value_2);
    s21_decimal_clear(result);

    if (s21_getscale(value_1) != s21_getscale(value_2))
      s21_scale_is_equal(&value_1, &value_2);

    if (s21_getsign(value_2) && !s21_getsign(value_1) ||
        !s21_getsign(value_2) && s21_getsign(value_1)) {
      if (s21_is_less(value_1, value_2)) {
        s21_decimal buf_val_1 = {0};
        buf_val_1 = value_1;
        s21_setsign(&buf_val_1, 0);
        error = s21_sub(value_2, buf_val_1, result);
        if (s21_is_greater(buf_val_1, value_2)) {
          s21_setsign(result, 1);
        }
      } else {
        s21_decimal buf_val_2 = {0};
        buf_val_2 = value_2;
        s21_setsign(&buf_val_2, 0);
        error = s21_sub(value_1, buf_val_2, result);
        if (s21_is_greater(buf_val_2, value_1)) {
          s21_setsign(result, 1);
        }
      }
    }
    if (s21_getsign(value_1) == s21_getsign(value_2)) {
      s21_longdecimal dec_l1 = {0};
      s21_longdecimal dec_l2 = {0};
      s21_from_decimal_to_longdecimal(value_1, &dec_l1);
      s21_from_decimal_to_longdecimal(value_2, &dec_l2);
      s21_longdecimal res = {0};
      unsigned_add(dec_l1, dec_l2, &res);
      set_long_scale(&res, precision);
      error = s21_from_longdecimal_to_decimal(res, result);
      if (s21_getsign(value_2)) s21_setsign(result, 1);
    }
    if (error == 1 && s21_getsign(*result)) error = 2;
    if (is_null_dec(*result)) s21_decimal_clear(result);
    if (error) s21_decimal_clear(result);
  }
  return error;
}

void s21_sub_big_decimal(s21_longdecimal value_1, s21_longdecimal value_2,
                         s21_longdecimal *result) {
  int tmp = 0, res;
  for (int i = 0; i < 192; i++) {
    res = s21_getbit_long(value_1, i) - s21_getbit_long(value_2, i) - tmp;

    tmp = res < 0;
    res = abs(res);
    s21_setbit_long(result, i, res % 2);
  }
}

int is_null_dec(s21_decimal dec) {
  int rez = 0;
  for (int i = 0; i < 3; i++) {
    if (dec.bits[i] == 0) rez++;
  }
  return (rez == 3) ? 1 : 0;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal_clear(result);
  int error = 0;

  int sign_res = 0;
  if (s21_getsign(value_1) && s21_getsign(value_2)) {
    s21_decimal temporary1 = value_1;
    value_1 = value_2;
    value_2 = temporary1;

    s21_setbit(&value_1, 127, 0);
    s21_setbit(&value_2, 127, 0);
  }

  s21_scale_is_equal(&value_1, &value_2);

  if (s21_getsign(value_1) != s21_getsign(value_2)) {
    s21_getsign(value_1) ? sign_res = 1 : 1;
    s21_setbit(&value_1, 127, 0);
    s21_setbit(&value_2, 127, 0);
    error = s21_add(value_1, value_2, result);

  } else {
    s21_longdecimal v1 = {0}, v2 = {0}, r = {0};
    s21_from_decimal_to_longdecimal(value_1, &v1);
    s21_from_decimal_to_longdecimal(value_2, &v2);

    s21_sub_big_decimal(v1, v2, &r);
    if (s21_is_greater_big_decimal(v2, v1)) {
      sign_res = !(s21_getsign(value_2));
      invertion(&r);
    }
    if (s21_getscale(value_1) >= 0) {
      error = s21_from_longdecimal_to_decimal(r, result);
      s21_setscale(result, s21_getscale(value_1));
    }
  }
  sign_res == 1 ? s21_setsign(result, 1) : 0;
  if (is_null_dec(*result)) null_decimal(result);
  if (error == 1 && s21_getsign(*result)) error = 2;

  return error;
}