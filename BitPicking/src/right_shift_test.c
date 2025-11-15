/*
 * right_shift_test.c
 *
 *  Created on: Nov 15, 2025
 *  Author: mark2v
 */

#include <stdio.h>
#include <stdlib.h>

#include "../include/bit_utils.h"
#include "../include/right_shift_test.h"

/***********************************************************************
 * NAME:		run_right_shift_test()
 *
 * DESCRIPTION:	Runs various tests with right shifting bits.
 *
 * INPUTS:		None.
 *
 * OUTPUTS:		None.
 */
void run_right_shift_test() {

	printf(BANNER, "run_right_shift_test()");

	printf("number to shift << number of places to shift\n\n");

	int num_places_to_shift = 0;
	int num_to_shift = 1;
	int shifted = num_to_shift >> num_places_to_shift;

	printf("num_places_to_shift: \t%d\n", num_places_to_shift);

	char* num_to_shift_str = get_bit_str(num_to_shift, 4);
	printf("num_to_shift: (%d) \t%s\n", num_to_shift, num_to_shift_str);

	char* shifted_str = get_bit_str(shifted, 4);
	printf("shifted: %d (%d >> %d): \t%s\n", shifted, num_to_shift, num_places_to_shift, shifted_str);

	free(num_to_shift_str);
	free(shifted_str);

	printf("\n");

	num_places_to_shift = 1;
	num_to_shift = 1;
	shifted = num_to_shift >> num_places_to_shift;

	printf("num_places_to_shift: \t%d\n", num_places_to_shift);

	num_to_shift_str = get_bit_str(num_to_shift, 4);
	printf("num_to_shift: (%d) \t%s\n", num_to_shift, num_to_shift_str);

	shifted_str = get_bit_str(shifted, 4);
	printf("shifted: %d (%d >> %d): \t%s\n", shifted, num_to_shift, num_places_to_shift, shifted_str);

	free(num_to_shift_str);
	free(shifted_str);

	printf("\n");

	num_places_to_shift = 1;
	num_to_shift = 3;
	shifted = num_to_shift >> num_places_to_shift;

	printf("num_places_to_shift: \t%d\n", num_places_to_shift);

	num_to_shift_str = get_bit_str(num_to_shift, 4);
	printf("num_to_shift: (%d) \t%s\n", num_to_shift, num_to_shift_str);

	shifted_str = get_bit_str(shifted, 4);
	printf("shifted: %d (%d >> %d): \t%s\n", shifted, num_to_shift, num_places_to_shift, shifted_str);

	free(num_to_shift_str);
	free(shifted_str);

	printf("\nNegative Numbers\n");
	printf("a >> n is the same mathematically as a / (2^n)\n\n");


	num_places_to_shift = 1;
	num_to_shift = -2;
	shifted = num_to_shift >> num_places_to_shift;

	printf("%d / 2^%d = %d\n", num_to_shift, num_places_to_shift, shifted);

	printf("num_places_to_shift: \t%d\n", num_places_to_shift);

	num_to_shift_str = get_bit_str(num_to_shift, 4);
	printf("num_to_shift: (%d) \t%s\n", num_to_shift, num_to_shift_str);

	shifted_str = get_bit_str(shifted, 4);
	printf("shifted: %d (%d >> %d): \t%s\n", shifted, num_to_shift, num_places_to_shift, shifted_str);

	free(num_to_shift_str);
	free(shifted_str);
}
