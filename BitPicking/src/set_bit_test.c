/*
 * set_bit_test.c
 *
 *  Created on: Nov 10, 2025
 *  Author: mark2v
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/bit_utils.h"
#include "../include/set_bit_test.h"

/***********************************************************************
 * NAME:		run_set_bit_test()
 *
 * DESCRIPTION:	Runs various tests on setting a bit.
 *
 * INPUTS:		None.
 *
 * OUTPUTS:		None.
 */
void run_set_bit_test() {

	printf(BANNER, "run_set_bit_test()");

	int num = 0;
	int pos = 0;

	// Set the 0th bit of zero to 1.
	int value = num | (1 << pos);

	char* bit_str = get_bit_str(value, 4);

	printf("Setting bit at position (index) %d on num %d : result: %d : %s\n", pos, num, value, bit_str);

	free(bit_str);

	// Set the 1st bit of zero to 1.
	pos = 1;

	value = num | (1 << pos);

	bit_str = get_bit_str(value, 4);

	printf("Setting bit at position (index) %d on num %d : result: %d : %s\n", pos, num, value, bit_str);

	free(bit_str);
}




