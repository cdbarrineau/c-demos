/*
 * clear_bit_test.c
 *
 *  Created on: Nov 11, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/bit_utils.h"
#include "../include/clear_bit_test.h"


/***********************************************************************
 * NAME:		run_clear_bit_test()
 *
 * DESCRIPTION:	Runs various tests on clearing a bit, a.k.a. setting a
 * 				bit to zero in a specified bit position (zero based).
 *
 * INPUTS:		None.
 *
 * OUTPUTS:		None.
 */
void run_clear_bit_test() {

	printf(BANNER, "run_clear_bit_test()");

	/*
	 * This prints the following:
	 *
	 * mask: 1110 of bit to unset: 0
	 * num to unset bit: 0001 - value (num & mask) after unset of bit: 0000
	 *
	 * mask: 1101 of bit to unset: 1
	 * num to unset bit: 0010 - value (num & mask) after unset of bit: 0000
	 *
	 */

	int bit_pos_to_clear = 0;
	int num = 1;

	// To clear a bit we need to create a mask where we shift
	// a 0001 by n where n is the n'th bit to unset.
	char* bit_to_clear_str = get_bit_str(bit_pos_to_clear, 4);
	printf("bit position to clear: %d  (%s)\n", bit_pos_to_clear, bit_to_clear_str);

	int shifted = 1 << bit_pos_to_clear;
	char* shifted_str = get_bit_str(shifted, 4);
	printf("Shifted %s (1 << bit_pos_to_clear)\n", shifted_str);

	int mask = ~(1 << bit_pos_to_clear);
	char* mask_str = get_bit_str(mask, 4);
	printf("mask: %s (~(1 << bit_pos_to_clear))\n", mask_str);

	int value = num & mask;
	char* num_str = get_bit_str(num, 4);
	char* value_str = get_bit_str(value, 4);

	printf("num %s : (%d) \n", num_str, num);
	printf("value %s (num & mask) \n", value_str);

	free(bit_to_clear_str);
	free(shifted_str);
	free(mask_str);
	free(num_str);
	free(value_str);

	printf("\n");

	// This will result in 0001.
	// Why not 0010???
	bit_pos_to_clear = 1;
	num = 1;

	bit_to_clear_str = get_bit_str(bit_pos_to_clear, 4);
	printf("bit position to clear: %d  (%s)\n", bit_pos_to_clear, bit_to_clear_str);

	shifted = 1 << bit_pos_to_clear;
	shifted_str = get_bit_str(shifted, 4);
	printf("Shifted %s (1 << bit_pos_to_clear)\n", shifted_str);

	mask = ~(1 << bit_pos_to_clear);
	mask_str = get_bit_str(mask, 4);
	printf("mask: %s (~(1 << bit_pos_to_clear))\n", mask_str);

	value = num & mask;
	num_str = get_bit_str(num, 4);
	value_str = get_bit_str(value, 4);

	printf("num %s : (%d) \n", num_str, num);
	printf("value %s (num & mask) Note how the bit in pos 0 remains 1\n", value_str);

	free(bit_to_clear_str);
	free(shifted_str);
	free(mask_str);
	free(num_str);
	free(value_str);

	printf("\n");

	bit_pos_to_clear = 1;
	num = 2; // (0010)

	bit_to_clear_str = get_bit_str(bit_pos_to_clear, 4);
	printf("bit position to clear: %d  (%s)\n", bit_pos_to_clear, bit_to_clear_str);

	shifted = 1 << bit_pos_to_clear;
	shifted_str = get_bit_str(shifted, 4);
	printf("Shifted %s (1 << bit_pos_to_clear)\n", shifted_str);

	mask = ~(1 << bit_pos_to_clear);
	mask_str = get_bit_str(mask, 4);
	printf("mask: %s (~(1 << bit_pos_to_clear))\n", mask_str);

	value = num & mask;
	num_str = get_bit_str(num, 4);
	value_str = get_bit_str(value, 4);

	printf("num %s : (%d) \n", num_str, num);
	printf("value %s (num & mask) Note how the bit in pos 1 is cleared\n", value_str);

	free(bit_to_clear_str);
	free(shifted_str);
	free(mask_str);
	free(num_str);
	free(value_str);
}
