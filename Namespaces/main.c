/*
 * main.c
 *
 *  Created on: Jan 3, 2026
 *  Author: mark2v
 */
#include <stdio.h>
#include <string.h>

#include "include/externs.h"
#include "include/statics.h"
#include "include/macros.h"

int main() {

	test_pre_dec();

	/* externs are guaranteed to be initialized to zero (or NUL for a char array).
	 */
	printf("BEFORE test_extern() arr in main (extern vars are guaranteed to be init to zero): %s\n", arr);

	// c == \0 so size is zero.
	printf("length of arr: %zu\n", strlen(arr));

	test_extern();

	// Should be able to reference extern variables.
	printf("AFTER text_extern() arr in main: %s\n", arr);

	printf("\n*****  test_static_var_in_function  *****\n");
	printf("static vars in a function are guaranteed to be initialized to zero.\n");
	test_static_var_in_function(1);
	test_static_var_in_function(1);

	test_macros();

	return 0;
}
