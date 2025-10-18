/*
 * arrays.c
 *
 *  Created on: Oct 11, 2025
 *      Author: mark2v
 */

#include <stdio.h>
#include <string.h>

#include "include/one_d_array.h"
#include "include/two_d_array.h"
#include "include/two_d_char_array.h"

#include "include/str_ops.h"

/***********************************************************************
 * NAME:		do_str_ops()
 *
 * DESCRIPTION:	Does some string operations.
 *
 */
void do_str_ops() {
	char* name1 = "Apple";
	char* name2 = "Banana";

	int result = compare(name1, name2);
	printf("Compare result of %s and %s is %d\n", name1, name2, result);

	int result2 = compare(name2, name1);
	printf("Compare result of %s and %s is %d\n", name2, name1, result2);

	int result3 = compare(name1, name1);
	printf("Compare result of %s and %s is %d\n", name1, name1, result3);

	int result4 = compare(NULL, NULL);
	printf("Compare result of NULL is %d\n", result4);

	int len1 = length(name1);
	printf("Length of %s is %d\n", name1, len1);

	int len2 = length(name2);
	printf("Length of %s is %d\n", name2, len2);

	int len3 = length(NULL);
	printf("Length of NULL is %d\n", len3);

	// This will core dump.
	// printf("Concat: %s\n", concat(name1, name2));

	const char src[] = "Hello";
	char dest[] = "World";

	concat(dest, src);
	printf("strcat: %s\n", dest);
	printf("length: %d\n", length(dest));


	printf("End\n");
}


int main() {

	do_str_ops();


//	printf ("***** one_d_array *****\n");
//	one_d_array();
//
//	printf ("***** two_d_array *****\n");
//	two_d_array();
//
//	printf ("***** two_d_char_array *****\n");
//	two_d_char_array();

	return 0;
}
