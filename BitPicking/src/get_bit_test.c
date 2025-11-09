/*
 * get_bit_test.c
 *
 *  Created on: Nov 9, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/bit_utils.h"
#include "../include/get_bit_test.h"


/***********************************************************************
 * NAME:		run_get_bit_test()
 *
 * DESCRIPTION:	Runs various tests on getting a bit, a.k.a seeing if a
 * 				bit is set.
 *
 * INPUTS:		None.
 *
 * OUTPUTS:		None.
 */
void run_get_bit_test() {
	int num = 1;
	int pos = 0;

	char* num_bit_str = get_bit_str(num, 4);

	printf("\nTesting getting bit at position %d of num %d\n", pos, num);

	// This will show the bit at position 0 of num 1 (0001) is set.
	int is_bit_set = (num & (1 << pos)) != 0;
	print_bit_set(pos, num, is_bit_set, num_bit_str);

	free(num_bit_str);

	// Update values to something more exotic.
	num = 2;
	pos = 1;

	num_bit_str = get_bit_str(num, 4);

	printf("\nTesting getting bit at position %d of num %d\n", pos, num);

	// This will result in the bit being set.
	// Since we are getting the bit at index 1 and that is set because 2: 0010.
	is_bit_set = (num & (1 << pos)) != 0;

	print_bit_set(pos, num, is_bit_set, num_bit_str);

	// This will result in the bit NOT being set.
	// Since we are using num in binary 0001 and pos is index 1.
	num = 1;

	printf("\nTesting getting bit at position %d of num %d\n", pos, num);

	is_bit_set = (num & (1 << pos)) != 0;

	print_bit_set(pos, num, is_bit_set, num_bit_str);


	free(num_bit_str);
}
