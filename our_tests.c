#include <check.h>

#include "s21_decimal.h"

START_TEST(is_less_1) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_less_2) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = -28756;
  int j = 28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_less(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_less_3) {
  s21_decimal test_1 = {{1, 0, 0, 65536}};
  s21_decimal test_2 = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_less_4) {
  s21_decimal test_1 = {{1, 0, 0, 0}};
  s21_decimal test_2 = {{1, 0, 0, 65536}};
  ck_assert_int_eq(s21_is_less(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_less_5) {
  s21_decimal test_1 = {{0, 1, 0, 0}};
  s21_decimal test_2 = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_less_6) {
  s21_decimal test_1 = {{1, 0, 0, 0}};
  s21_decimal test_2 = {{0, 1, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_less_7) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = 3456789;
  int j = 28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_less(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_less_8) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = 28756;
  int j = 34567890;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_less(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_less_9) {
  s21_decimal test_1 = {{0, 1, 0, 0}};
  s21_decimal test_2 = {{1, 0, 0, 65536}};
  ck_assert_int_eq(s21_is_less(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_less_10) {
  s21_decimal test_1 = {{1, 1, 1, 0}};
  s21_decimal test_2 = {{1, 1, 1, 65536}};
  ck_assert_int_eq(s21_is_less(test_1, test_2), 0);
}
END_TEST;

///

START_TEST(s21_is_less_simple_1) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_1, test_2), 0);
}
END_TEST;

START_TEST(s21_is_less_simple_2) {
  s21_decimal test_1 = {{1, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less(test_1, test_2), 0);
}
END_TEST;

START_TEST(s21_is_less_simple_3) {
  s21_decimal test_1 = {{1, 0, 0, 0}};
  s21_decimal test_2 = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_1, test_2), 0);
}
END_TEST;

START_TEST(s21_is_less_simple_4) {
  s21_decimal test_1 = {{1, 1, 0, 0}};
  s21_decimal test_2 = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_1, test_2), 0);
}
END_TEST;

START_TEST(s21_is_less_simple_5) {
  s21_decimal test_1 = {{0, 1, 0, 0}};
  s21_decimal test_2 = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_1, test_2), 0);
}
END_TEST;

START_TEST(s21_is_less_simple_6) {
  s21_decimal test_1 = {{1, 0, 0, 0}};
  s21_decimal test_2 = {{0, 1, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_1, test_2), 1);
}
END_TEST;

START_TEST(s21_is_less_simple_7) {
  s21_decimal test_1 = {{1, 0, 1, 0}};
  s21_decimal test_2 = {{0, 1, 0, 0}};

  ck_assert_int_eq(s21_is_less(test_1, test_2), 0);
}
END_TEST;

START_TEST(s21_is_less_simple_8) {
  s21_decimal test_1 = {{0, 1, 0, 0}};
  s21_decimal test_2 = {{1, 0, 1, 0}};

  ck_assert_int_eq(s21_is_less(test_1, test_2), 1);
}
END_TEST;

START_TEST(s21_is_less_simple_9) {
  s21_decimal test_1 = {{1, 1, 1, 0}};
  s21_decimal test_2 = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_1, test_2), 0);
}
END_TEST;

START_TEST(s21_is_less_simple_10) {
  s21_decimal test_1 = {{1, 0, 0, 0}};
  s21_decimal test_2 = {{1, 1, 1, 0}};
  ck_assert_int_eq(s21_is_less(test_1, test_2), 1);
}
END_TEST;

// is_greater //

START_TEST(is_greater_1) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_greater_2) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = -28756;
  int j = 28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_greater(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_greater_3) {
  s21_decimal test_1 = {{1, 0, 0, 65536}};
  s21_decimal test_2 = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_greater_4) {
  s21_decimal test_1 = {{1, 0, 0, 0}};
  s21_decimal test_2 = {{1, 0, 0, 65536}};
  ck_assert_int_eq(s21_is_greater(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_greater_5) {
  s21_decimal test_1 = {{0, 1, 0, 0}};
  s21_decimal test_2 = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_greater_6) {
  s21_decimal test_1 = {{1, 0, 0, 0}};
  s21_decimal test_2 = {{0, 1, 0, 0}};
  ck_assert_int_eq(s21_is_greater(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_greater_7) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = 3456789;
  int j = 28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_greater(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_greater_8) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = 28756;
  int j = 34567890;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_greater(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_greater_9) {
  s21_decimal test_1 = {{0, 1, 0, 0}};
  s21_decimal test_2 = {{1, 0, 0, 65536}};
  ck_assert_int_eq(s21_is_greater(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_greater_10) {
  s21_decimal test_1 = {{1, 1, 1, 0}};
  s21_decimal test_2 = {{1, 1, 1, 65536}};
  ck_assert_int_eq(s21_is_greater(test_1, test_2), 1);
}
END_TEST;

// is_less_or_equal //

START_TEST(is_less_or_equal_1) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_less_or_equal_2) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = -28756;
  int j = 28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_less_or_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_less_or_equal_3) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = -28756;
  int j = -28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_less_or_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_less_or_equal_4) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = 28756;
  int j = -28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_less_or_equal(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_less_or_equal_5) {
  s21_decimal test_1 = {{0, 1, 0, 0}};
  s21_decimal test_2 = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_less_or_equal_6) {
  s21_decimal test_1 = {{1, 0, 0, 0}};
  s21_decimal test_2 = {{0, 1, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_less_or_equal_7) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = 3456789;
  int j = 28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_less_or_equal(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_less_or_equal_8) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = 28756;
  int j = 34567890;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_less_or_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_less_or_equal_9) {
  s21_decimal test_1 = {{0, 1, 0, 0}};
  s21_decimal test_2 = {{1, 0, 0, 65536}};
  ck_assert_int_eq(s21_is_less_or_equal(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_less_or_equal_10) {
  s21_decimal test_1 = {{1, 1, 1, 65536}};
  s21_decimal test_2 = {{1, 1, 1, 65536}};
  ck_assert_int_eq(s21_is_less_or_equal(test_1, test_2), 1);
}
END_TEST;

// is_greater_or_equal //

START_TEST(is_greater_or_equal_1) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_greater_or_equal_2) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = -28756;
  int j = 28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_greater_or_equal_3) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = -28756;
  int j = -28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_greater_or_equal_4) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = 28756;
  int j = -28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_greater_or_equal_5) {
  s21_decimal test_1 = {{0, 1, 0, 0}};
  s21_decimal test_2 = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_greater_or_equal_6) {
  s21_decimal test_1 = {{1, 0, 0, 0}};
  s21_decimal test_2 = {{0, 1, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_greater_or_equal_7) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = 3456789;
  int j = 28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_greater_or_equal_8) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = 28756;
  int j = 34567890;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_greater_or_equal_9) {
  s21_decimal test_1 = {{0, 1, 0, 0}};
  s21_decimal test_2 = {{1, 0, 0, 65536}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_greater_or_equal_10) {
  s21_decimal test_1 = {{1, 1, 1, 65536}};
  s21_decimal test_2 = {{1, 1, 1, 65536}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_1, test_2), 1);
}
END_TEST;

// equal //

START_TEST(is_equal_1) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_equal_2) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = -28756;
  int j = 28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_equal(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_equal_3) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = -28756;
  int j = -28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_equal_4) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = 28756;
  int j = -28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_equal(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_equal_5) {
  s21_decimal test_1 = {{1, 1, 1, 0}};
  s21_decimal test_2 = {{1, 1, 1, 65536}};
  ck_assert_int_eq(s21_is_equal(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_equal_6) {
  s21_decimal test_1 = {{1, 0, 0, 0}};
  s21_decimal test_2 = {{0, 1, 0, 0}};
  ck_assert_int_eq(s21_is_equal(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_equal_7) {
  s21_decimal test_1 = {{0, 1, 0, 0}};
  s21_decimal test_2 = {{1, 0, 0, 65536}};
  ck_assert_int_eq(s21_is_equal(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_equal_8) {
  s21_decimal test_1 = {{1, 1, 1, 65536}};
  s21_decimal test_2 = {{1, 1, 1, 65536}};
  ck_assert_int_eq(s21_is_equal(test_1, test_2), 1);
}
END_TEST;

// not_equal //

START_TEST(is_not_equal_1) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_not_equal_2) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = -28756;
  int j = 28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_not_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_not_equal_3) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = -28756;
  int j = -28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_not_equal(test_1, test_2), 0);
}
END_TEST;

START_TEST(is_not_equal_4) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal test_2 = {{0, 0, 0, 0}};
  int i = 28756;
  int j = -28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_from_int_to_decimal(j, &test_2);
  ck_assert_int_eq(s21_is_not_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_not_equal_5) {
  s21_decimal test_1 = {{1, 1, 1, 0}};
  s21_decimal test_2 = {{1, 1, 1, 65536}};
  ck_assert_int_eq(s21_is_not_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_not_equal_6) {
  s21_decimal test_1 = {{1, 0, 0, 0}};
  s21_decimal test_2 = {{0, 1, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_not_equal_7) {
  s21_decimal test_1 = {{0, 1, 0, 0}};
  s21_decimal test_2 = {{1, 0, 0, 65536}};
  ck_assert_int_eq(s21_is_not_equal(test_1, test_2), 1);
}
END_TEST;

START_TEST(is_not_equal_8) {
  s21_decimal test_1 = {{1, 1, 1, 65536}};
  s21_decimal test_2 = {{1, 1, 1, 65536}};
  ck_assert_int_eq(s21_is_not_equal(test_1, test_2), 0);
}
END_TEST;

// negate

START_TEST(negate_1) {
  s21_decimal test_1 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int i = -28756;
  s21_from_int_to_decimal(i, &test_1);
  s21_negate(test_1, &result);
  ck_assert_int_eq(s21_getbit(result, 127), 0);
}
END_TEST

START_TEST(negate_2) {
  s21_decimal test_2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int i = 28756;
  s21_from_int_to_decimal(i, &test_2);
  s21_negate(test_2, &result);
  ck_assert_int_eq(s21_getbit(result, 127), 1);
}
END_TEST

START_TEST(test_s21_itd_1) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  int test_int = 0x00fffff2;
  s21_from_int_to_decimal(test_int, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], 0x00fffff2);
}
END_TEST

START_TEST(test_s21_itd_2) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  int test_int = 100000;
  s21_from_int_to_decimal(test_int, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], 100000);
}
END_TEST

START_TEST(test_s21_itd_3) {
  s21_decimal dec;
  int test_int = 100000;
  int code = s21_from_int_to_decimal(test_int, &dec);
  ck_assert_int_eq(code, OK);
}
END_TEST

START_TEST(test_s21_itd_4) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  int test_int = 0b010101011101010101;
  s21_from_int_to_decimal(test_int, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], 87893);
}
END_TEST

START_TEST(test_s21_ftd_1) {
  s21_decimal test_dec = {0};
  float test_float = 0.659267;
  s21_from_float_to_decimal(test_float, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], 659267);
  ck_assert_int_eq(test_dec.bits[1], 0);
  ck_assert_int_eq(test_dec.bits[2], 0);
  ck_assert_int_eq(test_dec.bits[3], 393216);
}
END_TEST

START_TEST(test_s21_ftd_2) {
  s21_decimal test_dec = {0};
  float test_float = -212121.4345;
  s21_from_float_to_decimal(test_float, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], 212121);
  ck_assert_int_eq(test_dec.bits[1], 0);
  ck_assert_int_eq(test_dec.bits[2], 0);
  ck_assert_int_eq((unsigned int)test_dec.bits[3], 2147483648);
}
END_TEST

START_TEST(test_s21_ftd_3) {
  s21_decimal test_dec = {0};
  float test_float = -212121434543454345434543443454345.4345;
  int err_code = s21_from_float_to_decimal(test_float, &test_dec);
  ck_assert_int_eq(err_code, 1);
}
END_TEST

START_TEST(test_s21_ftd_4) {
  s21_decimal test_dec = {0};
  float test_float = 212121434543454345434543443454345.4345;
  int err_code = s21_from_float_to_decimal(test_float, &test_dec);
  ck_assert_int_eq(err_code, 1);
}
END_TEST

START_TEST(test_s21_ftd_5) {
  s21_decimal test_dec = {0};
  float test_float = -21.00004345;
  s21_from_float_to_decimal(test_float, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], 2100004);
  ck_assert_int_eq(test_dec.bits[1], 0);
  ck_assert_int_eq(test_dec.bits[2], 0);
  ck_assert_int_eq((unsigned int)test_dec.bits[3], 2147811328);
}
END_TEST

START_TEST(test_s21_ftd_6) {
  s21_decimal test_dec = {0};
  float test_float = 0;
  s21_from_float_to_decimal(test_float, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], 0);
  ck_assert_int_eq(test_dec.bits[1], 0);
  ck_assert_int_eq(test_dec.bits[2], 0);
  ck_assert_int_eq(test_dec.bits[3], 0);
}
END_TEST

START_TEST(test_s21_add_1) {
  s21_decimal value_1 = {{1, 0, 0, 0x00000000}};
  s21_decimal value_2 = {{3, 0, 0, 0x00020000}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_add(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], 103);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0x00020000);
}
END_TEST

START_TEST(test_s21_add_2) {
  s21_decimal value_1 = {{23, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(result.bits[0], 26);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq((uint32_t)result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_add_3) {
  s21_decimal value_1 = {{0xffffffff, 0xffffffff, 0xfffffff2, 0}};
  s21_decimal value_2 = {{0xffffffff, 0xffffffff, 0xffffffff, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error_code, TOO_BIG);
}
END_TEST

START_TEST(test_s21_add_4) {
  s21_decimal value_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal value_2 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(error_code, 2);
}
END_TEST

START_TEST(test_s21_add_5) {
  s21_decimal value_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal value_2 = {{0xffffffff, 0xffffffff, 0xffffffff, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_add(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
}
END_TEST

START_TEST(test_s21_add_6) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 21674563, 43435, 0x80120000}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_add(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 21674563);
  ck_assert_int_eq(result.bits[2], 43435);
  ck_assert_int_eq(result.bits[3], 2148663296);
}
END_TEST

START_TEST(test_s21_sub_1) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_sub_2) {
  s21_decimal value_1 = {{0, 3456, 0, 0x80040000}};
  s21_decimal value_2 = {{4783, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], 47830000);
  ck_assert_int_eq(result.bits[1], 3456);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq((unsigned int)result.bits[3], 0x80040000);
}
END_TEST

START_TEST(test_s21_sub_3) {
  s21_decimal value_1 = {{23456575, 3456, 0, 0}};
  s21_decimal value_2 = {{4783, 0, 0, 0x800f0000}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], 1146720943);
  ck_assert_int_eq(result.bits[1], 220126269);
  ck_assert_int_eq(result.bits[2], 804663976);
  ck_assert_int_eq(result.bits[3], 983040);
}
END_TEST

START_TEST(test_s21_sub_4) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{4783, 0, 432423423, 0x80000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], 4783);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 432423423);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_sub_5) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{4783, 0, 432423423, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], 4783);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 432423423);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(test_s21_sub_6) {
  s21_decimal value_1 = {{4783, 0, 432423423, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], 4783);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 432423423);
  ck_assert_int_eq((unsigned int)result.bits[3], 0);
}
END_TEST

START_TEST(part1_mult_value_1_is_one) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result;
  s21_decimal test = {0};
  value_1.bits[0] = 1;
  value_2.bits[0] = 10;
  test.bits[0] = 10;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  s21_setsign(&value_1, 1);
  memset(&result, 0, sizeof(s21_decimal));
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_getsign(result), 1);
}
END_TEST

START_TEST(part1_mult_value_2_is_one) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result;
  s21_decimal test = {0};
  value_1.bits[0] = 15;
  value_2.bits[0] = 1;
  test.bits[0] = 15;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(part1_mult_value_1_is_zero) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result;
  s21_decimal test = {0};
  value_1.bits[0] = 0;
  value_2.bits[0] = 100;
  test.bits[0] = 0;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(part1_mult_value_2_is_zero) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result;
  s21_decimal test = {0};
  value_1.bits[0] = 7;
  value_2.bits[0] = 0;
  test.bits[0] = 0;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(part1_mult_max) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result;
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 5;
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(res, 1);

  s21_setsign(&value_2, 1);
  res = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(res, 2);
}
END_TEST

START_TEST(part1_mult_big_power) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result;
  s21_decimal test = {0};
  value_1.bits[0] = 2147483647;
  value_2.bits[0] = 255;
  test.bits[0] = 2147483393;
  test.bits[1] = 127;
  s21_setscale(&value_2, 10);
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(res, 0);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(result.bits[1], test.bits[1]);
  ck_assert_uint_eq(s21_getscale(result), 10);
  ck_assert_uint_eq(s21_getsign(result), 0);
}
END_TEST

START_TEST(part1_mult_value_1_is_minus) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result;
  s21_decimal test = {0};
  s21_setsign(&value_1, 1);
  value_1.bits[0] = 15;
  value_2.bits[0] = 1;
  test.bits[0] = 15;
  s21_setsign(&value_1, 1);
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_getsign(result), 1);
}
END_TEST

START_TEST(part1_mult_value_2_is_minus) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result;
  s21_decimal test = {0};
  value_1.bits[0] = 15;
  s21_setsign(&value_2, 1);
  value_2.bits[0] = 1;
  test.bits[0] = 15;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_getsign(result), 1);
}
END_TEST

START_TEST(part1_mult_value_1_is_zero_minus) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result;
  s21_decimal test = {0};
  s21_setsign(&value_1, 1);
  value_1.bits[0] = 0;
  value_2.bits[0] = 100;
  test.bits[0] = 0;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_getsign(result), 0);
}
END_TEST

START_TEST(part1_mult_value_2_is_zero_minus) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result;
  s21_decimal test = {0};
  value_1.bits[0] = 7;
  s21_setsign(&value_2, 1);
  value_2.bits[0] = 0;
  test.bits[0] = 0;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_getsign(result), 0);
}
END_TEST

START_TEST(part1_mult_value_1_2_is_minus) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result;
  s21_decimal test = {0};
  s21_setsign(&value_1, 1);
  s21_setsign(&value_2, 1);
  value_1.bits[0] = 0;
  value_2.bits[0] = 100;
  test.bits[0] = 0;
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_uint_eq(s21_getscale(result), 0);
  s21_setscale(&value_1, 5);
  s21_setscale(&value_2, 29);
  s21_mul(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
}
END_TEST

START_TEST(test_s21_div_1) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};

  s21_decimal as_result = {{5, 0, 0, 0}};
  int rez = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(rez, 0);
  ck_assert(result.bits[0] == as_result.bits[0] &&
            result.bits[1] == as_result.bits[1] &&
            result.bits[2] == as_result.bits[2] &&
            result.bits[3] == as_result.bits[3]);
}
END_TEST

START_TEST(test_s21_div_2) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 2147483648}};
  s21_decimal result;

  s21_decimal as_result = {{5, 0, 0, 2147483648}};
  int rez = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(rez, 0);
  ck_assert(result.bits[0] == as_result.bits[0] &&
            result.bits[1] == as_result.bits[1] &&
            result.bits[2] == as_result.bits[2] &&
            result.bits[3] == as_result.bits[3]);
}
END_TEST
START_TEST(test_s21_div_3) {
  s21_decimal value_1 = {{102, 0, 0, 65536}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal result;

  s21_decimal as_result = {{51, 0, 0, 65536}};
  int rez = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(rez, 0);
  ck_assert(result.bits[0] == as_result.bits[0] &&
            result.bits[1] == as_result.bits[1] &&
            result.bits[2] == as_result.bits[2] &&
            result.bits[3] == as_result.bits[3]);
}
END_TEST
START_TEST(test_s21_div_4) {
  s21_decimal value_1 = {{102, 0, 0, -2147418112}};
  s21_decimal value_2 = {{2, 0, 0, 0}};

  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal as_result = {{51, 0, 0, -2147418112}};
  int rez = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(rez, 0);
  //    ck_as
  ck_assert(result.bits[0] == as_result.bits[0] &&
            result.bits[1] == as_result.bits[1] &&
            result.bits[2] == as_result.bits[2] &&
            result.bits[3] == as_result.bits[3]);
}
END_TEST

START_TEST(test_s21_floor_1) {
  s21_decimal v_1 = {{673988, 0, 0, 262144}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_floor(v_1, &result);
  ck_assert_float_eq(result.bits[0], 67);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_floor_2) {
  s21_decimal v_1 = {{679988, 0, 0, 262144}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_floor(v_1, &result);
  ck_assert_float_eq(result.bits[0], 67);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_floor_3) {
  s21_decimal v_1 = {{679988, 0, 0, 2147745796}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_floor(v_1, &result);
  ck_assert_float_eq(result.bits[0], 68);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(test_s21_floor_4) {
  s21_decimal v_1 = {{2555, 0, 0, 0}};
  s21_setscale(&v_1, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_floor(v_1, &result);
  ck_assert_float_eq(result.bits[0], 25);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_round_1) {
  s21_decimal v_1 = {{5, 0, 1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(v_1, &result);
  ck_assert_float_eq(result.bits[0], 5);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 1);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_round_2) {
  s21_decimal v_1 = {{155, 1, 1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(v_1, &result);
  ck_assert_float_eq(result.bits[0], 155);
  ck_assert_float_eq(result.bits[1], 1);
  ck_assert_float_eq(result.bits[2], 1);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_round_3) {
  s21_decimal v_1 = {{155, 1, 1, 2147483648}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(v_1, &result);
  ck_assert_float_eq(result.bits[0], 155);
  ck_assert_float_eq(result.bits[1], 1);
  ck_assert_float_eq(result.bits[2], 1);
  ck_assert_float_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(test_s21_round_4) {
  s21_decimal v_1 = {{0, 1, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(v_1, &result);
  ck_assert_float_eq(result.bits[0], 0);
  ck_assert_float_eq(result.bits[1], 1);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_round_5) {
  s21_decimal v_1 = {{2555, 0, 0, 0}};
  s21_setscale(&v_1, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(v_1, &result);
  ck_assert_float_eq(result.bits[0], 26);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_truncate_1) {
  s21_decimal v_1 = {{673988, 0, 0, 262144}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(v_1, &result);
  ck_assert_float_eq(result.bits[0], 67);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_truncate_2) {
  s21_decimal v_1 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(-2744406, &v_1);
  s21_truncate(v_1, &result);
  ck_assert_float_eq(result.bits[0], 2744406);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(test_s21_decimal_to_int_1) {
  int number = 0;
  s21_decimal src = {{2147483647, 0, 0, 0}};
  s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 2147483647);
}
END_TEST

START_TEST(test_s21_decimal_to_int_2) {
  int number = 0;
  s21_decimal src = {{0, 0, 0, 0}};
  s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 0);
}
END_TEST

START_TEST(test_s21_decimal_to_int_3) {
  int number = 0;
  s21_decimal src = {{5000, 0, 0, 2147483648}};
  s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -5000);
}
END_TEST

START_TEST(test_s21_decimal_to_int_4) {
  int number = 0;
  s21_decimal src = {{2147483648, 0, 0, 2147483648}};
  s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(s21_from_decimal_to_int(src, &number), 1);
}
END_TEST

START_TEST(test_s21_decimal_to_float_1) {
  float number = 0.0;
  s21_decimal src = {{18122, 0, 0, 2147680256}};
  s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -18.122);
}
END_TEST

START_TEST(test_s21_decimal_to_float_2) {
  float number = 0.0;
  s21_decimal src = {{1812, 0, 0, 2147483648}};
  s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -1812);
}
END_TEST

START_TEST(test_s21_decimal_to_float_3) {
  float number = 0.0;
  s21_decimal src = {{4294967295, 4294967295, 0, 0}};
  s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, 0xFFFFFFFFFFFFFFFF);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("s21_decimal: ");
  TCase *tc1_1 = tcase_create("s21_decimal: ");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, is_less_1);
  tcase_add_test(tc1_1, is_less_2);
  tcase_add_test(tc1_1, is_less_3);
  tcase_add_test(tc1_1, is_less_4);
  tcase_add_test(tc1_1, is_less_5);
  tcase_add_test(tc1_1, is_less_6);
  tcase_add_test(tc1_1, is_less_7);
  tcase_add_test(tc1_1, is_less_8);
  tcase_add_test(tc1_1, is_less_9);
  tcase_add_test(tc1_1, is_less_10);

  // tests_is_less_simple

  tcase_add_test(tc1_1, s21_is_less_simple_1);
  tcase_add_test(tc1_1, s21_is_less_simple_2);
  tcase_add_test(tc1_1, s21_is_less_simple_3);
  tcase_add_test(tc1_1, s21_is_less_simple_4);
  tcase_add_test(tc1_1, s21_is_less_simple_5);
  tcase_add_test(tc1_1, s21_is_less_simple_6);
  tcase_add_test(tc1_1, s21_is_less_simple_7);
  tcase_add_test(tc1_1, s21_is_less_simple_8);
  tcase_add_test(tc1_1, s21_is_less_simple_9);
  tcase_add_test(tc1_1, s21_is_less_simple_10);

  // tests_is_greater
  tcase_add_test(tc1_1, is_greater_1);
  tcase_add_test(tc1_1, is_greater_2);
  tcase_add_test(tc1_1, is_greater_3);
  tcase_add_test(tc1_1, is_greater_4);
  tcase_add_test(tc1_1, is_greater_5);
  tcase_add_test(tc1_1, is_greater_6);
  tcase_add_test(tc1_1, is_greater_7);
  tcase_add_test(tc1_1, is_greater_8);
  tcase_add_test(tc1_1, is_greater_9);
  tcase_add_test(tc1_1, is_greater_10);

  // tests_is_less_or_equal
  tcase_add_test(tc1_1, is_less_or_equal_1);
  tcase_add_test(tc1_1, is_less_or_equal_2);
  tcase_add_test(tc1_1, is_less_or_equal_3);
  tcase_add_test(tc1_1, is_less_or_equal_4);
  tcase_add_test(tc1_1, is_less_or_equal_5);
  tcase_add_test(tc1_1, is_less_or_equal_6);
  tcase_add_test(tc1_1, is_less_or_equal_7);
  tcase_add_test(tc1_1, is_less_or_equal_8);
  tcase_add_test(tc1_1, is_less_or_equal_9);
  tcase_add_test(tc1_1, is_less_or_equal_10);

  // tests_is_greater_or_equal
  tcase_add_test(tc1_1, is_greater_or_equal_1);
  tcase_add_test(tc1_1, is_greater_or_equal_2);
  tcase_add_test(tc1_1, is_greater_or_equal_3);
  tcase_add_test(tc1_1, is_greater_or_equal_4);
  tcase_add_test(tc1_1, is_greater_or_equal_5);
  tcase_add_test(tc1_1, is_greater_or_equal_6);
  tcase_add_test(tc1_1, is_greater_or_equal_7);
  tcase_add_test(tc1_1, is_greater_or_equal_8);
  tcase_add_test(tc1_1, is_greater_or_equal_9);
  tcase_add_test(tc1_1, is_greater_or_equal_10);

  // tests_is_equal
  tcase_add_test(tc1_1, is_equal_1);
  tcase_add_test(tc1_1, is_equal_2);
  tcase_add_test(tc1_1, is_equal_3);
  tcase_add_test(tc1_1, is_equal_4);
  tcase_add_test(tc1_1, is_equal_5);
  tcase_add_test(tc1_1, is_equal_6);
  tcase_add_test(tc1_1, is_equal_7);
  tcase_add_test(tc1_1, is_equal_8);

  // tests_is_not_equal
  tcase_add_test(tc1_1, is_not_equal_1);
  tcase_add_test(tc1_1, is_not_equal_2);
  tcase_add_test(tc1_1, is_not_equal_3);
  tcase_add_test(tc1_1, is_not_equal_4);
  tcase_add_test(tc1_1, is_not_equal_5);
  tcase_add_test(tc1_1, is_not_equal_6);
  tcase_add_test(tc1_1, is_not_equal_7);
  tcase_add_test(tc1_1, is_not_equal_8);

  //   // tests_negate
  tcase_add_test(tc1_1, negate_1);
  tcase_add_test(tc1_1, negate_2);

  tcase_add_test(tc1_1, is_less_or_equal_1);
  tcase_add_test(tc1_1, is_less_or_equal_2);
  tcase_add_test(tc1_1, is_less_or_equal_3);
  tcase_add_test(tc1_1, is_less_or_equal_4);
  tcase_add_test(tc1_1, is_less_or_equal_5);
  tcase_add_test(tc1_1, is_less_or_equal_6);
  tcase_add_test(tc1_1, is_less_or_equal_7);
  tcase_add_test(tc1_1, is_less_or_equal_8);
  tcase_add_test(tc1_1, is_less_or_equal_9);
  tcase_add_test(tc1_1, is_less_or_equal_10);

  tcase_add_test(tc1_1, test_s21_itd_1);
  tcase_add_test(tc1_1, test_s21_itd_2);
  tcase_add_test(tc1_1, test_s21_itd_3);
  tcase_add_test(tc1_1, test_s21_itd_4);

  tcase_add_test(tc1_1, test_s21_ftd_1);
  tcase_add_test(tc1_1, test_s21_ftd_2);
  tcase_add_test(tc1_1, test_s21_ftd_3);
  tcase_add_test(tc1_1, test_s21_ftd_4);
  tcase_add_test(tc1_1, test_s21_ftd_5);
  tcase_add_test(tc1_1, test_s21_ftd_6);

  tcase_add_test(tc1_1, test_s21_add_1);
  tcase_add_test(tc1_1, test_s21_add_2);
  tcase_add_test(tc1_1, test_s21_add_3);
  tcase_add_test(tc1_1, test_s21_add_4);
  tcase_add_test(tc1_1, test_s21_add_5);
  tcase_add_test(tc1_1, test_s21_add_6);

  tcase_add_test(tc1_1, test_s21_sub_1);
  tcase_add_test(tc1_1, test_s21_sub_2);
  tcase_add_test(tc1_1, test_s21_sub_3);
  tcase_add_test(tc1_1, test_s21_sub_4);
  tcase_add_test(tc1_1, test_s21_sub_5);
  tcase_add_test(tc1_1, test_s21_sub_6);

  tcase_add_test(tc1_1, part1_mult_value_1_is_one);
  tcase_add_test(tc1_1, part1_mult_value_2_is_one);
  tcase_add_test(tc1_1, part1_mult_value_1_is_zero);
  tcase_add_test(tc1_1, part1_mult_value_2_is_zero);
  tcase_add_test(tc1_1, part1_mult_max);
  tcase_add_test(tc1_1, part1_mult_big_power);
  tcase_add_test(tc1_1, part1_mult_value_1_is_minus);
  tcase_add_test(tc1_1, part1_mult_value_2_is_minus);
  tcase_add_test(tc1_1, part1_mult_value_1_is_zero_minus);
  tcase_add_test(tc1_1, part1_mult_value_2_is_zero_minus);
  tcase_add_test(tc1_1, part1_mult_value_1_2_is_minus);

  tcase_add_test(tc1_1, test_s21_div_1);
  tcase_add_test(tc1_1, test_s21_div_2);
  tcase_add_test(tc1_1, test_s21_div_3);
  tcase_add_test(tc1_1, test_s21_div_4);

  tcase_add_test(tc1_1, test_s21_floor_1);
  tcase_add_test(tc1_1, test_s21_floor_2);
  tcase_add_test(tc1_1, test_s21_floor_3);
  tcase_add_test(tc1_1, test_s21_floor_4);

  // tests_round
  tcase_add_test(tc1_1, test_s21_round_1);
  tcase_add_test(tc1_1, test_s21_round_2);
  tcase_add_test(tc1_1, test_s21_round_3);
  tcase_add_test(tc1_1, test_s21_round_4);
  tcase_add_test(tc1_1, test_s21_round_5);

  // // tests_truncate
  tcase_add_test(tc1_1, test_s21_truncate_1);
  tcase_add_test(tc1_1, test_s21_truncate_2);

  tcase_add_test(tc1_1, test_s21_decimal_to_int_1);
  tcase_add_test(tc1_1, test_s21_decimal_to_int_2);
  tcase_add_test(tc1_1, test_s21_decimal_to_int_3);
  tcase_add_test(tc1_1, test_s21_decimal_to_int_4);

  // tests_from_decimal_to_float
  tcase_add_test(tc1_1, test_s21_decimal_to_float_1);
  tcase_add_test(tc1_1, test_s21_decimal_to_float_2);
  tcase_add_test(tc1_1, test_s21_decimal_to_float_3);

  srunner_run_all(sr, CK_ENV);  // CK_ENV
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}