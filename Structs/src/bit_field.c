/*
 * bit_field.c
 *
 *  Created on: Dec 30, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/bit_field.h"

/*
 * A struct can be used to create a bit field making
 * simple bit shifting more readable.
 *
 * This syntax allocates one bit so there are three 1-bit fields.
 */
struct {
	unsigned int first : 1;
	unsigned int second : 1;
	unsigned int third : 1;
} flags;

void print_bits(int bits);

/***********************************************************************
 * NAME:		test_bit_field()
 *
 * DESCRIPTION:	Runs various tests using a struct as a bit field.
 *
 */
void test_bit_field() {

	printf("*****  test_bit_field  *****\n");

	// Can only really set these to 0 or 1.
	// Set this flag ON.
	flags.first = 1;

	print_bits(flags.first);

	// This flag is OFF.
	print_bits(flags.second);

	// Set the third bit to on.
	flags.third = 1;

	print_bits(flags.first);
	print_bits(flags.third);
}


/***********************************************************************
 * NAME:		print_bits(int)
 *
 * DESCRIPTION:	Prints the bits in the given number.
 *
 */
void print_bits(int bits) {

	int num_bits = 4;

	// 4 bits plus one for the NUL.
	char *bit_str = (char*)malloc(sizeof(char) * (num_bits + 1));
	if (bit_str == NULL) {
		fprintf(stderr, "Unable to allocate memory!");
		return;
	}

	for (int i = 0; i < num_bits; i++) {
		char bit = (bits & (1u << i)) ? '1' : '0';

		// Make it LSB.
		bit_str[num_bits - i - 1] = bit;
	}

	bit_str[num_bits] = '\0';

	printf("Bits of %d = %s\n", bits, bit_str);

	free(bit_str);
}
