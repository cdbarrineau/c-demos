/*
 * main.c
 *
 *  Created on: Nov 6, 2025
 *      Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/bit_utils.h"
#include "include/get_bit_test.h"
//#include "include/print_bits.h"


int main() {


	run_get_bit_test();





	// Set the second bit of 0.
//	int set = num | (1 << pos);
//	char* bit_str2 = get_bit_str(set, 4);
//	printf("Set bit of %d bit at position %d is set %d: %s", num, pos, set, bit_str2);
//	free(bit_str2);



//	print_int_bits(2);

//	// Set the bit in position 3 to 1 which yields 1001 (9):
//	// result = num (1) | (1 << pos (3))
//	set_bit(3, 1);
//	printf("\n\n");
//
//	// Prints out the bits from 0-15.
//	print_bits();
//
//	bit_mask(5, 3);
//	printf("\n\n");
//
//	bit_mask(15, 3);
//	printf("\n\n");
//
//	// Sets each bit in a new variable to 1 for each i in the loop.
//	set_bits_loop();
//	printf("\n\n");
//
//	// Reuses the same value and sets the nth bit to 1 in a loop.
//	shift_bits_loop();
//	printf("\n\n");
//
//	// This is 0001 because 2^0 = 1
//	int i = 1 << 0;
//	char* str = get_bit_str(i, 4);
//	printf("Remember 2^ 0 == 1 so: 1 << 0 = %s\n\n", str);
//	free(str);

	return 0;
}

