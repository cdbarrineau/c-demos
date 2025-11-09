/*
 * bit_utils.h
 *
 *  Created on: Nov 9, 2025
 *  Author: mark2v
 */

#ifndef INCLUDE_BIT_UTILS_H_
#define INCLUDE_BIT_UTILS_H_

/***********************************************************************
 * NAME:		get_bit_str(int, int)
 *
 * DESCRIPTION:	Gets a dynamically allocated pointer to a string array that
 * 				contains the bit representation of the specified integer
 * 				as a "num_bits" bit value.
 *
 * WARNING:		Caller is responsible for freeing returned char*.
 *
 * INPUTS:		num The number to get the bit representation.
 * 				num_bits The number of bits to put in the string output.
 * 				Usually 4 or 8.
 *
 * OUTPUTS:		char* Returns the heap-allocated string representation of the
 * 				bits in num.
 */
char* get_bit_str(int num, int num_bits);

/***********************************************************************
 * NAME:		print_bit_set(int, int, int, char*)
 *
 * DESCRIPTION:	Prints out if a bit is set.
 *
 * INPUTS:		pos The bit position.
 *              num The number that contains the bits.
 *              is_bit_set 0 if not set, non-zero if set.
 * 				num_bit_str The string representation of the number in bits.
 *
 */
void print_bit_set(int pos, int num, int is_bit_set, char* num_bit_str);

#endif /* INCLUDE_BIT_UTILS_H_ */
