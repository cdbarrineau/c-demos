/*
 * bit_field.c
 *
 *  Created on: Dec 20, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/bit_field.h"

// This form allows the access of the members without
// a separate object.  For instance:
// flags.first
// flags.second
// etc.
struct {
	unsigned int first : 1;
	unsigned int second : 1;
	unsigned int third : 1;
} flags;

void print_bits(unsigned int num);

/***********************************************************************
 * NAME:		test_bit_field()
 *
 * DESCRIPTION:	Tests a bit field with a struct for the bits to twiddle.
 *
 */
void test_bit_field() {

	printf("\n*****  test_bit_field  *****\n");

	// Set the first bit on.
	flags.first = 1;

	print_bits(flags.first);

//	printf("flags.first: %d\n", flags.first);

}


void print_bits(unsigned int num) {

	// Make a bit string 4 bits long.
	int len = 4;

	char *bits = malloc(sizeof(char) * (len + 1));
	if (bits == NULL) {
		fprintf(stderr, "Unable to allocate memory!");
		return;
	}

	for (int i = 0; i < len; i++) {
		char bit = (num & (1u << i)) ? '1' : '0';

		// Want least significant bit placement.
		bits[len - i - 1] = bit;
	}

	bits[len] = '\0';

	printf("Bits of %d : %s\n", num, bits);

	free(bits);
}
