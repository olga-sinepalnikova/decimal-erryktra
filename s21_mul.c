#include "s21_decimal.h"

int unsigned_add(s21_longdecimal value_1, s21_longdecimal value_2,
                 s21_longdecimal *result) {
  int ost = 0;
  for (int i = 0; i < 192; ++i) {
    int bit = s21_getbit_long(value_1, i) + s21_getbit_long(value_2, i) + ost;
    s21_setbit_long(result, i, get_bit_int(bit, 0));
    ost = get_bit_int(bit, 1);
  }
  return (ost > 0);
}

int check_zero_long(s21_longdecimal src) {
  int flag = 0;
  for (int i = 0; i < 6; i++) {
    if (src.bits[i] == 0) flag++;
  }
  return flag == 6 ? 1 : 0;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) return 1;
  s21_longdecimal temp2 = {0};
  s21_decimal temp = {0};

  s21_longdecimal long_val1;
  s21_from_decimal_to_longdecimal(value_1, &long_val1);

  s21_longdecimal long_val2;
  s21_from_decimal_to_longdecimal(value_2, &long_val2);

  int state = OK;
  for (int i = 0; i < 192; ++i) {
    if (s21_getbit_long(long_val2, i)) {
      s21_longdecimal value_1_copy = long_val1;
      s21_shiftleft_long(&value_1_copy, i);
      state = unsigned_add(temp2, value_1_copy, &temp2);
      if (state) break;
    }
  }
  set_long_scale(&temp2, s21_getscale(value_1) + s21_getscale(value_2));

  if (check_zero_long(temp2)) {
    state = 0;
    null_decimal(result);
  } else {
    state = s21_from_longdecimal_to_decimal(temp2, &temp);

    if (s21_getsign(value_1) != s21_getsign(value_2))
      s21_setsign(&temp, 1);
    else
      s21_setsign(&temp, 0);
    if (!s21_getsign(temp) && state)
      state = TOO_BIG;
    else if (s21_getsign(temp) && state)
      state = TOO_SMALL;
    if (!state) *result = temp;
  }
  return state;
}
