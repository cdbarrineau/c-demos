/*
 * macros.h
 *
 *  Created on: Jan 4, 2026
 *  Author: mark2v
 */

#ifndef INCLUDE_MACROS_H_
#define INCLUDE_MACROS_H_

#define PRINT_STUFF printf("printf Macro - no args.\n")

#define TEST_MAC 3

#if TEST_MAC == 1
	#define FNAME "Zero.h"
#elif TEST_MAC == 2
	#define FNAME "NoMac.h"
#elif TEST_MAC == 3
	#define FNAME "MaybeMac.h"
#elif TEST_MAC == 4
	#define FNAME = "YesMac.h"
#else
	#define FNAME = "Unknown.h";
#endif

// Gets the max of two numbers.
#define MAX(A, B) \
	((A) > (B) ? (A) : (B))

#define STRINGIFY(A) #A

#define CONCAT(A, B) A ## B

#define PRINT_MACRO(X) printf("%s = %s\n", #X, STRINGIFY(X))



/***********************************************************************
 * NAME:		test_macros()
 *
 * DESCRIPTION:	Tests different macros.  This is not a test of every kind
 * 				that can be used but only the most common described in
 * 				K&R p80.
 */
void test_macros();

#endif /* INCLUDE_MACROS_H_ */
