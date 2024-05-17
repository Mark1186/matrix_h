#include "s21_matrix.h"

void s21_random_value_matrix(matrix_t *matrix) {
  if (matrix != NULL && matrix->matrix != NULL) {
    double min = 1.0;
    double max = 9.9;
    for (int i = 0; i < matrix->rows; ++i) {
      for (int j = 0; j < matrix->columns; ++j) {
        double scale = rand() / (double)RAND_MAX;
        matrix->matrix[i][j] = min + scale * (max - min);
      }
    }
  }
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int result_code = OK;
  if (result && rows > 0 && columns > 0) {
    result->matrix = 0;
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix) {
      for (int i = 0; i < rows; ++i) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
      }
    }
  } else {
    result_code = ERROR;
  }
  return result_code;
}

void s21_eq_matrix_handle_processing(matrix_t *A, matrix_t *B, int *result_code,
                                     int i, int j) {
  if (A && A->matrix && B && B->matrix && result_code) {
    double diff = fabs(A->matrix[i][j] - B->matrix[i][j]);
    if (diff >= 1e-7) {
      *result_code = FAILURE;
    }
  }
}

void s21_eq_matrix_handle(matrix_t *A, matrix_t *B, int *result_code) {
  if (A && A->matrix && B && B->matrix && result_code) {
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        s21_eq_matrix_handle_processing(A, B, result_code, i, j);
      }
    }
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result_code = SUCCESS;
  if (A && A->matrix && B && B->matrix) {
    if ((A->columns == B->columns) && (A->rows == B->rows)) {
      s21_eq_matrix_handle(A, B, &result_code);
    } else {
      result_code = FAILURE;
    }
  } else {
    result_code = FAILURE;
  }
  return result_code;
}

void s21_remove_matrix(matrix_t *A) {
  if (A && A->matrix) {
    for (int i = 0; i < A->rows; ++i) {
      free(A->matrix[i]);
      A->matrix[i] = NULL;
    }
    free(A->matrix);
    A->matrix = NULL;
  }
}

void s21_sumsub_matrix_processing(matrix_t *A, matrix_t *B, math_oper_t mth_opr,
                                  double *calc, int i, int j) {
  if (A && A->matrix && B && B->matrix && calc) {
    if (mth_opr == SUB) {
      *calc = A->matrix[i][j] - B->matrix[i][j];
    } else if (mth_opr == SUM) {
      *calc = A->matrix[i][j] + B->matrix[i][j];
    }
  }
}

void s21_sumsub_matrix_handle(matrix_t *A, matrix_t *B, matrix_t *result,
                              math_oper_t mth_opr) {
  if (A && A->matrix && B && B->matrix && result) {
    for (int i = 0; i < result->rows; ++i) {
      for (int j = 0; j < result->columns; ++j) {
        double calc = 0.0;
        s21_sumsub_matrix_processing(A, B, mth_opr, &calc, i, j);
        result->matrix[i][j] = calc;
      }
    }
  }
}

void s21_is_infnan_handle(matrix_t *A, int *result_code, int i, int j) {
  if (A && A->matrix && result_code) {
    if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j])) {
      *result_code = CALC_ERROR;
    }
  }
}

int s21_is_infnan(matrix_t *A) {
  int result_code = OK;
  if (A && A->matrix) {
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        s21_is_infnan_handle(A, &result_code, i, j);
      }
    }
  } else {
    result_code = ERROR;
  }
  return result_code;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = OK;
  if (A && A->matrix && B && B->matrix && result) {
    if ((A->rows == B->rows) && (A->columns == B->columns)) {
      s21_create_matrix(A->rows, A->columns, result);
      int is_infnan_A = s21_is_infnan(A);
      int is_infnan_B = s21_is_infnan(B);
      if (is_infnan_A || is_infnan_B) {
        result_code = CALC_ERROR;
      } else {
        s21_sumsub_matrix_handle(A, B, result, SUM);
      }
    } else {
      result_code = CALC_ERROR;
    }
  } else {
    result_code = ERROR;
  }
  return result_code;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = OK;
  if (A && A->matrix && B && B->matrix && result) {
    if ((A->rows == B->rows) && (A->columns == B->columns)) {
      s21_create_matrix(A->rows, A->columns, result);
      int is_infnan_A = s21_is_infnan(A);
      int is_infnan_B = s21_is_infnan(B);
      if (is_infnan_A || is_infnan_B) {
        result_code = CALC_ERROR;
      } else {
        s21_sumsub_matrix_handle(A, B, result, SUB);
      }
    } else {
      result_code = CALC_ERROR;
    }
  } else {
    result_code = ERROR;
  }
  return result_code;
}

void s21_mult_number_handle(matrix_t *A, matrix_t *result, double number) {
  if (A && A->matrix && result) {
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        double mult_num = A->matrix[i][j] * number;
        result->matrix[i][j] = mult_num;
      }
    }
  }
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int result_code = OK;
  if (A && A->matrix && result) {
    int is_infnan_A = s21_is_infnan(A);
    if (is_infnan_A || (isinf(number) || isnan(number))) {
      result_code = CALC_ERROR;
    } else {
      s21_create_matrix(A->rows, A->columns, result);
      s21_mult_number_handle(A, result, number);
    }
  } else {
    result_code = ERROR;
  }
  return result_code;
}

void s21_mult_matrix_processing(matrix_t *A, matrix_t *B, double *mul, int i,
                                int j) {
  if (A && A->matrix && B && B->matrix && mul && i >= 0 && j >= 0) {
    for (int k = 0; k < A->columns; ++k) {
      *mul += A->matrix[i][k] * B->matrix[k][j];
    }
  }
}
void s21_mult_matrix_handle(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A && A->matrix && B && B->matrix && result) {
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < B->columns; ++j) {
        double mul = 0;
        s21_mult_matrix_processing(A, B, &mul, i, j);
        result->matrix[i][j] = mul;
      }
    }
  }
}
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = OK;
  if (A && A->matrix && B && B->matrix && result) {
    int is_infnan_A = s21_is_infnan(A);
    int is_infnan_B = s21_is_infnan(B);
    if (is_infnan_A || is_infnan_B) {
      result_code = CALC_ERROR;
    } else if (A->columns == B->rows) {
      s21_create_matrix(A->rows, B->columns, result);
      s21_mult_matrix_handle(A, B, result);
    } else {
      result_code = CALC_ERROR;
    }
  } else {
    result_code = ERROR;
  }
  return result_code;
}

void s21_transpose_handle(matrix_t *A, matrix_t *result) {
  if (A && A->matrix && result) {
    for (int i = 0; i < A->columns; ++i) {
      for (int j = 0; j < A->rows; ++j) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int result_code = OK;
  if (A && A->matrix && result) {
    if (A->rows > 0 && A->columns > 0) {
      s21_create_matrix(A->columns, A->rows, result);
      s21_transpose_handle(A, result);
    }
  } else {
    result_code = ERROR;
  }
  return result_code;
}

void s21_determinant_processing_handle_check(int *minor_i, int *minor_j,
                                             int n) {
  if (*minor_j == n - 1) {
    (*minor_i)++;
    *minor_j = 0;
  }
}
void s21_determinant_processing_handle(matrix_t *pod_matrix, double **matrix,
                                       int *minor_i, int *minor_j, int n, int c,
                                       int i) {
  if (pod_matrix && pod_matrix->matrix && matrix && minor_i && minor_j) {
    for (int j = 0; j < n; j++) {
      if (j != c) {
        pod_matrix->matrix[*minor_i][(*minor_j)++] = matrix[i][j];
        s21_determinant_processing_handle_check(minor_i, minor_j, n);
      }
    }
  }
}

void s21_determinant_processing(matrix_t *pod_matrix, double **matrix, int n,
                                double *det) {
  if (pod_matrix && pod_matrix->matrix && matrix && det) {
    for (int c = 0; c < n; c++) {
      int minor_i = 0, minor_j = 0;
      for (int i = 1; i < n; i++) {
        s21_determinant_processing_handle(pod_matrix, matrix, &minor_i,
                                          &minor_j, n, c, i);
      }
      *det += (c % 2 == 0 ? 1 : -1) * matrix[0][c] *
              s21_determinant_handle(pod_matrix->matrix, n - 1);
    }
  }
}

double s21_determinant_handle(double **matrix, int n) {
  double det = 0.0;
  if (matrix && n > 0) {
    matrix_t pod_matrix;
    s21_create_matrix(n, n, &pod_matrix);

    if (n == 1) {
      det = matrix[0][0];
    } else if (n == 2) {
      det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
      s21_determinant_processing(&pod_matrix, matrix, n, &det);
    }
    s21_remove_matrix(&pod_matrix);
  }
  return det;
}

void s21_copy_matrix_handle(matrix_t *dst, matrix_t *src, int *ii, int k,
                            int j) {
  if (dst && dst->matrix && src && src->matrix) {
    for (int l = 0, jj = 0; l < src->columns; ++l) {
      if (l != j) {
        dst->matrix[*ii][jj] = src->matrix[k][l];
        ++jj;
      }
    }
    (*ii)++;
  }
}

void s21_copy_matrix(matrix_t *dst, matrix_t *src, int i, int j) {
  if (dst && dst->matrix && src && src->matrix) {
    for (int k = 0, ii = 0; k < src->rows; ++k) {
      if (k != i) {
        s21_copy_matrix_handle(dst, src, &ii, k, j);
      }
    }
  }
}

void s21_calc_complements_processing(matrix_t *A, matrix_t *result, int i,
                                     int j) {
  if (A && result) {
    matrix_t minor_matrix;
    s21_create_matrix(A->rows, A->columns, &minor_matrix);
    s21_copy_matrix(&minor_matrix, A, i, j);
    double det = s21_determinant_handle(minor_matrix.matrix, A->rows - 1);
    double dop = pow(-1, (i + j));
    result->matrix[i][j] = dop * det;
    s21_remove_matrix(&minor_matrix);
  }
}

void s21_calc_complements_handle(matrix_t *A, matrix_t *result) {
  if (A && result) {
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        s21_calc_complements_processing(A, result, i, j);
      }
    }
  }
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int result_code = OK;
  if (A && A->matrix && result) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      s21_calc_complements_handle(A, result);
    } else {
      result_code = CALC_ERROR;
    }
  } else {
    result_code = ERROR;
  }
  return result_code;
}

int s21_determinant(matrix_t *A, double *result) {
  int result_code = OK;
  if (A && A->matrix && result) {
    if (A->rows == A->columns) {
      double det = s21_determinant_handle(A->matrix, A->rows);
      *result = det;
    } else {
      result_code = CALC_ERROR;
    }
  } else {
    result_code = ERROR;
  }
  return result_code;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int result_code = OK;
  if (A && A->matrix && result) {
    double det = 0.0;
    result_code = s21_determinant(A, &det);
    if (det != 0 && !result_code && (A->rows == A->columns)) {
      double rev = 1.0 / det;
      if (A->rows == 1 && A->columns == 1) {
        s21_create_matrix(A->rows, A->columns, result);
        result->matrix[0][0] = rev;
      } else if (A->rows > 1 && A->columns > 1) {
        matrix_t calc_compl;
        s21_calc_complements(A, &calc_compl);

        matrix_t transpose;
        s21_transpose(&calc_compl, &transpose);
        s21_mult_number(&transpose, rev, result);

        s21_remove_matrix(&calc_compl);
        s21_remove_matrix(&transpose);
      }
    } else {
      result_code = CALC_ERROR;
    }
  } else {
    result_code = ERROR;
  }
  return result_code;
}