/*
 * function_pointers.c
 *
 *  Created on: Dec 14, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

// Only needed for strlen()
//#include <string.h>

#include "../include/function_pointers.h"

int do_str_fun(char *pa, char *pb) {
	printf("do_str_fun(%s, %s)\n", pa, pb);

	return 1;
}

int do_int_fuc(int *i, int *j) {
	printf("do_int_fuc(%d, %d)\n", *i, *j);

	return 0;
}


/***********************************************************************
 * NAME:		test_fcn_ptr(int)
 *
 * DESCRIPTION:	Test a function pointer.
 *
 * PARAMTERS:	is_numeric - 0 for numeric, any other value for string.
 *
 */
void test_fcn_ptr(int is_numeric) {

	printf("*****  test_int_fcn_ptr *****\n");

	int (*fcn)(void *, void *);

	void *arg1;
	void *arg2;

	if (is_numeric) {
		fcn = (int (*)(void *, void *))do_int_fuc;

		// Or more expanded syntax:
//		int *a1 = (int*)malloc(sizeof(int));
//		if (a1 == NULL) {
//			fprintf(stderr, "malloc failed!");
//			return;
//		}
//
//		*a1 = 1;
//		arg1 = (void*)a1;

		arg1 = (int*)malloc(sizeof(int));
		if (arg1 == NULL) {
			fprintf(stderr, "malloc failed!");
			return;
		}

		(*(int*)arg1) = 7;

		arg2 = (int*)malloc(sizeof(int));
		if (arg2 == NULL) {
			fprintf(stderr, "malloc failed!");

			free(arg1);

			return;
		}

		(*(int*)arg2) = 10;
	}
	else {
		fcn = (int (*)(void *, void *))do_str_fun;

		char *a1 = (char*)malloc(sizeof(char) * (3 + 1));
		if (a1 == NULL) {
			fprintf(stderr, "malloc failed!");
			return;
		}

		// NOTE: snprintf must include enough in size for the null terminator.
		snprintf(a1, 4, "One");
		arg1 = a1;

		char *a2 = (char*)malloc(sizeof(char) * (3 + 1));
		if (a2 == NULL) {
			fprintf(stderr, "malloc failed!");

			free(a1);

			return;
		}

		snprintf(a2, 4, "Two");
		arg2 = a2;
	}

	fcn(arg1, arg2);

	free(arg1);
	free(arg2);

	printf("Done.\n");
}

