/*
 * PUF_extraction.c
 *
 *  Created on: 09 ott 2015
 *      Author: mariobarbareschi
 */

#include "PUF_extraction.h"

int extractPUFfromMemory(uint8_t* memory, uint8_t* helper_data, uint16_t length, uint8_t* key){
	uint16_t i;
	memory_vector *original, *decoded, *codeword;
	original=createMemoryVector(length);
	original->values = (uint8_t*)memory;
	for (i = 0; i < original->byteLength; i++) {
		original->values[i] ^= helper_data[i];
	}

	decoded = decode(original, RM_R, RM_M);
	if(decoded == NULL){
		return 1;
	}

	codeword = encode(decoded, RM_R, RM_M);

/*	unsigned int errors = 0;
	for(i=0; i< original->byteLength; i++){
		errors += __builtin_popcount(original->values[i] ^ codeword->values[i]);
	}*/
	for (i = 0; i < original->byteLength; i++) {
		codeword->values[i] ^= helper_data[i];
		}

	for(i = 0; i<original->byteLength; i++)
	{
		key[i] = codeword->values[i];
	}

	SpongentHash(codeword->values, length, key);

	return 0;

}
