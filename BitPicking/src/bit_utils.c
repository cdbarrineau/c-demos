/*
 * bit_utils.c
 *
 *  Created on: Nov 9, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/bit_utils.h"

/***********************************************************************
 * NAME:		get_bit_str(int, int)
 *
 * DESCRIPTION:	Gets a dynamically allocated pointer to a string array that
 * 				contains the bit representation of the specified integer
 * 				as a "num_bits" byte value.
 *
 * WARNING:		Caller is responsible for freeing returned char*.
 *
 * INPUTS:		num The number to get the bit representation.
 * 				num_bits The number of bits to put in the string output.
 * 				Usually 4 or 8.
 *
 * OUTPUTS:		char* Returns the heap-allocated string representation of the
 * 				bits in num.
 */
char* get_bit_str(int num, int num_bits) {
	num_bits = num_bits > 0 ? num_bits : sizeof(int);

	// Allocate enough memory for the number of bits including room for NULL.
	char* buf = (char*)malloc((num_bits + 1));

	if (!buf) {
		printf("\nMemory allocation failed !\n");
		return "";
	}

	// Start at least significant bit.
	for (int i = num_bits - 1; i >= 0; i--) {
		char bit = (num & (1 << i)) ? '1' : '0';

		buf[i] = bit;
	}

	// Remember to append the NULL char.
	buf[num_bits] = '\0';

	return buf;

//	// XXX: This no worky worky...
//	// When having multiple malloc'd string it eventually
//	// get garbage.  Not too sure why...
//
//	num_bits = num_bits > 0 ? num_bits : sizeof(int);
//
//	char* buf = (char*)malloc((num_bits + 1) * sizeof(char));
//
//	if (!buf) {
//		printf("\nMemory allocation failed !\n");
//		return "";
//	}
//
//	// Start at least significant bit.
//	for (int i = num_bits - 1; i >= 0; i--) {
//		char* bit = (num & (1 << i)) ? "1" : "0";
//
////		strncat(buf, bit, 1);
//		strcat(buf, bit);
//	}
////	strncat(buf, "\0", 1);
////	strcat(buf, "\n");

	return buf;
}

/***********************************************************************
 * NAME:		print_bit_set(int, int, int, char*)
 *
 * DESCRIPTION:	Prints out if a bit is set.
 *
 * INPUTS:		pos The bit position.
 *              num The number that contains the bits.
 *              is_bit_set false if not set, true if set.
 * 				num_bit_str The string representation of the number in bits.
 *
 * OUTPUTS:		None.
 */
void print_bit_set(int pos, int num, bool is_bit_set, char* num_bit_str) {
	if (is_bit_set) {
		printf("Bit at position (index) %d of num %d is set.  Num: %s\n", pos, num, num_bit_str);
	}
	else {
		printf("Bit at position (index) %d of num %d is NOT set.  Num: %s\n", pos, num, num_bit_str);
	}
}

/***********************************************************************
 * NAME:		test_get_bit_str()
 *
 * DESCRIPTION:	Tests the get_bit_str function.
 *
 * INPUTS:		None.
 *
 * OUTPUTS:		None.
 */
void test_get_bit_str() {
	char* c = get_bit_str(0, 4);
	printf("c (0) %s\n", c);

	char* d = get_bit_str(1, 4);
	printf("d (1) %s\n", d);

	free(c);
	free(d);

	c = get_bit_str(1, 4);
	printf("c (1) %s\n", c);

	d = get_bit_str(2, 4);
	printf("d (2) %s\n", d);

	free(c);
	free(d);
}
