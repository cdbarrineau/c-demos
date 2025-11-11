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
 * NAME:		run_invert_bits_test()
 *
 * DESCRIPTION:	Runs various tests inverting bits via the tilde operator.
 *              This is used to make a bit mask.
 *
 * INPUTS:		None.
 *
 * OUTPUTS:		None.
 */
void run_invert_bits_test() {

	printf(BANNER, "run_invert_bits_test()");
	printf("To invert bits, use the NOT (~) operator and assign it to a value which is the MASK!\n\n");

	// ***  ~ is NOT operator that inverts each bit ***
	// Masking bit 0 in 1 will result in 1110 because ~ inverts all bits.
	// so ~0 === 1111
	int num_to_mask = 0;
	char* num_to_mask_str = get_bit_str(num_to_mask, 4);

	int mask = ~num_to_mask;
	char* mask_str = get_bit_str(mask, 4);
	printf("Mask of %s (%d) is %s (%d)\n", num_to_mask_str, num_to_mask, mask_str, mask);

	free(num_to_mask_str);
	free(mask_str);

	// Try the mask of 1.
	num_to_mask = 1;
	num_to_mask_str = get_bit_str(num_to_mask, 4);

	mask = ~num_to_mask;
	mask_str = get_bit_str(mask, 4);
	printf("Mask of %s (%d) is %s (%d)\n", num_to_mask_str, num_to_mask, mask_str, mask);

	free(num_to_mask_str);
	free(mask_str);
}

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

//	int bit_pos = 0;

	// ***  ~ is NOT operator that inverts each bit ***
	// Masking bit 0 in 1 will result in 1110 because ~ inverts all bits.
	// so ~0 === 1111
	// then left shift by one bit position is 1110
//	char* str = get_bit_str((~0), 4);
//	printf("~0: %s\n", str);
//	free(str);

//	int mask = ~(1 << bit_pos);
//	char* mask_str = get_bit_str(mask, 4);
//
//	printf("Mask of bit_pos: %d is %s", bit_pos, mask_str);



//	printf("mask at bit pos %d : ~(1 << %d) is %s (%d)\n", bit_pos, bit_pos, mask_str, mask);
//
//	int num = 1;
//	char* num_str = get_bit_str(num, 4);
//
//	printf("num %d : %s\n", num, num_str);
//
//	int value = num & mask;
//	char* value_str = get_bit_str(value, 4);
//
//	printf("clear bit value (num & mask) (%d & %d) is %s\n", num, mask, value_str);
//
//	// result = num & mask:
//	// result = num & ( ~(1 << 0) )
//	printf("Result bits: %s ( ~(1 << %s) )\n", value_str, mask_str);
//
//	free(num_str);
//	free(mask_str);
//	free(value_str);
}
