
#ifndef MATRIX_S21_MATRIX_H
#define MATRIX_S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum { OK, ERROR, CALC_ERROR } error_code_t;

typedef enum { SUM, SUB } math_oper_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

void s21_random_value_matrix(matrix_t *matrix);
void s21_eq_matrix_handle_processing(matrix_t *A, matrix_t *B, int *result_code,
                                     int i, int j);
void s21_eq_matrix_handle(matrix_t *A, matrix_t *B, int *result_code);
void s21_sumsub_matrix_processing(matrix_t *A, matrix_t *B, math_oper_t mth_opr,
                                  double *calc, int i, int j);
void s21_sumsub_matrix_handle(matrix_t *A, matrix_t *B, matrix_t *result,
                              math_oper_t mth_opr);
void s21_is_infnan_handle(matrix_t *A, int *result_code, int i, int j);
int s21_is_infnan(matrix_t *A);
void s21_mult_number_handle(matrix_t *A, matrix_t *result, double number);
void s21_mult_matrix_processing(matrix_t *A, matrix_t *B, double *mul, int i,
                                int j);
void s21_mult_matrix_handle(matrix_t *A, matrix_t *B, matrix_t *result);
void s21_transpose_handle(matrix_t *A, matrix_t *result);
void s21_determinant_processing_handle_check(int *minor_i, int *minor_j, int n);
void s21_determinant_processing_handle(matrix_t *pod_matrix, double **matrix,
                                       int *minor_i, int *minor_j, int n, int c,
                                       int i);
void s21_determinant_processing(matrix_t *pod_matrix, double **matrix, int n,
                                double *det);
double s21_determinant_handle(double **matrix, int n);
void s21_copy_matrix_handle(matrix_t *dst, matrix_t *src, int *ii, int k,
                            int j);
void s21_copy_matrix(matrix_t *dst, matrix_t *src, int i, int j);
void s21_calc_complements_processing(matrix_t *A, matrix_t *result, int i,
                                     int j);
void s21_calc_complements_handle(matrix_t *A, matrix_t *result);

#endif  // MATRIX_S21_MATRIX_H
