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

	printf("Remember bit position is 0-based!\n\n");

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
	int shifted = 1 << bit_pos_to_clear;
	int mask = ~(1 << bit_pos_to_clear);
	int value = num & mask;

	// To clear a bit we need to create a mask where we shift
	// a 0001 by n where n is the n'th bit to unset.
	char* bit_to_clear_str = get_bit_str(bit_pos_to_clear, 4);
	printf("bit position to clear: %d\t\t%s\n", bit_pos_to_clear, bit_to_clear_str);

	char* shifted_str = get_bit_str(shifted, 4);
	printf("Shifted: (1 << bit_pos_to_clear)\t%s\n", shifted_str);

	char* mask_str = get_bit_str(mask, 4);
	printf("mask: (~(1 << bit_pos_to_clear))\t%s\n", mask_str);

	char* num_str = get_bit_str(num, 4);
	printf("num: (%d) \t\t\t\t%s\n", num, num_str);

	char* value_str = get_bit_str(value, 4);
	printf("value: (num & mask) \t\t\t%s\n", value_str);

	free(bit_to_clear_str);
	free(shifted_str);
	free(mask_str);
	free(num_str);
	free(value_str);

	printf("\n");

	// This will not touch the 0th bit so value is still 0001
	bit_pos_to_clear = 1;
	num = 1;
	shifted = 1 << bit_pos_to_clear;
	mask = ~(1 << bit_pos_to_clear);
	value = num & mask;

	bit_to_clear_str = get_bit_str(bit_pos_to_clear, 4);
	printf("bit position to clear: %d\t\t%s\n", bit_pos_to_clear, bit_to_clear_str);

	shifted_str = get_bit_str(shifted, 4);
	printf("Shifted: (1 << bit_pos_to_clear)\t%s\n", shifted_str);

	mask_str = get_bit_str(mask, 4);
	printf("mask: (~(1 << bit_pos_to_clear))\t%s\n", mask_str);

	num_str = get_bit_str(num, 4);
	printf("num: (%d) \t\t\t\t%s\n", num, num_str);

	value_str = get_bit_str(value, 4);
	printf("value: (num & mask) \t\t\t%s\n", value_str);

	free(bit_to_clear_str);
	free(shifted_str);
	free(mask_str);
	free(num_str);
	free(value_str);

	printf("\n");

	bit_pos_to_clear = 1;
	num = 2; // (0010)
	shifted = 1 << bit_pos_to_clear;
	mask = ~(1 << bit_pos_to_clear);
	value = num & mask;

	bit_to_clear_str = get_bit_str(bit_pos_to_clear, 4);
	printf("bit position to clear: %d\t\t%s\n", bit_pos_to_clear, bit_to_clear_str);

	shifted_str = get_bit_str(shifted, 4);
	printf("Shifted: (1 << bit_pos_to_clear)\t%s\n", shifted_str);

	mask_str = get_bit_str(mask, 4);
	printf("mask: (~(1 << bit_pos_to_clear))\t%s\n", mask_str);

	num_str = get_bit_str(num, 4);
	printf("num: (%d) \t\t\t\t%s\n", num, num_str);

	value_str = get_bit_str(value, 4);
	printf("value: (num & mask) \t\t\t%s\n", value_str);

	free(bit_to_clear_str);
	free(shifted_str);
	free(mask_str);
	free(num_str);
	free(value_str);

	printf("\n");

	bit_pos_to_clear = 2;
	num = 4;
	shifted = 1 << bit_pos_to_clear;
	mask = ~(1 << bit_pos_to_clear);
	value = num & mask;

	bit_to_clear_str = get_bit_str(bit_pos_to_clear, 4);
	printf("bit position to clear: %d\t\t%s\n", bit_pos_to_clear, bit_to_clear_str);

	shifted_str = get_bit_str(shifted, 4);
	printf("Shifted: (1 << bit_pos_to_clear)\t%s\n", shifted_str);

	mask_str = get_bit_str(mask, 4);
	printf("mask: (~(1 << bit_pos_to_clear))\t%s\n", mask_str);

	num_str = get_bit_str(num, 4);
	printf("num: (%d) \t\t\t\t%s\n", num, num_str);

	value_str = get_bit_str(value, 4);
	printf("value: (num & mask) \t\t\t%s\n", value_str);

	free(bit_to_clear_str);
	free(shifted_str);
	free(mask_str);
	free(num_str);
	free(value_str);
}
