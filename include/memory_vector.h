//
//  memory_vector.h
//  rm
//
//  Created by Mario Barbareschi on 12/10/15.
//  Copyright (c) 2015 Mario Barbareschi. All rights reserved.
//

#ifndef __rm__memory_vector__
#define __rm__memory_vector__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct memory_vector {
    uint8_t *values;
    int length;
    int byteLength;
};

typedef struct memory_vector memory_vector;

int getIntValue(memory_vector* memory, int position);
void writeBitValue(memory_vector* memory, int value, int position);
memory_vector* createMemoryVector(int length);

#ifndef STM32F4xx
void hexToMemoryVector(char* string, int length, memory_vector* memory);
void printMemoryVector(memory_vector *v);
#endif

#endif /* defined(__rm__memory_vector__) */
