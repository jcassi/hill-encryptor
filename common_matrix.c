#include "common_matrix.h"

int matrix_init(matrix_t *self, size_t rows, size_t cols) {
	if ((self->elements = (int *)malloc(rows * cols * sizeof(int))) == NULL) {
		return -1;
	}
	self->rows = rows;
	self->cols = cols;
	return 0;
}
void matrix_uninit(matrix_t *self) {
	free(self->elements);
}

void matrix_fill_by_rows(matrix_t *self, int *array, size_t length) {
	for (int i = 0; i < self->rows; i++) {
		for (size_t j = 0; j < self->cols; j++) {
			if(i * self->cols + j < length) {
				self->elements[i * self->cols + j] = array[i * self->cols + j];
			} else {
				self->elements[i * self->cols + j] = 0;
			}
		}
	}
}

void matrix_multiply_by_array(matrix_t *self, int *array, int *result) {
	for (int i = 0; i < self->rows; ++i) {
		result[i] = 0;
		for (int j = 0; j < self->cols; ++j) {
			result[i] += self->elements[i * self->cols + j] * array[j];	
		}
	}
}
