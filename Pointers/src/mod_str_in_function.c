/*
 * mod_str_in_function.c
 *
 *  Created on: Jan 2, 2026
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/mod_str_in_function.h"

// Making these static allows only this .c file
// to use these functions.  Static also applies
// to variable.
static void mod_str_in_fcn(char **s);
static void mod_malloc_str_in_fcn(char **s);

/***********************************************************************
 * NAME:		test_mod_str_in_function()
 *
 * DESCRIPTION:	Tests passing a double pointer to a function that will
 * 				modify the string address itself.
 */
void test_mod_str_in_function() {

	printf("*****  test_mod_str_in_function  *****\n");

	char *s = "Hello";

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


/***********************************************************************
 * NAME:		test_mod_malloc_str_in_function()
 *
 * DESCRIPTION:	Tests passing a double pointer to a function that will
 * 				modify the string address itself using malloc to
 * 				specifically test how to handle the allocated memory.
 */
void test_mod_malloc_str_in_function() {

	printf("*****  test_mod_malloc_str_in_function  *****\n");

	char *s = (char*)malloc(sizeof(char) * 6);
	if (s == NULL) {
		fprintf(stderr, "Unable to allocate memory!");
		return;
	}

	strncpy(s, "Hello", 6);

	printf("BEFORE mod s %s - %p\n", s, s);

	mod_malloc_str_in_fcn(&s);

	printf("AFTER mod s %s - %p\n", s, s);

	free(s);
}

/***********************************************************************
 * NAME:		mod_malloc_str_in_fcn(char**)
 *
 * DESCRIPTION:	Modifies the pointer itself by dereferencing the pointer.
 */
void mod_malloc_str_in_fcn(char **s) {

	char *s2 = (char*)malloc(sizeof(char) * 8);
	if (s2 == NULL) {
		fprintf(stderr, "Unable to allocate s2 memory!");

		return;
	}

	strncpy(s2, "Goodbye", 8);

	char *tmp = (*s);

	free(tmp);

	(*s) = s2;

	printf("IN mod s %s - %p\n", (*s), s);
}




