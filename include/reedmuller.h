#ifndef REEDMULLER_H
#define REEDMULLER_H

#include "vector.h"
#include "matrix.h"
#include "monomial.h"
#include "list.h"
#include "memory_vector.h"

struct generating_monomial {
	int last_position;
	int num_bits;
	monomial *mon;
};

typedef struct generating_monomial generating_monomial;

/* ================================================================================
 function prototypes for reed-muller functions
 ================================================================================ */
vector *psi_monomial(int, monomial *);
vector *psi_x(int,int);
list *create_gmonomials(generating_monomial *, int, int);
list *generate_reduced_monomials(int, int);
list *group_reduced_monomials(list *, int, int);

matrix *create_generator_matrix(int, list *);
vector **generate_characteristic_vectors(monomial *, int);
int majority(vector *, vector **, int);

memory_vector *encode(memory_vector* v,int r,int m);
memory_vector *decode(memory_vector*,int,int);

#endif