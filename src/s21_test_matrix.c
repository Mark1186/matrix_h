#include <check.h>

#include "s21_matrix.h"

START_TEST(s21_test_random_value) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  s21_random_value_matrix(&A);
  ck_assert_int_eq(s21_eq_matrix(&A, &A), SUCCESS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_test_create_matrix_1) {
  int row = 3;
  int column = 3;
  matrix_t matrix;
  int result_code = s21_create_matrix(row, column, &matrix);
  ck_assert_int_eq(result_code, OK);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_test_create_matrix_2) {
  matrix_t matrix;
  int result_code = s21_create_matrix(3, -1, &matrix);
  ck_assert_int_eq(result_code, ERROR);
}

START_TEST(s21_test_create_matrix_3) {
  matrix_t matrix;
  int result_code = s21_create_matrix(5, 0, &matrix);
  ck_assert_int_eq(result_code, ERROR);
}

START_TEST(s21_test_create_matrix_4) {
  int result_code = s21_create_matrix(3, 1, NULL);
  ck_assert_int_eq(result_code, ERROR);
}
END_TEST

START_TEST(s21_test_remove_matrix_1) {
  // success remove
  matrix_t A = {};
  s21_create_matrix(5, 5, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(s21_test_remove_matrix_2) {
  // failure handle null pointer
  s21_remove_matrix(NULL);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(s21_test_remove_matrix_3) {
  // failure handle INCORRECT_MATRIX structure
  matrix_t A = {};
  s21_remove_matrix(&A);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(s21_test_eq_matrix_1) {
  // success with initialized values
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;
  A.matrix[2][2] = 10.0;
  A.matrix[3][0] = 11.0;
  A.matrix[3][1] = 12.0;
  A.matrix[3][2] = 13.0;
  A.matrix[4][0] = 14.0;
  A.matrix[4][1] = 15.0;
  A.matrix[4][2] = 16.0;
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[0][2] = 3.0;
  B.matrix[1][0] = 4.0;
  B.matrix[1][1] = 5.0;
  B.matrix[1][2] = 6.0;
  B.matrix[2][0] = 7.0;
  B.matrix[2][1] = 8.0;
  B.matrix[2][2] = 9.0;
  B.matrix[2][2] = 10.0;
  B.matrix[3][0] = 11.0;
  B.matrix[3][1] = 12.0;
  B.matrix[3][2] = 13.0;
  B.matrix[4][0] = 14.0;
  B.matrix[4][1] = 15.0;
  B.matrix[4][2] = 16.0;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_test_eq_matrix_2) {
  // success with uninitialized values
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_test_eq_matrix_3) {
  // success with a difference of less than 1e-7
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  A.matrix[0][0] = 1.00000001;
  A.matrix[0][1] = 2.00000001;
  A.matrix[0][2] = 3.00000001;
  A.matrix[1][0] = 4.00000001;
  A.matrix[1][1] = 5.00000001;
  A.matrix[1][2] = 6.00000001;
  A.matrix[2][0] = 7.00000001;
  A.matrix[2][1] = 8.00000001;
  A.matrix[2][2] = 9.00000001;
  A.matrix[2][2] = 10.00000001;
  A.matrix[3][0] = 11.00000001;
  A.matrix[3][1] = 12.00000001;
  A.matrix[3][2] = 13.00000001;
  A.matrix[4][0] = 14.00000001;
  A.matrix[4][1] = 15.00000001;
  A.matrix[4][2] = 16.00000001;
  B.matrix[0][0] = 1.00000002;
  B.matrix[0][1] = 2.00000002;
  B.matrix[0][2] = 3.00000002;
  B.matrix[1][0] = 4.00000002;
  B.matrix[1][1] = 5.00000002;
  B.matrix[1][2] = 6.00000002;
  B.matrix[2][0] = 7.00000002;
  B.matrix[2][1] = 8.00000002;
  B.matrix[2][2] = 9.00000002;
  B.matrix[2][2] = 10.00000002;
  B.matrix[3][0] = 11.00000002;
  B.matrix[3][1] = 12.00000002;
  B.matrix[3][2] = 13.00000002;
  B.matrix[4][0] = 14.00000002;
  B.matrix[4][1] = 15.00000002;
  B.matrix[4][2] = 16.00000002;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_test_eq_matrix_4) {
  // failure with different dimensions of matrices
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(3, 4, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_test_eq_matrix_5) {
  // failure with INCORRECT_MATRIX
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_test_eq_matrix_6) {
  // failure with different values
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;
  A.matrix[2][2] = 10.0;
  A.matrix[3][0] = 11.0;
  A.matrix[3][1] = 12.0;
  A.matrix[3][2] = 13.0;
  A.matrix[4][0] = 14.0;
  A.matrix[4][1] = 15.0;
  A.matrix[4][2] = 16.0;
  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 2.0;
  B.matrix[0][2] = 3.0;
  B.matrix[1][0] = 4.0;
  B.matrix[1][1] = 5.0;
  B.matrix[1][2] = 6.0;
  B.matrix[2][0] = 7.0;
  B.matrix[2][1] = 8.0;
  B.matrix[2][2] = 9.0;
  B.matrix[2][2] = 10.0;
  B.matrix[3][0] = 11.0;
  B.matrix[3][1] = 12.0;
  B.matrix[3][2] = 13.0;
  B.matrix[4][0] = 14.0;
  B.matrix[4][1] = 15.0;
  B.matrix[4][2] = 16.0;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_test_sum_matrix_1) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 7.0;
  B.matrix[1][1] = 8.0;
  matrix_t C;

  matrix_t check;
  s21_create_matrix(2, 2, &check);
  check.matrix[0][0] = 6.0;
  check.matrix[0][1] = 8.0;
  check.matrix[1][0] = 10.0;
  check.matrix[1][1] = 12.0;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&check);
}

START_TEST(s21_test_sum_matrix_2) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  matrix_t B;
  s21_create_matrix(2, 3, &B);
  matrix_t C;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_test_sum_matrix_3) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  matrix_t B;
  s21_create_matrix(2, 3, &B);
  matrix_t C;
  ck_assert_int_eq(s21_sum_matrix(NULL, &B, &C), ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_test_sum_matrix_4) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  matrix_t B;
  s21_create_matrix(2, 3, &B);
  matrix_t C;
  ck_assert_int_eq(s21_sum_matrix(&A, NULL, &C), ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_test_sum_matrix_5) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  matrix_t B;
  s21_create_matrix(2, 3, &B);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, NULL), ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_test_sum_matrix_6) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 7.0;
  B.matrix[1][1] = 8.0;
  matrix_t C;

  A.matrix[1][1] = INFINITY;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}

START_TEST(s21_test_sum_matrix_7) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  matrix_t C;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}

START_TEST(s21_test_sum_matrix_8) {
  // sucess with task refence
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 5;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 6;
  B.matrix[0][0] = 1, B.matrix[0][1] = 0, B.matrix[0][2] = 0;
  B.matrix[1][0] = 2, B.matrix[1][1] = 0, B.matrix[1][2] = 0;
  B.matrix[2][0] = 3, B.matrix[2][1] = 4, B.matrix[2][2] = 1;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
  eq_matrix.matrix[0][0] = 2, eq_matrix.matrix[0][1] = 2,
  eq_matrix.matrix[0][2] = 3;
  eq_matrix.matrix[1][0] = 2, eq_matrix.matrix[1][1] = 4,
  eq_matrix.matrix[1][2] = 5;
  eq_matrix.matrix[2][0] = 3, eq_matrix.matrix[2][1] = 4,
  eq_matrix.matrix[2][2] = 7;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_test_sub_matrix_1) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 7.0;
  B.matrix[1][1] = 8.0;
  matrix_t C;

  matrix_t check;
  s21_create_matrix(2, 2, &check);
  check.matrix[0][0] = -4.0;
  check.matrix[0][1] = -4.0;
  check.matrix[1][0] = -4.0;
  check.matrix[1][1] = -4.0;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_test_sub_matrix_2) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  matrix_t B;
  s21_create_matrix(2, 3, &B);
  matrix_t C;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &C), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_test_sub_matrix_3) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  matrix_t B;
  s21_create_matrix(2, 3, &B);
  matrix_t C;
  ck_assert_int_eq(s21_sub_matrix(NULL, &B, &C), ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_test_sub_matrix_4) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  matrix_t B;
  s21_create_matrix(2, 3, &B);
  matrix_t C;
  ck_assert_int_eq(s21_sub_matrix(&A, NULL, &C), ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_test_sub_matrix_5) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  matrix_t B;
  s21_create_matrix(2, 3, &B);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_test_sub_matrix_6) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 7.0;
  B.matrix[1][1] = 8.0;
  matrix_t C;

  B.matrix[1][0] = INFINITY;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &C), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}

START_TEST(s21_test_sub_matrix_7) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  matrix_t C;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}

START_TEST(s21_test_sub_matrix_8) {
  // sucess with task refence
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 5;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 6;
  B.matrix[0][0] = 1, B.matrix[0][1] = 0, B.matrix[0][2] = 0;
  B.matrix[1][0] = 2, B.matrix[1][1] = 0, B.matrix[1][2] = 0;
  B.matrix[2][0] = 3, B.matrix[2][1] = 4, B.matrix[2][2] = 1;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  eq_matrix.matrix[0][0] = 0, eq_matrix.matrix[0][1] = 2,
  eq_matrix.matrix[0][2] = 3;
  eq_matrix.matrix[1][0] = -2, eq_matrix.matrix[1][1] = 4,
  eq_matrix.matrix[1][2] = 5;
  eq_matrix.matrix[2][0] = -3, eq_matrix.matrix[2][1] = -4,
  eq_matrix.matrix[2][2] = 5;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_mult_number_1) {
  // failure with INCORRECT_MATRIX
  matrix_t A = {};
  double number = 3.14;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;
  ck_assert_int_eq(s21_mult_number(&A, number, NULL), ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_2) {
  // failure with non-finite input double
  matrix_t A = {};
  matrix_t result = {};
  double number = INFINITY;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), CALC_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_3) {
  // failure with with the resulting non-finite
  matrix_t A = {};
  matrix_t result = {};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;
  A.matrix[2][2] = INFINITY;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_4) {
  // success with uninitialized values
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_mult_number_5) {
  // success with initialized values
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;
  s21_create_matrix(3, 3, &eq_matrix);
  eq_matrix.matrix[0][0] = 3.0;
  eq_matrix.matrix[0][1] = 6.0;
  eq_matrix.matrix[0][2] = 9.0;
  eq_matrix.matrix[1][0] = 12.0;
  eq_matrix.matrix[1][1] = 15.0;
  eq_matrix.matrix[1][2] = 18.0;
  eq_matrix.matrix[2][0] = 21.0;
  eq_matrix.matrix[2][1] = 24.0;
  eq_matrix.matrix[2][2] = 27.0;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_mult_number_6) {
  // success with task reference values
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 2;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 2, A.matrix[2][1] = 3, A.matrix[2][2] = 4;
  s21_create_matrix(3, 3, &eq_matrix);
  eq_matrix.matrix[0][0] = 2, eq_matrix.matrix[0][1] = 4,
  eq_matrix.matrix[0][2] = 6;
  eq_matrix.matrix[1][0] = 0, eq_matrix.matrix[1][1] = 8,
  eq_matrix.matrix[1][2] = 4;
  eq_matrix.matrix[2][0] = 4, eq_matrix.matrix[2][1] = 6,
  eq_matrix.matrix[2][2] = 8;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_test_mul_matrix_1) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 7.0;
  B.matrix[1][1] = 8.0;
  matrix_t C;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &C), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_test_mul_matrix_2) {
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  matrix_t C;
  ck_assert_int_eq(s21_mult_matrix(NULL, &B, &C), ERROR);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_test_mul_matrix_3) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  matrix_t C;
  ck_assert_int_eq(s21_mult_matrix(&A, NULL, &C), ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_test_mul_matrix_4) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, NULL), ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_test_mul_matrix_5) {
  matrix_t A;
  s21_create_matrix(2, 3, &A);
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  matrix_t C;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &C), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_test_mul_matrix_6) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  s21_random_value_matrix(&A);
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[1][1] = INFINITY;
  matrix_t C;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &C), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_test_mul_matrix_7) {
  // success with uninitialized values
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &eq_matrix);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_test_mul_matrix_8) {
  // success with initialized values
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[0][2] = 3.0;
  B.matrix[1][0] = 4.0;
  B.matrix[1][1] = 5.0;
  B.matrix[1][2] = 6.0;
  B.matrix[2][0] = 7.0;
  B.matrix[2][1] = 8.0;
  B.matrix[2][2] = 9.0;
  s21_create_matrix(3, 3, &eq_matrix);
  eq_matrix.matrix[0][0] = 30, eq_matrix.matrix[0][1] = 36,
  eq_matrix.matrix[0][2] = 42;
  eq_matrix.matrix[1][0] = 66, eq_matrix.matrix[1][1] = 81,
  eq_matrix.matrix[1][2] = 96;
  eq_matrix.matrix[2][0] = 102, eq_matrix.matrix[2][1] = 126,
  eq_matrix.matrix[2][2] = 150;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_test_mul_matrix_9) {
  // success with task reference values
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 4;
  A.matrix[1][0] = 2, A.matrix[1][1] = 5;
  A.matrix[2][0] = 3, A.matrix[2][1] = 6;
  s21_create_matrix(2, 3, &B);
  B.matrix[0][0] = 1, B.matrix[0][1] = -1, B.matrix[0][2] = 1;
  B.matrix[1][0] = 2, B.matrix[1][1] = 3, B.matrix[1][2] = 4;
  s21_create_matrix(3, 3, &eq_matrix);
  eq_matrix.matrix[0][0] = 9, eq_matrix.matrix[0][1] = 11,
  eq_matrix.matrix[0][2] = 17;
  eq_matrix.matrix[1][0] = 12, eq_matrix.matrix[1][1] = 13,
  eq_matrix.matrix[1][2] = 22;
  eq_matrix.matrix[2][0] = 15, eq_matrix.matrix[2][1] = 15,
  eq_matrix.matrix[2][2] = 27;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_transpose_1) {
  // failure with INCORRECT_MATRIX
  matrix_t A = {};
  matrix_t result = {};
  ck_assert_int_eq(s21_transpose(&A, &result), ERROR);
}
END_TEST

START_TEST(s21_transpose_2) {
  // success with unininitialized matrix 3x2
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(3, 2, &A);
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_3) {
  // success with unininitialized matrix 2x3
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(2, 3, &A);
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_4) {
  // success with initialized matrix 2x3
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &eq_matrix);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  eq_matrix.matrix[0][0] = 1, eq_matrix.matrix[0][1] = 4;
  eq_matrix.matrix[1][0] = 2, eq_matrix.matrix[1][1] = 5;
  eq_matrix.matrix[2][0] = 3, eq_matrix.matrix[2][1] = 6;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&eq_matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_5) {
  // success with task reference values and 3x2 matrix
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 4;
  A.matrix[1][0] = 2, A.matrix[1][1] = 5;
  A.matrix[2][0] = 3, A.matrix[2][1] = 6;
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  eq_matrix.matrix[0][0] = 1, eq_matrix.matrix[0][1] = 2,
  eq_matrix.matrix[0][2] = 3;
  eq_matrix.matrix[1][0] = 4, eq_matrix.matrix[1][1] = 5,
  eq_matrix.matrix[1][2] = 6;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&eq_matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_1) {
  // failure with INCORRECT_MATRIX
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_calc_complements(&A, NULL), ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  // failure with vector matrix (rows or cols == 1)
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(1, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALC_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  // success with task reference values
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  eq_matrix.matrix[0][0] = 0, eq_matrix.matrix[0][1] = 10,
  eq_matrix.matrix[0][2] = -20;
  eq_matrix.matrix[1][0] = 4, eq_matrix.matrix[1][1] = -14,
  eq_matrix.matrix[1][2] = 8;
  eq_matrix.matrix[2][0] = -8, eq_matrix.matrix[2][1] = -2,
  eq_matrix.matrix[2][2] = 4;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_determinant_1) {
  // failure with INCORRECT_MATRIX
  matrix_t A = {};
  double det = 0;
  ck_assert_int_eq(s21_determinant(&A, &det), ERROR);
}
END_TEST

START_TEST(s21_determinant_2) {
  // failure with non-square matrix
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 6.0;
  ck_assert_int_eq(s21_determinant(&A, &det), CALC_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3) {
  // success with task reference values
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_4) {
  // success with 2x2 matrix
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 12.0;
  A.matrix[0][1] = 4.0;
  A.matrix[1][0] = 342.0;
  A.matrix[1][1] = 9.0;
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, -1260);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_5) {
  // success with 1x1 matrix
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 21;
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 21);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_1) {
  // failure with INCORRECT_MATRIX
  matrix_t A = {};
  matrix_t result = {};
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), ERROR);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  // failure when matrix has s21_determinant_handle equal to zero
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALC_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  // failure with non-square matrix
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(5, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;
  A.matrix[3][0] = 10.0;
  A.matrix[3][1] = 11.0;
  A.matrix[3][2] = 12.0;
  A.matrix[4][0] = 13.0;
  A.matrix[4][1] = 14.0;
  A.matrix[4][2] = 15.0;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALC_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  // success matrix 1x1
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &eq_matrix);
  A.matrix[0][0] = 21;
  eq_matrix.matrix[0][0] = 1.0 / 21.0;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_inverse_matrix_5) {
  // success with task reference values
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 2, A.matrix[0][1] = 5, A.matrix[0][2] = 7;
  A.matrix[1][0] = 6, A.matrix[1][1] = 3, A.matrix[1][2] = 4;
  A.matrix[2][0] = 5, A.matrix[2][1] = -2, A.matrix[2][2] = -3;
  eq_matrix.matrix[0][0] = 1, eq_matrix.matrix[0][1] = -1,
  eq_matrix.matrix[0][2] = 1;
  eq_matrix.matrix[1][0] = -38, eq_matrix.matrix[1][1] = 41,
  eq_matrix.matrix[1][2] = -34;
  eq_matrix.matrix[2][0] = 27, eq_matrix.matrix[2][1] = -29,
  eq_matrix.matrix[2][2] = 24;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_inverse_matrix_6) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;
  s21_inverse_matrix(&A, &Z);

  s21_create_matrix(4, 4, &X);
  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = 1.0;
  X.matrix[0][2] = 0.0;
  X.matrix[0][3] = 0.0;
  X.matrix[1][0] = -5.0 / 23.0;
  X.matrix[1][1] = -121.0 / 23.0;
  X.matrix[1][2] = 2.0 / 23.0;
  X.matrix[1][3] = 1.0 / 23.0;
  X.matrix[2][0] = -18.0 / 23.0;
  X.matrix[2][1] = -379.0 / 46.0;
  X.matrix[2][2] = 19.0 / 46.0;
  X.matrix[2][3] = -25.0 / 46.0;
  X.matrix[3][0] = 53.0 / 69.0;
  X.matrix[3][1] = 1061.0 / 138.0;
  X.matrix[3][2] = -47.0 / 138.0;
  X.matrix[3][3] = 19.0 / 46.0;
  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_inverse_matrix_7) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;

  res = s21_inverse_matrix(&A, &Z);

  ck_assert_int_eq(Z.matrix[0][0] == (1.0 / A.matrix[0][0]), 1);
  ck_assert_int_eq(res, OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_inverse_matrix_8) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;

  res = s21_inverse_matrix(&A, &Z);
  ck_assert_int_eq(res, CALC_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_9) {
  int res = 0;
  matrix_t A;
  matrix_t Z;

  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;

  res = s21_inverse_matrix(&A, &Z);
  ck_assert_int_eq(res, CALC_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_10) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;
  s21_remove_matrix(&A);
  res = s21_inverse_matrix(&A, &Z);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(s21_inverse_matrix_11) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 8.0;
  A.matrix[2][1] = 6.0;
  A.matrix[2][2] = 9.0;

  s21_inverse_matrix(&A, &Z);

  s21_create_matrix(3, 3, &X);

  X.matrix[0][0] = -3.0 / 5.0;
  X.matrix[0][1] = 0.0;
  X.matrix[0][2] = 1.0 / 5.0;
  X.matrix[1][0] = -4.0 / 5.0;
  X.matrix[1][1] = 1.0;
  X.matrix[1][2] = -2.0 / 5.0;
  X.matrix[2][0] = 16.0 / 15.0;
  X.matrix[2][1] = -2.0 / 3.0;
  X.matrix[2][2] = 1.0 / 5.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_inverse_matrix_12) {
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(3, -3, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_13) {
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 8.0;
  A.matrix[2][1] = 6.0;
  A.matrix[2][2] = 9.0;
  ck_assert_int_eq(s21_inverse_matrix(&A, NULL), ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_14) {
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 8.0;
  A.matrix[2][1] = 6.0;
  A.matrix[2][2] = 9.0;
  ck_assert_int_eq(s21_inverse_matrix(NULL, NULL), ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_15) {
  matrix_t A = {};
  s21_create_matrix(3, 3, NULL);
  ck_assert_int_eq(s21_inverse_matrix(NULL, NULL), ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_16) {
  // det eq zero
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0, A.matrix[0][1] = 5, A.matrix[0][2] = 7;
  A.matrix[1][0] = 0, A.matrix[1][1] = 3, A.matrix[1][2] = 4;
  A.matrix[2][0] = 0, A.matrix[2][1] = -2, A.matrix[2][2] = -3;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_17) {
  // success with 2x2 matrix
  matrix_t A = {};
  matrix_t result;
  matrix_t check;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  s21_create_matrix(2, 2, &check);
  check.matrix[0][0] = -2;
  check.matrix[0][1] = 1;
  check.matrix[1][0] = 1.5;
  check.matrix[1][1] = -0.5;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

Suite *s21_matrix_suite(void) {
  Suite *suite;
  TCase *tc_random_value, *tc_remove_matrix_1, *tc_remove_matrix_2,
      *tc_remove_matrix_3, *tc_create_matrix_1, *tc_create_matrix_2,
      *tc_create_matrix_3, *tc_create_matrix_4, *tc_eq_matrix_1,
      *tc_eq_matrix_2, *tc_eq_matrix_3, *tc_eq_matrix_4, *tc_eq_matrix_5,
      *tc_eq_matrix_6, *tc_sum_matrix_1, *tc_sum_matrix_2, *tc_sum_matrix_3,
      *tc_sum_matrix_4, *tc_sum_matrix_5, *tc_sum_matrix_6, *tc_sum_matrix_7,
      *tc_sum_matrix_8, *tc_sub_matrix_1, *tc_sub_matrix_2, *tc_sub_matrix_3,
      *tc_sub_matrix_4, *tc_sub_matrix_5, *tc_sub_matrix_6, *tc_sub_matrix_7,
      *tc_sub_matrix_8, *tc_mul_number_1, *tc_mul_number_2, *tc_mul_number_3,
      *tc_mul_number_4, *tc_mul_number_5, *tc_mul_number_6, *tc_mul_matrix_1,
      *tc_mul_matrix_2, *tc_mul_matrix_3, *tc_mul_matrix_4, *tc_mul_matrix_5,
      *tc_mul_matrix_6, *tc_mul_matrix_7, *tc_mul_matrix_8, *tc_mul_matrix_9,
      *tc_transpose_1, *tc_transpose_2, *tc_transpose_3, *tc_transpose_4,
      *tc_transpose_5, *tc_calc_complements_1, *tc_calc_complements_2,
      *tc_calc_complements_3, *tc_determinant_1, *tc_determinant_2,
      *tc_determinant_3, *tc_determinant_4, *tc_determinant_5,
      *tc_inverse_matrix_1, *tc_inverse_matrix_2, *tc_inverse_matrix_3,
      *tc_inverse_matrix_4, *tc_inverse_matrix_5, *tc_inverse_matrix_6,
      *tc_inverse_matrix_7, *tc_inverse_matrix_8, *tc_inverse_matrix_9,
      *tc_inverse_matrix_10, *tc_inverse_matrix_11, *tc_inverse_matrix_12,
      *tc_inverse_matrix_13, *tc_inverse_matrix_14, *tc_inverse_matrix_15,
      *tc_inverse_matrix_16, *tc_inverse_matrix_17;
  suite = suite_create("s21_test_matrix");

  tc_random_value = tcase_create("s21_test_random_value");
  tcase_add_test(tc_random_value, s21_test_random_value);
  suite_add_tcase(suite, tc_random_value);

  tc_create_matrix_1 = tcase_create("s21_test_create_matrix_1");
  tcase_add_test(tc_create_matrix_1, s21_test_create_matrix_1);
  suite_add_tcase(suite, tc_create_matrix_1);

  tc_create_matrix_2 = tcase_create("s21_test_create_matrix_2");
  tcase_add_test(tc_create_matrix_2, s21_test_create_matrix_2);
  suite_add_tcase(suite, tc_create_matrix_2);

  tc_create_matrix_3 = tcase_create("s21_test_create_matrix_3");
  tcase_add_test(tc_create_matrix_3, s21_test_create_matrix_3);
  suite_add_tcase(suite, tc_create_matrix_3);

  tc_create_matrix_4 = tcase_create("s21_test_create_matrix_4");
  tcase_add_test(tc_create_matrix_4, s21_test_create_matrix_4);
  suite_add_tcase(suite, tc_create_matrix_4);

  tc_remove_matrix_1 = tcase_create("s21_test_remove_matrix_1");
  tcase_add_test(tc_remove_matrix_1, s21_test_remove_matrix_1);
  suite_add_tcase(suite, tc_remove_matrix_1);

  tc_remove_matrix_2 = tcase_create("s21_test_remove_matrix_2");
  tcase_add_test(tc_remove_matrix_2, s21_test_remove_matrix_2);
  suite_add_tcase(suite, tc_remove_matrix_2);

  tc_remove_matrix_3 = tcase_create("s21_test_remove_matrix_3");
  tcase_add_test(tc_remove_matrix_3, s21_test_remove_matrix_3);
  suite_add_tcase(suite, tc_remove_matrix_3);

  tc_eq_matrix_1 = tcase_create("s21_test_eq_matrix_1");
  tcase_add_test(tc_eq_matrix_1, s21_test_eq_matrix_1);
  suite_add_tcase(suite, tc_eq_matrix_1);

  tc_eq_matrix_2 = tcase_create("s21_test_eq_matrix_2");
  tcase_add_test(tc_eq_matrix_2, s21_test_eq_matrix_2);
  suite_add_tcase(suite, tc_eq_matrix_2);

  tc_eq_matrix_3 = tcase_create("s21_test_eq_matrix_3");
  tcase_add_test(tc_eq_matrix_3, s21_test_eq_matrix_3);
  suite_add_tcase(suite, tc_eq_matrix_3);

  tc_eq_matrix_4 = tcase_create("s21_test_eq_matrix_4");
  tcase_add_test(tc_eq_matrix_4, s21_test_eq_matrix_4);
  suite_add_tcase(suite, tc_eq_matrix_4);

  tc_eq_matrix_5 = tcase_create("s21_test_eq_matrix_5");
  tcase_add_test(tc_eq_matrix_5, s21_test_eq_matrix_5);
  suite_add_tcase(suite, tc_eq_matrix_5);

  tc_eq_matrix_6 = tcase_create("s21_test_eq_matrix_6");
  tcase_add_test(tc_eq_matrix_6, s21_test_eq_matrix_6);
  suite_add_tcase(suite, tc_eq_matrix_6);

  tc_sum_matrix_1 = tcase_create("s21_test_sum_matrix_1");
  tcase_add_test(tc_sum_matrix_1, s21_test_sum_matrix_1);
  suite_add_tcase(suite, tc_sum_matrix_1);

  tc_sum_matrix_2 = tcase_create("s21_test_sum_matrix_2");
  tcase_add_test(tc_sum_matrix_2, s21_test_sum_matrix_2);
  suite_add_tcase(suite, tc_sum_matrix_2);

  tc_sum_matrix_3 = tcase_create("s21_test_sum_matrix_3");
  tcase_add_test(tc_sum_matrix_3, s21_test_sum_matrix_3);
  suite_add_tcase(suite, tc_sum_matrix_3);

  tc_sum_matrix_4 = tcase_create("s21_test_sum_matrix_4");
  tcase_add_test(tc_sum_matrix_4, s21_test_sum_matrix_4);
  suite_add_tcase(suite, tc_sum_matrix_4);

  tc_sum_matrix_5 = tcase_create("s21_test_sum_matrix_5");
  tcase_add_test(tc_sum_matrix_5, s21_test_sum_matrix_5);
  suite_add_tcase(suite, tc_sum_matrix_5);

  tc_sum_matrix_6 = tcase_create("s21_test_sum_matrix_6");
  tcase_add_test(tc_sum_matrix_6, s21_test_sum_matrix_6);
  suite_add_tcase(suite, tc_sum_matrix_6);

  tc_sum_matrix_7 = tcase_create("s21_test_sum_matrix_7");
  tcase_add_test(tc_sum_matrix_7, s21_test_sum_matrix_7);
  suite_add_tcase(suite, tc_sum_matrix_7);

  tc_sum_matrix_8 = tcase_create("s21_test_sum_matrix_8");
  tcase_add_test(tc_sum_matrix_8, s21_test_sum_matrix_8);
  suite_add_tcase(suite, tc_sum_matrix_8);

  tc_sub_matrix_1 = tcase_create("s21_test_sub_matrix_1");
  tcase_add_test(tc_sub_matrix_1, s21_test_sub_matrix_1);
  suite_add_tcase(suite, tc_sub_matrix_1);

  tc_sub_matrix_2 = tcase_create("s21_test_sub_matrix_2");
  tcase_add_test(tc_sub_matrix_2, s21_test_sub_matrix_2);
  suite_add_tcase(suite, tc_sub_matrix_2);

  tc_sub_matrix_3 = tcase_create("s21_test_sub_matrix_3");
  tcase_add_test(tc_sub_matrix_3, s21_test_sub_matrix_3);
  suite_add_tcase(suite, tc_sub_matrix_3);

  tc_sub_matrix_4 = tcase_create("s21_test_sub_matrix_4");
  tcase_add_test(tc_sub_matrix_4, s21_test_sub_matrix_4);
  suite_add_tcase(suite, tc_sub_matrix_4);

  tc_sub_matrix_5 = tcase_create("s21_test_sub_matrix_5");
  tcase_add_test(tc_sub_matrix_5, s21_test_sub_matrix_5);
  suite_add_tcase(suite, tc_sub_matrix_5);

  tc_sub_matrix_6 = tcase_create("s21_test_sub_matrix_6");
  tcase_add_test(tc_sub_matrix_6, s21_test_sub_matrix_6);
  suite_add_tcase(suite, tc_sub_matrix_6);

  tc_sub_matrix_7 = tcase_create("s21_test_sub_matrix_7");
  tcase_add_test(tc_sub_matrix_7, s21_test_sub_matrix_7);
  suite_add_tcase(suite, tc_sub_matrix_7);

  tc_sub_matrix_8 = tcase_create("s21_test_sub_matrix_8");
  tcase_add_test(tc_sub_matrix_8, s21_test_sub_matrix_8);
  suite_add_tcase(suite, tc_sub_matrix_8);

  tc_mul_number_1 = tcase_create("s21_test_mul_number_1");
  tcase_add_test(tc_mul_number_1, s21_mult_number_1);
  suite_add_tcase(suite, tc_mul_number_1);

  tc_mul_number_2 = tcase_create("s21_test_mul_number_2");
  tcase_add_test(tc_mul_number_2, s21_mult_number_2);
  suite_add_tcase(suite, tc_mul_number_2);

  tc_mul_number_3 = tcase_create("s21_test_mul_number_3");
  tcase_add_test(tc_mul_number_3, s21_mult_number_3);
  suite_add_tcase(suite, tc_mul_number_3);

  tc_mul_number_4 = tcase_create("s21_test_mul_number_4");
  tcase_add_test(tc_mul_number_4, s21_mult_number_4);
  suite_add_tcase(suite, tc_mul_number_4);

  tc_mul_number_5 = tcase_create("s21_test_mul_number_5");
  tcase_add_test(tc_mul_number_5, s21_mult_number_5);
  suite_add_tcase(suite, tc_mul_number_5);

  tc_mul_number_6 = tcase_create("s21_test_mul_number_6");
  tcase_add_test(tc_mul_number_6, s21_mult_number_6);
  suite_add_tcase(suite, tc_mul_number_6);

  tc_mul_matrix_1 = tcase_create("s21_test_mul_matrix_1");
  tcase_add_test(tc_mul_matrix_1, s21_test_mul_matrix_1);
  suite_add_tcase(suite, tc_mul_matrix_1);

  tc_mul_matrix_2 = tcase_create("s21_test_mul_matrix_2");
  tcase_add_test(tc_mul_matrix_2, s21_test_mul_matrix_2);
  suite_add_tcase(suite, tc_mul_matrix_2);

  tc_mul_matrix_3 = tcase_create("s21_test_mul_matrix_3");
  tcase_add_test(tc_mul_matrix_3, s21_test_mul_matrix_3);
  suite_add_tcase(suite, tc_mul_matrix_3);

  tc_mul_matrix_4 = tcase_create("s21_test_mul_matrix_4");
  tcase_add_test(tc_mul_matrix_4, s21_test_mul_matrix_4);
  suite_add_tcase(suite, tc_mul_matrix_4);

  tc_mul_matrix_5 = tcase_create("s21_test_mul_matrix_5");
  tcase_add_test(tc_mul_matrix_5, s21_test_mul_matrix_5);
  suite_add_tcase(suite, tc_mul_matrix_5);

  tc_mul_matrix_6 = tcase_create("s21_test_mul_matrix_6");
  tcase_add_test(tc_mul_matrix_6, s21_test_mul_matrix_6);
  suite_add_tcase(suite, tc_mul_matrix_6);

  tc_mul_matrix_7 = tcase_create("s21_test_mul_matrix_7");
  tcase_add_test(tc_mul_matrix_7, s21_test_mul_matrix_7);
  suite_add_tcase(suite, tc_mul_matrix_7);

  tc_mul_matrix_8 = tcase_create("s21_test_mul_matrix_8");
  tcase_add_test(tc_mul_matrix_8, s21_test_mul_matrix_8);
  suite_add_tcase(suite, tc_mul_matrix_8);

  tc_mul_matrix_9 = tcase_create("s21_test_mul_matrix_9");
  tcase_add_test(tc_mul_matrix_9, s21_test_mul_matrix_9);
  suite_add_tcase(suite, tc_mul_matrix_9);

  tc_transpose_1 = tcase_create("s21_test_transpose_1");
  tcase_add_test(tc_transpose_1, s21_transpose_1);
  suite_add_tcase(suite, tc_transpose_1);

  tc_transpose_2 = tcase_create("s21_test_transpose_2");
  tcase_add_test(tc_transpose_2, s21_transpose_2);
  suite_add_tcase(suite, tc_transpose_2);

  tc_transpose_3 = tcase_create("s21_test_transpose_3");
  tcase_add_test(tc_transpose_3, s21_transpose_3);
  suite_add_tcase(suite, tc_transpose_3);

  tc_transpose_4 = tcase_create("s21_test_transpose_4");
  tcase_add_test(tc_transpose_4, s21_transpose_4);
  suite_add_tcase(suite, tc_transpose_4);

  tc_transpose_5 = tcase_create("s21_test_transpose_5");
  tcase_add_test(tc_transpose_5, s21_transpose_5);
  suite_add_tcase(suite, tc_transpose_5);

  tc_calc_complements_1 = tcase_create("s21_test_calc_complements_1");
  tcase_add_test(tc_calc_complements_1, s21_calc_complements_1);
  suite_add_tcase(suite, tc_calc_complements_1);

  tc_calc_complements_2 = tcase_create("s21_test_calc_complements_2");
  tcase_add_test(tc_calc_complements_2, s21_calc_complements_2);
  suite_add_tcase(suite, tc_calc_complements_2);

  tc_calc_complements_3 = tcase_create("s21_test_calc_complements_3");
  tcase_add_test(tc_calc_complements_3, s21_calc_complements_3);
  suite_add_tcase(suite, tc_calc_complements_3);

  tc_determinant_1 = tcase_create("s21_test_determinant_1");
  tcase_add_test(tc_determinant_1, s21_determinant_1);
  suite_add_tcase(suite, tc_determinant_1);

  tc_determinant_2 = tcase_create("s21_test_determinant_2");
  tcase_add_test(tc_determinant_2, s21_determinant_2);
  suite_add_tcase(suite, tc_determinant_2);

  tc_determinant_3 = tcase_create("s21_test_determinant_3");
  tcase_add_test(tc_determinant_3, s21_determinant_3);
  suite_add_tcase(suite, tc_determinant_3);

  tc_determinant_4 = tcase_create("s21_test_determinant_4");
  tcase_add_test(tc_determinant_4, s21_determinant_4);
  suite_add_tcase(suite, tc_determinant_4);

  tc_determinant_5 = tcase_create("s21_test_determinant_5");
  tcase_add_test(tc_determinant_5, s21_determinant_5);
  suite_add_tcase(suite, tc_determinant_5);

  tc_inverse_matrix_1 = tcase_create("s21_test_inverse_matrix_1");
  tcase_add_test(tc_inverse_matrix_1, s21_inverse_matrix_1);
  suite_add_tcase(suite, tc_inverse_matrix_1);

  tc_inverse_matrix_2 = tcase_create("s21_test_inverse_matrix_2");
  tcase_add_test(tc_inverse_matrix_2, s21_inverse_matrix_2);
  suite_add_tcase(suite, tc_inverse_matrix_2);

  tc_inverse_matrix_3 = tcase_create("s21_test_inverse_matrix_3");
  tcase_add_test(tc_inverse_matrix_3, s21_inverse_matrix_3);
  suite_add_tcase(suite, tc_inverse_matrix_3);

  tc_inverse_matrix_4 = tcase_create("s21_test_inverse_matrix_4");
  tcase_add_test(tc_inverse_matrix_4, s21_inverse_matrix_4);
  suite_add_tcase(suite, tc_inverse_matrix_4);

  tc_inverse_matrix_5 = tcase_create("s21_test_inverse_matrix_5");
  tcase_add_test(tc_inverse_matrix_5, s21_inverse_matrix_5);
  suite_add_tcase(suite, tc_inverse_matrix_5);

  tc_inverse_matrix_6 = tcase_create("s21_test_inverse_matrix_6");
  tcase_add_test(tc_inverse_matrix_6, s21_inverse_matrix_6);
  suite_add_tcase(suite, tc_inverse_matrix_6);

  tc_inverse_matrix_7 = tcase_create("s21_test_inverse_matrix_7");
  tcase_add_test(tc_inverse_matrix_7, s21_inverse_matrix_7);
  suite_add_tcase(suite, tc_inverse_matrix_7);

  tc_inverse_matrix_8 = tcase_create("s21_test_inverse_matrix_8");
  tcase_add_test(tc_inverse_matrix_8, s21_inverse_matrix_8);
  suite_add_tcase(suite, tc_inverse_matrix_8);

  tc_inverse_matrix_9 = tcase_create("s21_test_inverse_matrix_9");
  tcase_add_test(tc_inverse_matrix_9, s21_inverse_matrix_9);
  suite_add_tcase(suite, tc_inverse_matrix_9);

  tc_inverse_matrix_10 = tcase_create("s21_test_inverse_matrix_10");
  tcase_add_test(tc_inverse_matrix_10, s21_inverse_matrix_10);
  suite_add_tcase(suite, tc_inverse_matrix_10);

  tc_inverse_matrix_11 = tcase_create("s21_test_inverse_matrix_11");
  tcase_add_test(tc_inverse_matrix_11, s21_inverse_matrix_11);
  suite_add_tcase(suite, tc_inverse_matrix_11);

  tc_inverse_matrix_12 = tcase_create("s21_test_inverse_matrix_12");
  tcase_add_test(tc_inverse_matrix_12, s21_inverse_matrix_12);
  suite_add_tcase(suite, tc_inverse_matrix_12);

  tc_inverse_matrix_13 = tcase_create("s21_test_inverse_matrix_13");
  tcase_add_test(tc_inverse_matrix_13, s21_inverse_matrix_13);
  suite_add_tcase(suite, tc_inverse_matrix_13);

  tc_inverse_matrix_14 = tcase_create("s21_test_inverse_matrix_14");
  tcase_add_test(tc_inverse_matrix_14, s21_inverse_matrix_14);
  suite_add_tcase(suite, tc_inverse_matrix_14);

  tc_inverse_matrix_15 = tcase_create("s21_test_inverse_matrix_15");
  tcase_add_test(tc_inverse_matrix_15, s21_inverse_matrix_15);
  suite_add_tcase(suite, tc_inverse_matrix_15);

  tc_inverse_matrix_16 = tcase_create("s21_test_inverse_matrix_16");
  tcase_add_test(tc_inverse_matrix_16, s21_inverse_matrix_16);
  suite_add_tcase(suite, tc_inverse_matrix_16);

  tc_inverse_matrix_17 = tcase_create("s21_test_inverse_matrix_17");
  tcase_add_test(tc_inverse_matrix_17, s21_inverse_matrix_17);
  suite_add_tcase(suite, tc_inverse_matrix_17);

  return suite;
}

void test_fail(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int fail = 0;
  test_fail(s21_matrix_suite(), &fail);
  return 0;
}