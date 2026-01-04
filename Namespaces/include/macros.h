/*
 * macros.h
 *
 *  Created on: Jan 4, 2026
 *  Author: mark2v
 */

#ifndef INCLUDE_MACROS_H_
#define INCLUDE_MACROS_H_

#define YES printf("YESMAN\n")

// Gets the max of two numbers.
#define MAX(A, B) \
	((A) > (B) ? (A) : (B))

#define STRINGIFY(A) #A

#define CONCAT(A, B) A ## B

/***********************************************************************
 * NAME:		test_macros()
 *
 * DESCRIPTION:	Tests different macros.  This is not a test of every kind
 * 				that can be used but only the most common described in
 * 				K&R p80.
 */
void test_macros();

#endif /* INCLUDE_MACROS_H_ */
