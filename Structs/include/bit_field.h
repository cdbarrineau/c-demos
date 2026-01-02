/*
 * bit_field.h
 *
 *  Created on: Dec 30, 2025
 *  Author: mark2v
 */

#ifndef INCLUDE_BIT_FIELD_H_
#define INCLUDE_BIT_FIELD_H_

/*
 * A struct can be used to create a bit field making
 * simple bit shifting more readable.
 *
 * Again, can't do this here, multiple defnitions.
 */
//struct {
//	unsigned int first : 1;
//	unsigned int second : 1;
//	unsigned int third : 1;
//} flags;

/***********************************************************************
 * NAME:		test_bit_field()
 *
 * DESCRIPTION:	Runs various tests using a struct as a bit field.
 *
 */
void test_bit_field();

#endif /* INCLUDE_BIT_FIELD_H_ */
