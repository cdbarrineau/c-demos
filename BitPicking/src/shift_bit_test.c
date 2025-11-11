/*
 * shift_bit_test.c
 *
 *  Created on: Nov 10, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/shift_bit_test.h"
#include "../include/bit_utils.h"

/***********************************************************************
 * NAME:		run_shift_bit_test()
 *
 * DESCRIPTION:	Runs various tests on shifting a bit.
 *
 * INPUTS:		None.
 *
 * OUTPUTS:		None.
 */
void run_shift_bit_test() {

	printf(BANNER, "run_shift_bit_test()");

	int val1 = 0 << 0;

	char* str1 = get_bit_str(val1, 4);
	printf("0 << %d == %d => %s  - because: (0 * 2^%d=%d)\n", 0, val1, str1, 0, val1);
	free(str1);

	int pos = 0;

	// This will be 1 (0001) because 2^0 = 1.
	int val = 1 << pos;
	char* str = get_bit_str(val, 4);
	printf("1 << %d == %d => %s  - because: (1 * 2^%d=%d)\n", pos, val, str, pos, val);
	free(str);

	// This will be 2 (0011) because 2^1 = 2.
	pos = 1;
	val = 1 << pos;
	str = get_bit_str(val, 4);
	printf("1 << %d == %d => %s  - because: (1 * 2^%d=%d)\n", pos, val, str, pos, val);
	free(str);

	// This will be 4 (0100) because 2^2 == 4
	pos = 2;
	val = 1 << pos;
	str = get_bit_str(val, 4);
	printf("1 << %d == %d => %s  - because: (1 * 2^%d=%d)\n", pos, val, str, pos, val);
	free(str);

	pos = 1;
	val = 5 << pos;
	str = get_bit_str(val, 4);
	printf("5 << %d == %d => %s  - because: (5 * 2^%d=%d)\n", pos, val, str, pos, val);
	free(str);

	pos = 3;
	val = 5 << pos;
	str = get_bit_str(val, 8);
	printf("5 << %d == %d => %s  - because: (5 * 2^%d=%d)\n", pos, val, str, pos, val);
	free(str);

}

