#include "s21_decimal.h"

int s21_is_simple_equal(s21_decimal dec_1,
                        s21_decimal dec_2) {  // 1 - равны, 0 - не равны
  int result = 0;
  if (dec_1.bits[3] == dec_2.bits[3] && dec_1.bits[2] == dec_2.bits[2] &&
      dec_1.bits[1] == dec_2.bits[1] && dec_1.bits[0] == dec_2.bits[0])
    result = 1;
  return result;
}

int s21_is_equal(s21_decimal dec_1, s21_decimal dec_2) {
  int res = 0;
  if (s21_getscale(dec_1) != s21_getscale(dec_2))
    s21_scale_is_equal(&dec_1, &dec_2);
  if (s21_is_simple_equal(dec_1, dec_2)) res = 1;
  return res;
}

int s21_is_less_simple(s21_decimal dec_1, s21_decimal dec_2) {
  int result = 0;
  if (s21_is_simple_equal(dec_1, dec_2))
    result = 0;
  else if (dec_1.bits[2] > dec_2.bits[2])
    result = 0;
  else if (dec_1.bits[1] > dec_2.bits[1])
    result = 0;
  else if (dec_1.bits[0] > dec_2.bits[0])
    result = 0;
  for (int i = 2; i >= 0; i--) {
    if (dec_1.bits[i] < dec_2.bits[i]) {
      result = 1;
      break;
    }
    if (dec_1.bits[i] > dec_2.bits[i]) {
      result = 0;
      break;
    }
  }
  return result;
}

int s21_is_less(s21_decimal dec_1, s21_decimal dec_2) {
  int res = 0;
  if (s21_getsign(dec_1) && !s21_getsign(dec_2))
    res = 1;  //первое число отрицательное
  else {
    if (s21_getscale(dec_1) != s21_getscale(dec_2))
      s21_scale_is_equal(&dec_1, &dec_2);
    if (!s21_getsign(dec_1) && !s21_getsign(dec_2) &&
        s21_is_less_simple(dec_1, dec_2))
      res = 1;
    else if (s21_getsign(dec_1) && s21_getsign(dec_2) &&
             !s21_is_less_simple(dec_1, dec_2))
      res = 1;
    if (s21_getscale(dec_1) != s21_getscale(dec_2))
      s21_scale_is_equal(&dec_1, &dec_2);

    if (!s21_getsign(dec_1) && !s21_getsign(dec_2) &&
        s21_is_less_simple(dec_1, dec_2))
      res = 1;
    else if (s21_getsign(dec_1) && s21_getsign(dec_2) &&
             !s21_is_less_simple(dec_1, dec_2))
      res = 1;
  }
  return res;
}

int s21_is_greater(s21_decimal dec_1, s21_decimal dec_2) {
  return ((!s21_is_less(dec_1, dec_2) && (!s21_is_equal(dec_1, dec_2))) ? 1
                                                                        : 0);
}

int s21_is_less_or_equal(s21_decimal dec_1, s21_decimal dec_2) {
  return (s21_is_equal(dec_1, dec_2) || s21_is_less(dec_1, dec_2) ? 1 : 0);
}

int s21_is_greater_or_equal(s21_decimal dec_1, s21_decimal dec_2) {
  return (s21_is_equal(dec_1, dec_2) || s21_is_greater(dec_1, dec_2) ? 1 : 0);
}

int s21_is_not_equal(s21_decimal dec_1, s21_decimal dec_2) {
  return (!s21_is_equal(dec_1, dec_2) ? 1 : 0);
}