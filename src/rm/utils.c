/*
 *  utils.c
 *  
 *
 *  Created by Edgar Felizmenio on 5/3/13.
 *  Copyright 2013 University of the Philippines. All rights reserved.
 *
 */
#ifndef UTILS_C
#define UTILS_C

#include <stdlib.h>
#include "common.h"
#include "vector.h"

#include "utils.h"

vector *to_int_vector(char *s, int length) {
	int i;
	vector *v = create_vector(length);

	for (i = 0; i < length || s[i] != '\0'; i++) {
		v->values[i] = (int)s[i] - 0x30;
	}

	return v;
}

int is_bin_string(char *s, int length) {
    int i;
    for (i = 0; i < length || s[i] != '\0'; i++) {
        if (s[i] != '0' && s[i] != '1') {
            return 0;
        }
    }
    return 1;
}

#endif