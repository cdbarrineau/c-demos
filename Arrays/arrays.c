/*
 * arrays.c
 *
 *  Created on: Oct 11, 2025
 *      Author: mark2v
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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

/*
 *
 */
void create_20_array() {

	int len = 20;

	char* arr = (char*)malloc(len);
	arr[0] = '\0';

	// This will put in the ASCII chars from 48 (0) to 67 (C).
	for (int i = 0; i < len; i++) {
		arr[i] = i + '0';
	}

	for (int i = 0; i < len; i++) {
		printf("%c\n", arr[i]);
	}

	printf("str = %s\n", arr);
	printf("strlen: %zu\n", strlen(arr));

	free(arr);
}

void free_str_array_of_arrays(char** arr, int len) {

	for (int i = 0; i < len; i++) {
		free(arr[i]);
	}

	free(arr);
}

void create_str_array_of_arrays() {

	// Length of the array or string arrays.
	int num_row = 20;
	int num_cols = 10;

	// Allocate the pointer to the list of pointers.
	// Allocate 20 slots of size char* plus one for the NULL terminator.
	char** outer = (char**) malloc(sizeof(char*) * (num_row + 1));

	for (int i = 0; i < num_row; i++) {
		// Each item in the list, allocate enough space for num_cols plus the NULL terminator.
		outer[i] = (char*)malloc(sizeof(char) * (num_cols + 1));
		outer[i][0] = '\0';

		snprintf(outer[i], num_cols + 1, "item # %d", (i + 1));
	}

	for (int i = 0; i < num_row; i++) {
		printf("outer[%d]: %s\n", i, outer[i]);
	}

	free_str_array_of_arrays(outer, num_row);
}


int main() {

//	do_str_ops();

//	create_20_array();

	create_str_array_of_arrays();


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
