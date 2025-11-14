/*
 * print_bits.c
 *
 *  Created on: Nov 9, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "../include/print_bits.h"
#include "../include/bit_utils.h"


/***********************************************************************
 * NAME:		print_int_bits(int)
 *
 * DESCRIPTION:	Prints each bit in the specified number on a separate line
 *              for the width of an int (usually 4 bytes).
 *
 * INPUTS:		num The number to get the bit representation.
 *
 */
void print_int_bits(int num) {

	printf(BANNER, "print_int_bits(num)");

	// Only want to print the first 4 bits of num
	int len = sizeof(int);
	char* buf = (char*)malloc(len);
	buf[0] = '\n'; // OR: *buf = 0

	for (int i = 0; i < len; i++) {
		int shifted = 1 << i;

		char* shifted_str = get_bit_str(shifted, 4);

		printf("Shift of 1 << %d = %s (decimal = %d) ( 1 * 2^%d = %d)\n", i, shifted_str, shifted, i, shifted);

		free(shifted_str);

		char bit = (num & (1 << i)) ? '1' : '0';

		// Here we want to but the least significant bit at the other end of
		// the array.  This is effectively swapping the array positions.
		buf[len - 1 - i] = bit;
	}
	buf[len] = '\0';

	printf("Bits of %d: %s\n", num, buf);

	free(buf);
}

/***********************************************************************
 * NAME:		print_bits()
 *
 * DESCRIPTION:	Prints the first 15 bits in a byte.
 */
void print_bits() {

	printf(BANNER, "print_bits()");

	// Print out 0 - 15 (0000 - 1111)
	for (int i = 0; i < 16; i++) {
		char* bits = get_bit_str(i, 4);

		printf("Bits in %d is %s\n", i, bits);

		free(bits);
	}
}

/****************************************************************************
 * NAME:		set_bits_loop()
 *
 * DESCRIPTION: Loops from 0 - 4 and sets the i'th bit in the loop and prints
 *              the result.
 *
 *              This is print out a bit string with 1 set to the index + 1 place so:
 *
 * 				0: 0001
 * 				1: 0010
 * 				2: 0100
 * 				3: 1000
 *
 */
void set_bits_loop() {

	printf(BANNER, "set_bits_loop()");

	for (int i = 0; i < 4; i++) {
		int shifted_bit = 1 << i;

		char* bits = get_bit_str(shifted_bit, 4);

		printf("Setting bit %d to: %s\n", i, bits);

		free(bits);
	}
}


/****************************************************************************
 * NAME:		shift_bits_loop()
 *
 * DESCRIPTION: Loops from 0 - 4 and sets the i'th bit in the loop and
 * 				prints the result.  This reuses the shifted value so that
 * 				in the end, each bit will be set.
 *
 * 				This is print out a bit string with 1 set to the index + 1 place so:
 *
 * 				0: 0001
 * 				1: 0011
 *	 			2: 0111
 * 				3: 1111
 *
 */
void shift_bits_loop() {

	printf(BANNER, "shift_bits_loop()");

	int value = 0;
	for (int i = 0; i < 4; i++) {
		value += 1 << i;

		char* bits = get_bit_str(value, 4);

		printf("Setting bit %d to: %s\n", i, bits);

		free(bits);
	}
}


/***********************************************************************
 * NAME:		bit_mask(int, int)
 *
 * DESCRIPTION:	???
 *
 * INPUTS:		value The value to mask.
 *              num_to_shift The number of bit positions to shift.
 *
 */
void bit_mask(int value, int num_to_shift) {

	printf(BANNER, "bit_mask(value, num_to_shift)");

	char* num_to_shift_bits = get_bit_str(num_to_shift, 4);
	printf("Num to shift: %d\t(binary): %s\n", num_to_shift, num_to_shift_bits);
	free(num_to_shift_bits);

	char* value_bits = get_bit_str(value, 4);
	printf("Value: %d\t(binary): %s\n", value, value_bits);
	free(value_bits);

	int mask = 1 << num_to_shift;
	char* mask_bits = get_bit_str(mask, 4);
	printf("Mask of (1 << %d): %s (decimal: %d)\n", num_to_shift, mask_bits, mask);
	free(mask_bits);

	char* is_bit_set = (value & mask) ? "Yes": "No";
	printf("Is bit set at position %d? %s\n", num_to_shift, is_bit_set);

	char* result_bits = get_bit_str(value & mask, 4);
	printf("(%d & %d): %s\n", value, mask, result_bits);
	free(result_bits);
}
