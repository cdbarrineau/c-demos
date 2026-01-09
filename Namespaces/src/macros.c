/*
 * macros.c
 *
 *  Created on: Jan 4, 2026
 *  Author: mark2v
 */
#include <stdio.h>

#include "../include/macros.h"

void test_pound_defines() {

	printf("\n*****  test_pound_defines  *****\n");

	// Defined as a printf macro.
	PRINT_STUFF;

	printf("void* STRINGIFY = %s\n", STRINGIFY(void*));

	PRINT_MACRO(TEST_MAC);

// Define a test file macro and print it.
#define TEST_FILE "test.h"
	PRINT_MACRO(TEST_FILE);

// FNAME is set in header file.
#ifdef FNAME
	PRINT_MACRO(FNAME);
#else
	printf("FNAME not defined!\n");
#endif

}

/***********************************************************************
 * NAME:		test_macros()
 *
 * DESCRIPTION:	Tests different macros.  This is not a test of every kind
 * 				that can be used but only the most common described in
 * 				K&R p80.
 */
void test_macros() {

	test_pound_defines();

	printf("\n*****  test_macros  *****\n");

	int i = 1;
	int j = 2;
	printf("MAX(%d, %d) = %d\n", i, j, MAX(i, j));

	double x = 1.1;
	double y = 1.2;
	printf("MAX(%f, %f) = %f\n", x, y, MAX(x, y));

	// a comes before b in ASCII.
	char c1 = 'a';
	char c2 = 'b';
	printf("MAX(%c, %c) = %c\n", c1, c2, MAX(c1, c2));

	// For some reason getting compiler warnings about i and i
	// possibly not being defined when MAX is put into the printf.
	/*
	 * MAX(A, B) ((A) > (B) ? (A) : (B))
	 *
	 * What happens is that whatever the larger number is, it will be
	 * incremented twice, once for the condition test then again for the
	 * return value so:
	 *
	 * (i++) > (j++) ? (i++) : (j++)
	 *
	 * The macro returns the correct value (in this case 5 since 4++)
	 * but AFTER the macro is done, j is now set to 6.
	 */
	i = 2;
	j = 4;
	int k = MAX(i++, j++);
	printf("MAX(%d, %d) = %d\n", i, j, k);
	printf("\ti = %d j = %d\n", i, j);


	char *s = STRINGIFY(123);
	printf("s = %s\n", s);

	char *s2 = STRINGIFY(void*);
	printf("s2 = %s\n", s2);


	// This is really only used in things like auto-gen
	// names, etc.
	//
	// Don't think can use variables because the macros
	// are run on pre-processing where variables are not
	// defined yet.
//	int a = 1;
//	int b = 1;
	int ab = CONCAT(1, 2);
	printf("CONCAT %d\n", ab);
}

