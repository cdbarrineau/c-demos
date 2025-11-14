/*
 * invert_bits_test.c
 *
 *  Created on: Nov 13, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/bit_utils.h"
#include "../include/invert_bits_test.h"

/***********************************************************************
 * NAME:		run_invert_bits_test()
 *
 * DESCRIPTION:	Runs various tests inverting bits via the tilde operator.
 *              This is used to make a bit inverted.
 *
 * INPUTS:		None.
 *
 * OUTPUTS:		None.
 */
void run_invert_bits_test() {

	printf(BANNER, "run_invert_bits_test()");
	printf("To invert bits, use the NOT (~) operator\n\n");

	// ***  ~ is NOT operator that inverts each bit ***
	// inverting bit 0 in 1 will result in 1110 because ~ inverts all bits.
	// so ~0 === 1111
	int num_to_invert = 0;
	char* num_to_invert_str = get_bit_str(num_to_invert, 4);

	int inverted = ~num_to_invert;
	char* inverted_str = get_bit_str(inverted, 4);
	printf("Invert of %s (%d) is %s (%d)\n", num_to_invert_str, num_to_invert, inverted_str, inverted);

	free(num_to_invert_str);
	free(inverted_str);

	// Try the inverted of 1.
	num_to_invert = 1;
	num_to_invert_str = get_bit_str(num_to_invert, 4);

	inverted = ~num_to_invert;
	inverted_str = get_bit_str(inverted, 4);
	printf("Invert of %s (%d) is %s (%d)\n", num_to_invert_str, num_to_invert, inverted_str, inverted);

	free(num_to_invert_str);
	free(inverted_str);

	// Try a inverted of 2.
	num_to_invert = 2;
	num_to_invert_str = get_bit_str(num_to_invert, 4);

	inverted = ~num_to_invert;
	inverted_str = get_bit_str(inverted, 4);
	printf("Invert of %s (%d) is %s (%d)\n", num_to_invert_str, num_to_invert, inverted_str, inverted);

	free(num_to_invert_str);
	free(inverted_str);

	// Try inverted of 3.
	num_to_invert = 3;
	num_to_invert_str = get_bit_str(num_to_invert, 4);

	inverted = ~num_to_invert;
	inverted_str = get_bit_str(inverted, 4);
	printf("Invert of %s (%d) is %s (%d)\n", num_to_invert_str, num_to_invert, inverted_str, inverted);

	free(num_to_invert_str);
	free(inverted_str);

	// Try the inverted of 4.
	num_to_invert = 4;
	num_to_invert_str = get_bit_str(num_to_invert, 4);

	inverted = ~num_to_invert;
	inverted_str = get_bit_str(inverted, 4);
	printf("Invert of %s (%d) is %s (%d)\n", num_to_invert_str, num_to_invert, inverted_str, inverted);

	free(num_to_invert_str);
	free(inverted_str);
}
