/*
 * types.c
 *
 *  Created on: 10/giu/2014
 *      Author: HyperText
 */

#include "types.h"

/***
 *      ____   _    _  ______  ______  ______  _____
 *     |  _ \ | |  | ||  ____||  ____||  ____||  __ \
 *     | |_) || |  | || |__   | |__   | |__   | |__) |
 *     |  _ < | |  | ||  __|  |  __|  |  __|  |  _  /
 *     | |_) || |__| || |     | |     | |____ | | \ \
 *     |____/  \____/ |_|     |_|     |______||_|  \_\
 *
 *
 */

/* Works also as reset */
void initBuffer(Buffer * buffer) {
	buffer->head = 0;
	buffer->tail = 0;
	buffer->count = 0;
}

uint8_t isBufferFull(Buffer *buffer) {
	if (buffer->count == BUFFER_SIZE) {
		return 1;
	}

	return 0;
}

uint8_t isBufferEmpty(Buffer * buffer) {
	if (buffer->count == 0) {
		return 1;
	}

	return 0;
}

/* Before writing, one has to check if Buffer isn't full */
void writeBuffer(Buffer *buffer, uint8_t element) {
#ifdef BUFFER_PROTECTION
	/* for protection of "tail" in case there is no pre-write control and one writes into the full buffer */
	if (isBufferFull(buffer) == 1) {
		return;
	}
#endif

	buffer->content[buffer->tail] = element;
	buffer->count = buffer->count + 1;

	if (buffer->tail == BUFFER_SIZE-1) {
		buffer->tail = 0;
	} else {
		buffer->tail = buffer->tail + 1;
	}
}

/* Before reading, one has to check if Buffer isn't empty */
uint8_t readBuffer(Buffer * buffer) {
#ifdef BUFFER_PROTECTION
	/* for protection of "head" in case there is no pre-read control and one reads from the empty buffer */
	if (isBufferEmpty(buffer) == 1) {
		return 0;
	}
#endif

	uint8_t temp = buffer->content[buffer->head];

	if (buffer->head == BUFFER_SIZE-1) {
		buffer->head = 0;
	} else {
		buffer->head = buffer->head + 1;
	}

	buffer->count = buffer->count - 1;

	return temp;
}

/* Before reading, one has to check if Buffer isn't empty */
uint64_t readBuffer8(Buffer * buffer) {
#ifdef BUFFER_PROTECTION
	/* for protection of "head" in case there is no pre-read control and one reads from the empty buffer */
	if (isBufferEmpty(buffer) == 1) {
		return 0;
	}
#endif

	uint64_t temp = 0;
	uint8_t * p = (uint8_t *) &temp;
	uint8_t i;

	for (i = 0; i < 8; i++) {
		p[i] = readBuffer(buffer);
	}
//
//	= (uint64_t)
//			  ((uint64_t) 0x00000000000000FF & (uint64_t) buffer->content[buffer->head])
//			| ((uint64_t) 0x000000000000FF00 & ((uint64_t) buffer->content[buffer->head + 1] << 8))
//			| ((uint64_t) 0x0000000000FF0000 & ((uint64_t) buffer->content[buffer->head + 2] << 16))
//			| ((uint64_t) 0x00000000FF000000 & ((uint64_t) buffer->content[buffer->head + 3] << 24))
//			| ((uint64_t) 0x000000FF00000000 & ((uint64_t) buffer->content[buffer->head + 4] << 32))
//			| ((uint64_t) 0x0000FF0000000000 & ((uint64_t) buffer->content[buffer->head + 5] << 40))
//			| ((uint64_t) 0x00FF000000000000 & ((uint64_t) buffer->content[buffer->head + 6] << 48))
//			| ((uint64_t) 0xFF00000000000000 & ((uint64_t) buffer->content[buffer->head + 7] << 56));
//
//	if (buffer->head + 8 < BUFFER_SIZE) {
//		buffer->head = buffer->head + 8;
//	} else if (buffer->head + 8 == BUFFER_SIZE) {
//		buffer->head = 0;
//	} else if (buffer->head + 8 >= BUFFER_SIZE) { //  basta anche solo ELSE (8 byte risparmiati)?
//		buffer->head = buffer->head % BUFFER_SIZE;
//	}
//
//	buffer->count = buffer->count - 8;

	return temp;
}

