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
 *
 */

char* get_bit_str(int mask) {
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

		char* mask_str = get_bit_str(mask);

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

void bit_mask(int value, int num_to_shift) {

	char* num_to_shift_bits = get_bit_str(num_to_shift);
	printf("Num to shift: %d (binary): %s\n", num_to_shift, num_to_shift_bits);
	free(num_to_shift_bits);

	int mask = 1 << num_to_shift;
	char* mask_bits = get_bit_str(mask);
	printf("Mask of (1 << %d): %s\n", num_to_shift, mask_bits);
	free(mask_bits);

	char* value_bits = get_bit_str(value);
	printf("Value bits of %d: %s\n", value, value_bits);
	free(value_bits);

	int result = value & mask;

	char* result_bits = get_bit_str(result);
	printf("Result: %s\n", result_bits);
	free(result_bits);

}

int main() {

	// printf("num to shift: %d value to mask: %d\n", 3, 5);
	bit_mask(5, 3);

//	print_int_bits(-1);
//
//	print_int_bits(-2);
//
//	print_int_bits(0);

//	print_int_bits(1);

//	print_int_bits(2);
//
//	print_int_bits(3);


	return 0;
}

