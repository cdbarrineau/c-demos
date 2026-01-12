/*
 * variable_args.c
 *
 *  Created on: Jan 10, 2026
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdarg.h>

static void print_char_args(char *fmt, ...);
static void print_int_args(int n, ...);

/***********************************************************************
 * NAME:		test_variable_args()
 *
 * DESCRIPTION: Tests va_arg in a function.
 *
 */
void test_variable_args() {

	// The first argument's length must match the
	// number of parameters in the ...
	print_char_args("23", "Two", "Three");

	print_int_args(4, 4, 3, 2, 1);
}

/***********************************************************************
 * NAME:		print_char_args(char*, ...)
 *
 * DESCRIPTION:	Prints variable arguments.
 *
 * PARAMETERS:	start The initial string.
 * 				... Any arguments after the initial string.
 */
static void print_char_args(char *start, ...) {

	va_list ap;

	// Set where the va arg part of the argument list ends.
	va_start(ap, start);

	for (char *p = start; *p; p++) {
		char *str = va_arg(ap, char*);

		printf("str = %s, p = %s\n", str, p);
	}

	va_end(ap);
}

/***********************************************************************
 * NAME:		print_int_args(int n, ...);
 *
 * DESCRIPTION:	Prints out the va args of ints.
 *
 * PARAMETERS:	n The number of arguments.
 * 				... the variable arguments.
 */
void print_int_args(int n, ...) {

	va_list ap;

	va_start(ap, n);

	for (int i = 0; i < n; i++) {
		int curr = va_arg(ap, int);

		printf("curr = %d\n", curr);
	}

	va_end(ap);
}





