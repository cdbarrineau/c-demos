/*
 * clear_bit_test.h
 *
 *  Created on: Nov 11, 2025
 *  Author: mark2v
 */

#ifndef INCLUDE_CLEAR_BIT_TEST_H_
#define INCLUDE_CLEAR_BIT_TEST_H_

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
void run_invert_bits_test();

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
void run_clear_bit_test();

#endif /* INCLUDE_CLEAR_BIT_TEST_H_ */
