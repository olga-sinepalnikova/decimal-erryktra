#include "s21_decimal.h"

int s21_getbit(s21_decimal dec,
               int position) {  //определить значение бита на позиции
  if (position < 0 || position > 127) return -1;
  int bit_index = position % 32;
  int arr_index = position / 32;
  unsigned int mask = 1 << bit_index;
  int res = (dec.bits[arr_index] & mask) >> bit_index;
  return res;
}

int s21_setbit(s21_decimal *dec, int position,
               int value) {  // установить значение бита 0/1
  if (position < 0 || position > 127) return -1;
  int bit_index = position % 32;
  int arr_index = position / 32;
  unsigned int mask = 1 << bit_index;
  if (value == 0) {
    mask = ~mask;
    dec->bits[arr_index] = dec->bits[arr_index] & mask;
  }
  if (value == 1) {
    dec->bits[arr_index] = dec->bits[arr_index] | mask;
  }
  return (dec->bits[arr_index]);
}

int s21_getscale(s21_decimal dec) {  //определение степени
  dec.bits[3] = dec.bits[3] << 1;
  int scale = dec.bits[3] >> 17;
  return (scale < 29 ? scale : -1);
}

int get_long_scale(s21_longdecimal dec) {
  dec.data = dec.data << 1;
  int scale = dec.data >> 17;
  return scale;
}

int s21_getsign(s21_decimal dec) {  //определение знака числа      1 -
                                    //отрицательное, 0 - положительное
  unsigned int mask = 1 << 31;
  int res = (dec.bits[3] & mask) >> 31;
  return res;
}

int get_long_sign(s21_longdecimal dec) {  //определение знака числа      1 -
                                          //отрицательное, 0 - положительное
  int mask = 1 << 31;
  int res = (dec.data & mask) >> 31;
  return res;
}

void s21_setsign(s21_decimal *dec, int sign) {  //установить знак
  if (sign == 1) s21_setbit(dec, 127, 1);
  if (sign == 0) s21_setbit(dec, 127, 0);
}

void s21_setscale(s21_decimal *dec, int new_scale) {  //установить степень
  int sign = s21_getsign(*dec);
  unsigned int mask = new_scale << 16;  //
  dec->bits[3] = mask;
  if (sign == 1)
    s21_setsign(dec, 1);
  else
    s21_setsign(dec, 0);
}

void set_long_scale(s21_longdecimal *dec, int new_scale) {
  int sign = get_long_sign(*dec);
  unsigned int mask = new_scale << 16;  //
  dec->data = mask;
  if (sign == 1)
    dec->data |= MINUS;
  else
    dec->data |= PLUS;
}

int s21_shiftleft(s21_decimal *dec, int shift) {  //сдвиг всего децимала влево
  int flag = 0;
  for (int i = 0; i < shift; i++) {
    int bit_32 = s21_getbit(*dec, 31);
    int bit_64 = s21_getbit(*dec, 63);
    int bit_96 = s21_getbit(*dec, 95);
    dec->bits[0] <<= 1;
    dec->bits[1] <<= 1;
    dec->bits[2] <<= 1;
    s21_setbit(dec, 32, bit_32);
    s21_setbit(dec, 64, bit_64);
    if (bit_96) flag = 1;
  }
  return flag;
}

s21_decimal s21_simple_addition(s21_decimal *dec_1, s21_decimal *dec_2,
                                s21_decimal *res) {
  int save_space = 0;
  int buffer_1 = 0;
  int buffer_2 = 0;
  for (int i = 0; i <= 96; i++) {
    buffer_1 = s21_getbit(*dec_1, i);
    buffer_2 = s21_getbit(*dec_2, i);
    if (!buffer_1 && !buffer_2 && !save_space) {
      s21_setbit(res, i, 0);  //оба бита ноль, нет в запасе
      save_space = 0;
    } else if (buffer_1 != buffer_2 && !save_space) {
      s21_setbit(res, i, 1);  //один из битов 1, нет в запасе
      save_space = 0;
    } else if (buffer_1 && buffer_2 &&
               !save_space) {  //оба бита 1, нет в запасе, в результат - 0,
                               //закидываем единицу
      s21_setbit(res, i, 0);
      save_space = 1;
    } else if (!buffer_1 && !buffer_2 &&
               save_space) {  //оба бита 0, но есть в запасе
      s21_setbit(res, i, 1);
      save_space = 0;
    } else if (buffer_1 && buffer_2 &&
               save_space) {  //оба бита 1, есть в запасе
      s21_setbit(res, i, 1);
      save_space = 1;
    } else if (buffer_1 != buffer_2 &&
               save_space) {  //один из битов 1, есть в запасе
      s21_setbit(res, i, 0);
      save_space = 1;
    }
  }
  return *res;
}

void s21_mul_ten(s21_decimal *dec, s21_decimal *res) {  //перенос запятой вправо
  s21_decimal_clear(res);
  s21_decimal buffer_1 = *dec;
  s21_decimal buffer_2 = *dec;
  s21_shiftleft(&buffer_1, 3);
  s21_shiftleft(&buffer_2, 1);
  *res = s21_simple_addition(&buffer_1, &buffer_2, res);
  if (s21_getsign(*dec)) s21_setsign(res, 1);
  int scale =
      s21_getscale(*dec) + 1;  //вычитаем, потому что степень отрицательная
  s21_setscale(res, scale);
}

void s21_scale_is_equal(s21_decimal *dec_1, s21_decimal *dec_2) {
  int delta = 0;
  int flag = 0;
  s21_decimal buffer_1 = {{0, 0, 0, 0}};
  s21_decimal buffer_2 = {{0, 0, 0, 0}};
  if (s21_getscale(*dec_1) != s21_getscale(*dec_2)) {
    if (s21_getscale(*dec_1) > s21_getscale(*dec_2)) {
      delta = s21_getscale(*dec_1) - s21_getscale(*dec_2);
      flag = 1;
    } else if (s21_getscale(*dec_1) < s21_getscale(*dec_2)) {
      delta = s21_getscale(*dec_2) - s21_getscale(*dec_1);
    }
    if (flag) {
      for (int i = 0; i < delta; i++) {
        s21_mul_ten(dec_2, &buffer_2);
        *dec_2 = buffer_2;
      }
      *dec_2 = buffer_2;
    } else {
      for (int i = 0; i < delta; i++) {
        s21_mul_ten(dec_1, &buffer_1);
        *dec_1 = buffer_1;
      }
      *dec_1 = buffer_1;
    }
  }
}

int s21_is_greater_big_decimal(s21_longdecimal value_1,
                               s21_longdecimal value_2) {
  int result = 0, out = 0;
  for (int i = 6; i >= 0 && !result && !out; i--) {
    if (value_1.bits[i] || value_2.bits[i]) {
      if (value_1.bits[i] > value_2.bits[i]) {
        result = 1;
      }
      if (value_1.bits[i] != value_2.bits[i]) out = 1;
    }
  }

  return result;
}

void invertion(s21_longdecimal *val) {
  for (int i = 0; i < 6; i++) {
    val->bits[i] = ~val->bits[i];
  }
  val->bits[0] += 1;
  if (val->bits[0] < 0) val->bits[0] = ~val->bits[0];
}

int s21_getbit_long(s21_longdecimal dec,
                    int position) {  //определить значение бита на позиции
  if (position < 0 || position > 223) return -1;
  int bit_index = position % 32;
  int arr_index = position / 32;
  unsigned int mask = 1 << bit_index;
  int res = (dec.bits[arr_index] & mask) >> bit_index;
  return res;
}

int s21_setbit_long(s21_longdecimal *dec, int position,
                    int value) {  // установить значение бита 0/1
  if (position < 0 || position > 191) return -1;
  int bit_index = position % 32;
  int arr_index = position / 32;
  unsigned int mask = 1 << bit_index;
  if (value == 0) {
    mask = ~mask;
    dec->bits[arr_index] = dec->bits[arr_index] & mask;
  }
  if (value == 1) {
    dec->bits[arr_index] = dec->bits[arr_index] | mask;
  }
  return (dec->bits[arr_index]);
}

int s21_shiftleft_long(s21_longdecimal *dec,
                       int shift) {  //сдвиг всего децимала влево
  int flag = 0;
  for (int i = 0; i < shift; i++) {
    int bit_32 = s21_getbit_long(*dec, 31);
    int bit_64 = s21_getbit_long(*dec, 63);
    int bit_96 = s21_getbit_long(*dec, 95);
    int bit_128 = s21_getbit_long(*dec, 127);
    int bit_160 = s21_getbit_long(*dec, 159);
    int bit_192 = s21_getbit_long(*dec, 192);
    dec->bits[0] <<= 1;
    dec->bits[1] <<= 1;
    dec->bits[2] <<= 1;
    dec->bits[3] <<= 1;
    dec->bits[4] <<= 1;
    dec->bits[5] <<= 1;
    s21_setbit_long(dec, 32, bit_32);
    s21_setbit_long(dec, 64, bit_64);
    s21_setbit_long(dec, 96, bit_96);
    s21_setbit_long(dec, 128, bit_128);
    s21_setbit_long(dec, 160, bit_160);
    if (bit_192) flag = 1;
  }
  return flag;
}

int get_bit_int(int num, int i) { return (num & 1 << i) != 0; }

void null_decimal(s21_decimal *dst) {
  for (int i = 0; i < 4; i++) dst->bits[i] = 0;
}
