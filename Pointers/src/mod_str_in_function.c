/*
 * mod_str_in_function.c
 *
 *  Created on: Jan 2, 2026
 *  Author: mark2v
 */
#include <stdio.h>

#include "../include/mod_str_in_function.h"

void mod_str_in_fcn(char **s);

/***********************************************************************
 * NAME:		test_mod_str_in_function()
 *
 * DESCRIPTION:	Tests passing a double pointer to a function that will
 * 				modify the string address itself.
 */
void test_mod_str_in_function() {

	printf("*****  test_mod_str_in_function  *****\n");

	char * s = "Hello";

	printf("BEFORE mod string: %s - %p\n", s, s);

	mod_str_in_fcn(&s);

	printf("AFTER mod string: %s - %p", s, s);
}

/***********************************************************************
 * NAME:		mod_str_in_fcn(char**)
 *
 * DESCRIPTION:	Modifies the pointer itself by dereferencing the pointer.
 */
void mod_str_in_fcn(char **s) {

	(*s) = "Goodbye";
}
