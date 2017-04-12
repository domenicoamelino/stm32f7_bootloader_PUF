#ifndef MATRIX_C
#define MATRIX_C

#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "common.h"

#include "matrix.h"

/* ================================================================================
	function definitions for matrices
================================================================================ */
matrix *create_matrix(int num_rows, int num_columns) {
	int i,j;
	matrix *m = (matrix*)malloc(sizeof(matrix));
	m->num_rows = num_rows;
	m->num_columns = num_columns;
	m->values = (int**)calloc(num_rows, sizeof(int *));

	for (i = 0; i < num_rows; i++) {
		m->values[i] = (int*)calloc(num_columns, sizeof(int));
		for (j = 0; j < num_columns; j++) {
			m->values[i][j] = 0;
		}
	}
	return m;
}

void destroy_matrix(matrix *m) {
	int i;
    if (m != NULL) {
        if (m->values != NULL) {
            for (i = 0; i < m->num_rows; i++) {
                free(m->values[i]);
                m->values[i] = NULL;
            }
            free(m->values);
            m->values = NULL;
        }
        m->num_rows = 0;
        m->num_columns = 0;
        free(m);
    }
	m = NULL;
}

void set_matrix_value(matrix *m, int value, int row, int column) {
	if (row >= 0 && row < m->num_rows && column >= 0 && column < m->num_columns) {
		m->values[row][column] = value % DEGREE;
	}
}

vector *lmultiply_vector(vector *v, matrix *m) {
	vector *result = NULL;
	int i,j,sum;

	if (v->length == m->num_rows) {
		result = create_vector(m->num_columns);
		for (i = 0; i < m->num_columns; i++) {
			sum = 0;
			for (j = 0; j < m->num_rows; j++) {
				sum += v->values[j] * m->values[j][i];
			}
			result->values[i] = sum % DEGREE;
		}
	}
 
	return result;
}

void print_matrix(matrix *m) {
	int i,j;
    if (m == NULL) {
        //printf("null\n");
    } else {
        for (i = 0; i < m->num_rows; i++) {
            for (j = 0; j < m->num_columns; j++) {
          //      printf("%d ", m->values[i][j]);
            }
            //printf("\n");
        }
        //printf("\n");
    }

}
#endif
