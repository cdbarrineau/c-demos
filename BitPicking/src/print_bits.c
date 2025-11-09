/*
 * print_bits.c
 *
 *  Created on: Nov 9, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/print_bits.h"
#include "../include/bit_utils.h"

#define BANNER "\n***********  %s  ***********\n"


/***********************************************************************
 * NAME:		print_int_bits(int)
 *
 * DESCRIPTION:	Prints each bit in the specified number on a separate line.
 *
 * INPUTS:		num The number to get the bit representation.
 *
 */
void print_int_bits(int num) {

	printf(BANNER, "print_int_bits(num)");

	int len = sizeof(int);
	char* buf = (char*)malloc(len);

	for (int i = 0; i < len; i++) {
		int mask = 1 << i;

		char* mask_str = get_bit_str(mask, 4);

		printf("Mask of 1 << %d: %s (decimal = %d) ( 1 * 2^%d = %d)\n", i, mask_str, mask, i, mask);

		free(mask_str);

		char* bit = (num & (1 << i)) ? "1" : "0";

		strncat(buf, bit, 1);
	}
	strncat(buf, "\0", 1);

	printf("%d: %s\n", num, buf);

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
 * NAME:		set_bit(int, int)
 *
 * DESCRIPTION:	Sets the bit at position pos in the specified number.
 *
 * INPUTS:		pos The bit position in num to set.
 *              num The number to get the bit representation.
 *
 */
void set_bit(int pos, int num) {
	printf(BANNER, "set_bit(pos, num)");

	printf("Setting bit in position %d in number %d\n", pos, num);

	// For num, here == 1 so we get 0001.
	char* num_bits = get_bit_str(num, 4);
	printf("num %d in binary: %s\n", num, num_bits);
	free(num_bits);

	// For result we're shifting 1 n = 3 places (n + 1) as we get 1000
	char* shift = get_bit_str(1 << pos, 4);
	printf("pos %d in binary (pos + 1): %s\n", pos, shift);
	free(shift);

	// Here we're taking the number 1 (0001) and setting the pos (3) + 1 bit so
	// we get 1001 which in decimal is 9.
	int result = num | (1 << pos);

	printf("result = num | (1 << pos)\n");

	char* result_bits = get_bit_str(result, 4);
	printf("result = (%d | (1 << %d)) => result = %d in binary: %s", num, pos, result, result_bits);
	free(result_bits);
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
