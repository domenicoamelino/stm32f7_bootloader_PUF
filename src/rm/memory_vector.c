//
//  memory_vector.c
//  rm
//
//  Created by Mario Barbareschi on 12/10/15.
//  Copyright (c) 2015 Mario Barbareschi. All rights reserved.
//

#include "memory_vector.h"

int getIntValue(memory_vector* memory, int position){
    if(position > memory->length){
        return -1;
    }else{
        uint8_t cell = memory->values[position/8];
        if(cell & (((uint8_t)0x80)>>position%8)){
            return 1;
        }else{
            return 0;
        }
    }
}

void writeBitValue(memory_vector* memory, int value, int position){
    if(position < memory->length){
        if (value) { // if == 1 then changes the bit value, otherwise does nothing because it's already zero
            memory->values[position/8] |= (((uint8_t)0x80)>>position%8);
        }
    }
}

memory_vector* createMemoryVector(int length){
    memory_vector* vector = (memory_vector*)malloc(sizeof(memory_vector));
    int byteLength = length/8 + (length%8 ? +1 : 0);
    vector->values = (uint8_t*) malloc(sizeof(uint8_t)*byteLength);
    vector->length = length;
    vector->byteLength = byteLength;
    // initialize the vector
    int i = 0;
    for (i = 0; i < byteLength; i++) {
        vector->values[i] = 0;
    }
    
    return vector;
}

void hexToMemoryVector(char* string, int length, memory_vector* memory){
    if (length<=memory->length) {
        int i;
        for (i=0; i<=2*memory->byteLength; i+=2) {
            uint8_t val;
            sscanf(&string[i], "%02hhX", &val);
            memory->values[i/2] = val;
        }
    }
}

void printMemoryVector(memory_vector *v) {
    int i;
    printf("length: %d\t",v->length);
    for (i = 0; i < v->length; i++) {
            printf("%d",getIntValue(v, i));
    }
    printf("\n");
}