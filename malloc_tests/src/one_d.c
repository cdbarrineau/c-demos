/*
 * one_d.c
 *
 *  Created on: Nov 29, 2025
 *  Author: mark2v
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/one_d.h"


/***********************************************************************
 * NAME:		print_zero_to_nine()
 *
 * DESCRIPTION:	Print 0 - 9 using the ASCII codes (0 in ASCII is 48 decimal).
 *
 * INPUTS:		None.
 *
 * OUTPUTS:		None.
 */
void print_zero_to_nine() {
	int num_items = 10;

	// Make sure to allocate +1 for the null terminator.
	char* arr = (char*)malloc(sizeof(char) * (num_items + 1));
	if (arr == NULL) {
		fprintf(stderr, "Error allocating buffer with malloc");
		return;
	}

	arr[0] = '\0';

	for (int i = 0; i < num_items; i++) {
		// 48 is 0.
		arr[i] = i + 48;

		printf("arr[%d] = %c\n", i, arr[i]);
	}

	arr[num_items] = '\0';

	printf("Array = %s", arr);

	free(arr);
}

/***********************************************************************
 * NAME:		init_str_list(uint size)
 *
 * DESCRIPTION:	Allocates, initializes, and frees a string list of
 * 				size "size".
 *
 * INPUTS:		size - The size of the char** to allocate and initialize.
 *
 * OUTPUTS:		None.
 */
void init_str_list(uint size) {
	if (size == 0) {
		fprintf(stderr, "Cannot allocate an array of size 0.");
		return;
	}

	// Allocate enough memory plus the NULL of the list array.
	char** arr = (char**)malloc(sizeof(char*) * (size + 1));

	if (arr == NULL) {
		fprintf(stderr, "Unable to allocate string array.");
		return;
	}

	// QUESTION: How to properly initialize arr?
	// I've seen multiple examples of such:
	// 1) arr[0] = NULL;     // If not sure if this is really needed like it is for a single char*
	// 2) arr[size] = NULL;  // I would think this must always be done.
	// 3) Some places say to do nothing though if so, draws into question of malloc "size + 1"

	// Valdrind will give no errors if this is commented or uncommented
	// I suppose because we are initializing each string in the array
	// below to NUL?
//	arr[0] = NULL;
//	arr[size - 1] = NULL;

	// ANSWER: Since we're immediately populating the arrays,
	// no need to do anything--it's just a waste.

	// Cap the array at 30 bytes.
	size_t len = 30;
	for (int i = 0; i < size; i++) {
		arr[i] = (char*)malloc(sizeof(char) * (len + 1));

		// QUESTION: Should there be a null terminated like below?
		// arr[i][0] = '\0';

		// ANSWER: Same as above, since immediately snprintf,
		// no need to null-terminate the array.

		// snprintf appends the NUL at the end.
		snprintf(arr[i], len, "arr[%d] = %d", i, i);
	}

	for (int i = 0; i < size; i++) {
		printf(arr[i]);
		printf("\n");

		free(arr[i]);
	}

	free(arr);
}




/***********************************************************************
 * NAME:		print_zero_to_nine_list()
 *
 * DESCRIPTION:	Print 0 - 9 where each entry is a string so a string
 * 				of strings (char**).
 *
 * INPUTS:		None.
 *
 * OUTPUTS:		None.
 */
void print_zero_to_nine_list() {

	init_str_list(10);


	// 10 strings in a string list.
//	int num_outter_items = 10;
//
//	// Cap each list item at 30 bytes.
//	int num_inner_bytes = 30;
//
//	// Always add one for the null terminator for a list of strings.
//	char** list = (char**)malloc(sizeof(char*) * (num_outter_items + 1));
//	list[0] = NULL;
//
//	printf("list: 	 %p\n", list);
//	printf("list[0]: %s\n", list[0]);
//
//	for (int i = 0; i < num_outter_items; i++) {
//		list[i] = '\0';
//
////		printf("list[%d] = %s\n", i, list[i]);
//		char* item = (char*)malloc(sizeof(char) * num_inner_bytes + 1);
//
////		item[num_inner_bytes] = '\0';
//
//		list[i] = item;
//
//		// snprintf ensures the item is NULL terminated.
//		snprintf(item, (num_inner_bytes + 1), "list[%d] = %d", i, i);
//
//		list[i] = item;
//	}
//
//	for (int i = 0; i < num_outter_items; i++) {
//		printf("%s\n", list[i]);
//
//		free(list[i]);
//	}
//
//	free(list);
}


