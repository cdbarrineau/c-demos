/*
 * statics.c
 *
 *  Created on: Jan 3, 2026
 *  Author: mark2v
 */
#include <stdio.h>

#include "../include/statics.h"

/***********************************************************************
 * NAME:		test_static_var_in_function(int)
 *
 * DESCRIPTION:	Tests a static variable in this function.  The static value
 * 				will remain across different function invocations.
 */
void test_static_var_in_function(int i) {

	static int j = 0;

	int k = i + j++;

	printf("static j = %d : k (%d + j) = %d\n", j, i, k);
}

