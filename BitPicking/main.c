/*
 * main.c
 *
 *  Created on: Nov 6, 2025
 *      Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * IMPORTANT: Shifting by a negative number or a number greater than bit
 * 			  width is undefined!
 *
 * 			  Also, all vacant bits are filled in by 0.
 *
 * Left shift effectively multiplies a number by 2.
 *
 * *** a << n === a * (2^n)
 *
 * *** 1 << 0 = 1 because x^1 == 1 ***
 *
 * 	This example can see that multiplying by 2 not only gives 10 but also shifts
 *	the bits by one to the left:
 * 		5 (0101) : 5 << 1 = 10 (1010)  or 5 * (2^1)
 *
 * 	Another example, shift bit in 5 three places:
 * 		5 (0101) << 3 = 40 (101000) or 5 * (2^3)
 *
 *
 * Right shift effectively multiplies a divides by 2.
 *	Example: 20 (10100) 20 >> 2 = 5 (1010)
 *
 *
 *
 *
 * result = value << positions:
 * 		r = 1 << 3 Shifts the bits in 1 by 3 positions.
 *		1 << 3 = 1000  Creates a mask with the 4th bit set.
 *
 *
 */

char* get_mask(int mask) {
	int len = sizeof(int);
	char* buf = (char*)malloc(len);

	// Start at least significant bit.
	for (int i = len - 1; i >= 0; i--) {
		char* bit = (mask & (1 << i)) ? "1" : "0";

		strncat(buf, bit, 1);
	}
	strncat(buf, "\0", 1);

	return buf;
}

/*
 * Prints the bits in the passed in number.
 *
 */
void print_int_bits(int num) {
	int len = sizeof(int);
	char* buf = (char*)malloc(len);

	// Start at least significant bit.
	for (int i = len - 1; i >= 0; i--) {
		int mask = 1 << i;

		char* mask_str = get_mask(mask);

		printf("Mask of 1 << %d: %s (decimal = %d) ( 1 * 2^%d = %d)\n", i, mask_str, mask, i, mask);


		free(mask_str);
//		int mask = 1 << i;
//		int and = num & mask;
//
//		printf("Mask: %d\tAnd: %d\n", mask, and);

		char* bit = (num & (1 << i)) ? "1" : "0";

		strncat(buf, bit, 1);
	}
	strncat(buf, "\0", 1);

	printf("%d: %s\n", num, buf);

	free(buf);
}

int main() {

//	print_int_bits(-1);
//
//	print_int_bits(-2);
//
//	print_int_bits(0);

	print_int_bits(1);

//	print_int_bits(2);
//
//	print_int_bits(3);


	return 0;
}

