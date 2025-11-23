/*
 * twos_compliment.c
 *
 *  Created on: Nov 15, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/bit_utils.h"
#include "../include/twos_compliment.h"


/***********************************************************************
 * NAME:		run_twos_compliment_test()
 *
 * DESCRIPTION:	Runs various tests with 2's compliment.
 *
 * INPUTS:		None.
 *
 * OUTPUTS:		None.
 */
void run_twos_compliment_test() {

	printf(BANNER, "run_twos_compliment_test()");

	// Convert a positive to a negative number.

	// Invert all bits and add 1.
	int num_to_convert = 0;
	int inverted = ~num_to_convert;
	int result = inverted + 1;

	char* num_to_convert_str = get_bit_str(num_to_convert, 4);
	char* inverted_str = get_bit_str(inverted, 4);
	char* result_str = get_bit_str(result, 4);

	printf("num to convert:\t  %d (%s)\n", num_to_convert, num_to_convert_str);
	printf("inverted:\t %d (%s)\n", inverted, inverted_str);
	printf("result:\t\t  %d (%s)\n", result, result_str);

	free(num_to_convert_str);
	free(inverted_str);
	free(result_str);

	printf("\n");

	num_to_convert = 1;
	inverted = ~num_to_convert;
	result = inverted + 1;

	num_to_convert_str = get_bit_str(num_to_convert, 4);
	inverted_str = get_bit_str(inverted, 4);
	result_str = get_bit_str(result, 4);

	printf("num to convert:\t  %d (%s)\n", num_to_convert, num_to_convert_str);
	printf("inverted:\t %d (%s)\n", inverted, inverted_str);
	printf("result:\t\t %d (%s)\n", result, result_str);

	free(num_to_convert_str);
	free(inverted_str);
	free(result_str);

	printf("\n");

	// Convert a negative to a positive number.
	num_to_convert = -1;
	inverted = ~num_to_convert;
	result = inverted + 1;

	num_to_convert_str = get_bit_str(num_to_convert, 4);
	inverted_str = get_bit_str(inverted, 4);
	result_str = get_bit_str(result, 4);

	printf("num to convert:\t %d (%s)\n", num_to_convert, num_to_convert_str);
	printf("inverted:\t  %d (%s)\n", inverted, inverted_str);
	printf("result:\t\t  %d (%s)\n", result, result_str);

	free(num_to_convert_str);
	free(inverted_str);
	free(result_str);
}
