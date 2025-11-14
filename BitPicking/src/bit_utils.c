/*
 * bit_utils.c
 *
 *  Created on: Nov 9, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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
	/*
	 * With, num_bits = num_bits > 0 ? num_bits : sizeof(int);,
	 * should num_bits <= 0, the number of bits used is the number
	 * s of bytes of an int.
	 * ** Which is why use * CHAR_BIT
	 * ** But also want to check for upper bound!!
	 */
	num_bits = num_bits > 0 ? num_bits : sizeof(int) * CHAR_BIT;

	// Allocate enough memory for the number of bits including room for NULL.
	char* buf = (char*)malloc(num_bits + 1);

	if (!buf) {
		printf("\nMemory allocation failed !\n");
		return NULL;
	}

	buf[0] = '\0';   // OR: *buf = 0;

	for (int i = 0; i < num_bits; i++) {
		/*
		 * When i = 31 or whatever the bit width of int minus 1, sifting by that much or more is UB.
		 * Consider using unsigned math 1u << i. Note this is still UB when i > 32.
		 */
		char bit = (num & (1u << i)) ? '1' : '0';;

		// Here we want to but the least significant bit at the other end of
		// the array.  This is effectively swapping the array positions.
		buf[num_bits - 1 - i] = bit;
	}

	// Remember to append the NULL char.
	buf[num_bits] = '\0';

	return buf;


//	// XXX: This no worky worky...
//	// When having multiple malloc'd string it eventually
//	// get garbage. Answers from SO inline below.
//
//	// SO Comment:
//	// s/malloc/calloc - strcat scans its left operand until
//	// it finds a null terminator, and malloc returns uninitialized
//	// memory, so it can easily overrun the buffer.
//
//	// 1) Probably want to range-check num_bits for greater than 30 since
//	// 		1 << i is UB when i == 31.
//	// 2) Add in * CHAR_BIT when defaulting num_bits:
//			num_bits = num_bits > 0 ? num_bits : sizeof(int) * CHAR_BIT;
//
//	/*
//	 * Unneeded code
//	 * With char* buf = (char*)malloc((num_bits + 1) * sizeof(char));,
//	 * both the cast and * sizeof(char) serve no purpose.
//	 *
//	 * Better as char* buf = malloc(num_bits + 1u);
//	 * 1u avoid UB and works better with pathological input when num_bits == INT_MAX.
//	 * Of course any num_bits > sizeof(int)*CHAR_BIT deserves detection to prevent
//	 * later UB in the shifting.
//	 *
//	 * So use:
//	 * 		char* buf = malloc(num_bits + 1u);
//	 *
//   * With C23, we could use to handle many cases.
//   * snprintf(buf, num_bits + 1, "%0*b", num_bits,
//   *              (unsigned) (num & ((1llu << num_bits) - 1));
//	 */

	/*
		On the first call, strcat(buf, bit); is undefined behavior (UB) as pointer
		buf does not yet point to a string. In C, a string is a sequence of
		characters up to an including the null character. After the malloc() call,
		the memory pointed to by buf is not yet assigned.

		Assign buf[0] first to '\0'.
	*/

//	char* buf = (char*)malloc((num_bits + 1) * sizeof(char));
//
//	if (!buf) {
//		// Use stderr instead.
//		printf("\nMemory allocation failed !\n");
//		return NULL;
//	}
//
//	// Start at least significant bit.
//	// This is: https://wiki.c2.com/?ShlemielThePainter
//	for (int i = num_bits - 1; i >= 0; i--) {
//		/*
//		 * When i = 31 or whatever the bit width of int minus 1, sifting by that much or more is UB.
//		 * Consider using unsigned math 1u << i. Note this is still UB when i > 32.
//		 */
//		char* bit = (num & (1 << i)) ? "1" : "0";
//
////		strncat(buf, bit, 1);
//		strcat(buf, bit);
//	}
////	strncat(buf, "\0", 1);
////	strcat(buf, "\n");
//
//	return buf;
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
 * NAME:		test_get_bit_loop()
 *
 * DESCRIPTION:	Tests the get_bit_str function looping over 0-15 (0000 - 1111).
 *
 * INPUTS:		None.
 *
 * OUTPUTS:		None.
 */
void test_get_bit_loop() {
	for (int i = 0; i < 16; i++) {
		char* bits = get_bit_str(i, 4);

		printf("i = %d bits: %s\n", i, bits);

		free(bits);
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
