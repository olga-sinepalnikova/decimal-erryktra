#include <ctype.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[6];
  int data;
} s21_longdecimal;

// masks
#define MINUS 0x80000000
#define PLUS 0x00000000
#define MAX4BITS 0xffffffff

#define MIN_FLOAT 1e-28

// errors codes
#define OK 0

#define CONVERTION_ERR 1

#define TOO_BIG 1
#define TOO_SMALL 2

typedef union converter_float {
  float float_value;
  int32_t int_value;
} converter_float;

typedef union converter_double {
  double double_value;
  int64_t int64_value;
} converter_double;

typedef union converter {
  int num;
  char bytes[4];
} converter;

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// Comparison
int s21_is_equal(s21_decimal dec_1, s21_decimal dec_2);
int s21_is_less_or_equal(s21_decimal dec_1, s21_decimal dec_2);
int s21_is_less(s21_decimal dec_1, s21_decimal dec_2);
int s21_is_greater(s21_decimal dec_1, s21_decimal dec_2);
int s21_is_greater_or_equal(s21_decimal dec_1, s21_decimal dec_2);
int s21_is_not_equal(s21_decimal dec_1, s21_decimal dec_2);

// Arithmetics
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// Convertors
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_decimal_to_longdecimal(s21_decimal src, s21_longdecimal *dst);
int s21_from_longdecimal_to_decimal(s21_longdecimal src, s21_decimal *dst);

// Utils

int s21_from_decimal_to_longdouble(s21_decimal src, long double *dst);
void s21_decimal_clear(s21_decimal *dst);

// Vova's utils
int get_long_scale(s21_longdecimal dec);
int get_long_sign(s21_longdecimal dec);
void set_long_scale(s21_longdecimal *dec, int new_scale);
int check_long_overflow(s21_longdecimal dec);

// Sasha's utils
int s21_getbit(s21_decimal dec, int position);
int s21_setbit(s21_decimal *dec, int position, int value);
int s21_getscale(s21_decimal dec);
int s21_getsign(s21_decimal dec);
void s21_setsign(s21_decimal *dec, int sign);
void s21_mul_ten(s21_decimal *dec, s21_decimal *res);
void s21_scale_is_equal(s21_decimal *dec_1, s21_decimal *dec_2);
int s21_shiftleft(s21_decimal *dec, int shift);
void s21_setscale(s21_decimal *dec, int new_scale);
int s21_setbit_long(s21_longdecimal *dec, int position, int value);
int s21_is_greater_big_decimal(s21_longdecimal value_1,
                               s21_longdecimal value_2);
int s21_getbit_long(s21_longdecimal dec, int position);
void invertion(s21_longdecimal *val);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_shiftleft_long(s21_longdecimal *dec, int shift);
int get_bit_int(int num, int i);
void null_decimal(s21_decimal *dst);
void s21_sub_big_decimal(s21_longdecimal value_1, s21_longdecimal value_2,
                         s21_longdecimal *result);
int unsigned_add(s21_longdecimal value_1, s21_longdecimal value_2,
                 s21_longdecimal *result);
void div_ten(s21_longdecimal *dec);
int is_null_dec(s21_decimal dec);