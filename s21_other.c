#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int stat = 0;
  s21_decimal buffer = value;
  if (result) {
    if (s21_getsign(value))
      s21_setsign(&buffer, 0);
    else
      s21_setsign(&buffer, 1);
  } else
    stat = 1;
  *result = buffer;
  return stat;
}

void s21_decimal_clear(s21_decimal *dst) {  //обнуление децимал числа
  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  s21_decimal_clear(result);
  int errorNumb = OK;
  double ost = 0.0;
  long double doubleNumb = 0.0;
  if (s21_getscale(value)) {
    s21_from_decimal_to_longdouble(value, &doubleNumb);
    doubleNumb = floor(doubleNumb);
    if (doubleNumb < 0) {
      s21_setbit(result, 127, 1);
      doubleNumb *= (-1);
    }
    for (int g = 0; g < 96; g++) {
      if (doubleNumb >= 1) {
        doubleNumb = trunc(doubleNumb) / 2;
        ost = doubleNumb - trunc(doubleNumb);
        if (ost > 0.0) {
          s21_setbit(result, g, 1);
        } else {
          s21_setbit(result, g, 0);
        }
      }
    }
  } else {
    for (int j = 0; j < 4; j++) {
      result->bits[j] = value.bits[j];
    }
  }
  return errorNumb;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_decimal_clear(result);
  int errorNumb = OK;
  double ost = 0.0;
  long double doubleNumb = 0.0;
  if (s21_getscale(value)) {
    s21_from_decimal_to_longdouble(value, &doubleNumb);
    doubleNumb = round(doubleNumb);
    if (doubleNumb < 0) {
      s21_setbit(result, 127, 1);
      doubleNumb *= (-1);
    }
    for (int g = 0; g < 96; g++) {
      if (doubleNumb >= 1) {
        doubleNumb = trunc(doubleNumb) / 2;
        ost = doubleNumb - trunc(doubleNumb);
        if (ost > 0.0) {
          s21_setbit(result, g, 1);
        } else {
          s21_setbit(result, g, 0);
        }
      }
    }
  } else {
    for (int j = 0; j < 4; j++) {
      result->bits[j] = value.bits[j];
    }
  }
  return errorNumb;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_decimal_clear(result);
  int errorNumb = OK;
  double ost = 0.0;
  long double doubleNumb = 0.0;
  if (s21_getscale(value)) {
    s21_from_decimal_to_longdouble(value, &doubleNumb);
    doubleNumb = trunc(doubleNumb);
    if (doubleNumb < 0) {
      s21_setbit(result, 127, 1);
      doubleNumb *= (-1);
    }
    for (int g = 0; g < 96; g++) {
      if (doubleNumb >= 1) {
        doubleNumb = trunc(doubleNumb) / 2;
        ost = doubleNumb - trunc(doubleNumb);
        if (ost > 0.0) {
          s21_setbit(result, g, 1);
        } else {
          s21_setbit(result, g, 0);
        }
      }
    }
  } else {
    for (int j = 0; j < 4; j++) {
      result->bits[j] = value.bits[j];
    }
  }
  return errorNumb;
}
