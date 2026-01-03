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

int main() {

	/* Probably not a good idea to do this since arr does
	 * have the first index set to NUL.
	 */
	printf("BEFORE test_extern() arr in main (not a good idea, arr is not NUL terminated yet): %s\n", arr);

	test_extern();

	// Should be able to reference extern variables.
	printf("AFTER text_extern() arr in main: %s\n", arr);

	printf("*****  test_static_var_in_function  *****\n");
	test_static_var_in_function(1);
	test_static_var_in_function(1);

	return 0;
}
