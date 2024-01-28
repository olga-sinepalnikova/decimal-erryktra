#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!value_2.bits[0] && !value_2.bits[1] && !value_2.bits[2]) return 3;
  s21_decimal one = {1, 0, 0, 0};
  s21_decimal rez = {0};
  s21_decimal v1 = value_1;
  s21_decimal v2 = value_2;
  s21_setsign(&v1, 0);
  s21_setsign(&v2, 0);
  s21_decimal temp = v1;
  s21_scale_is_equal(&v1, &v2);
  int status = 0;

  while (!status) {
    int r = s21_is_greater_or_equal(temp, v2);
    if (r) {
      s21_sub(temp, v2, &temp);
      s21_add(rez, one, &rez);
    } else {
      s21_setscale(&one, 1);
      s21_decimal rz = {0};
      s21_decimal ost = {0};
      s21_mul(v2, one, &rz);
      int ost2 = 0;
      while (!status) {
        if (s21_is_greater_or_equal(temp, rz)) {
          s21_sub(temp, rz, &temp);
          ost2++;
        } else {
          s21_from_int_to_decimal(ost2, &ost);
          s21_setscale(&ost, 1);
          s21_add(ost, rez, &rez);
          status = 1;
        }
      }
    }
  }
  if (s21_getsign(value_1) != s21_getsign(value_2)) s21_setsign(&rez, 1);

  *result = rez;

  return 0;
}