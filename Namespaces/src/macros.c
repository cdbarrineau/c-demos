/*
 * macros.c
 *
 *  Created on: Jan 4, 2026
 *  Author: mark2v
 */
#include <stdio.h>

#include "../include/macros.h"

/***********************************************************************
 * NAME:		test_macros()
 *
 * DESCRIPTION:	Tests different macros.  This is not a test of every kind
 * 				that can be used but only the most common described in
 * 				K&R p80.
 */
void test_macros() {

	printf("\n*****  test_macros  *****\n");

	// Defined as a printf macro.
	YES;

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


//	int a = 1;
//	int b = 1;
////	int ab = 0;
//	int ab = CONCAT(a, b);







}

