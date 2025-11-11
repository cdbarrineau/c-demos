/*
 * print_bits.h
 *
 *  Created on: Nov 9, 2025
 *  Author: mark2v
 */

#ifndef INCLUDE_PRINT_BITS_H_
#define INCLUDE_PRINT_BITS_H_

/***********************************************************************
 * NAME:		print_int_bits(int)
 *
 * DESCRIPTION:	Prints each bit in the specified number on a separate line.
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
void print_int_bits(int num);

/***********************************************************************
 * NAME:		print_bits()
 *
 * DESCRIPTION:	Prints the first 15 bits in a byte.
 *
 */
void print_bits();

/****************************************************************************
 * NAME:		set_bits_loop()
 *
 * DESCRIPTION: Loops from 0 - 4 and sets the i'th bit in the loop and prints
 *              the result.
 *
 *              This is print out a bit string with 1 set to the index + 1 place so:
 *
 * 				0: 0001
 * 				1: 0010
 * 				2: 0100
 * 				3: 1000
 *
 */
void set_bits_loop();

/****************************************************************************
 * NAME:		shift_bits_loop()
 *
 * DESCRIPTION: Loops from 0 - 4 and sets the i'th bit in the loop and
 * 				prints the result.  This reuses the shifted value so that
 * 				in the end, each bit will be set.
 *
 * 				This is print out a bit string with 1 set to the index + 1 place so:
 *
 * 				0: 0001
 * 				1: 0011
 *	 			2: 0111
 * 				3: 1111
 *
 */
void shift_bits_loop();

/***********************************************************************
 * NAME:		bit_mask(int, int)
 *
 * DESCRIPTION:	???
 *
 * INPUTS:		value The value to mask.
 *              num_to_shift The number of bit positions to shift.
 *
 */
void bit_mask(int value, int num_to_shift);


#endif /* INCLUDE_PRINT_BITS_H_ */
