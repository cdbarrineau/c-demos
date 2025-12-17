/*
 * pointer_array.c
 *
 *  Created on: Dec 9, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/pointer_array.h"


/***********************************************************************
 * NAME:		test_int_ptr_array()
 *
 * DESCRIPTION:	Test a 2-D int array or pointers.
 *
 *
 */
void test_int_ptr_array() {

	printf("****  test_int_ptr_array  ****\n");

	int ptr_len = 3;

	// This allocates 3 pointers and does not init them.
	// Could do this but does not work with ptr_len:
	// 		int *arr[3] = { NULL };
	int *arr[ptr_len];

	printf("arr: %p\n", arr);

	// Init the array.
	for (int i = 0; i < ptr_len; i++) {
		// Can't do this because it's the same address, just the value is
		// different so need to malloc each item.
//		int v = i + 1;
//		arr[i] = &v;

		// So have to malloc.
		//int* a = (int*)malloc(sizeof(int));
		//*a = i + 1;
		//arr[i] = a;
//		printf("arr[%d] = %d : %p\n", i, *a, arr[i]);

		// Or simply:
		*(arr + i) = (int*)malloc(sizeof(int));

		*(arr + i)[0] = i + 1;
		// or:
		// *arr[i] = i + 1;

		printf("malloc'd arr[%d] = %d : %p\n", i, *arr[i], arr[i]);
	}

	printf("Printing...\n");


	for (int i = 0; i < ptr_len; i++) {

		// Can get 0th element because of malloc above with sizeof(int)
		int val = *(arr + i)[0];

		// Or:
//		int val = *arr[i];
		printf("arr[%d] = %d\n", i, val);

		free(arr[i]);
	}
}


/***********************************************************************
 * NAME:		test_char_ptr_array()
 *
 * DESCRIPTION:	Test a char[] array of pointers.
 *
 *
 */
void test_char_ptr_array() {

	printf("****  test_char_ptr_array  ****\n");

	int num_items = 5;
	int len = 30;

	// NOTE: This can be the same as char** however that char** must
	// be malloc'd.
	// Additionally, if the len is not known, have to do a malloc.
	char *arr[30];

	for (int i = 0; i < num_items; i++) {
		*(arr + i) = (char*)malloc(sizeof(char) * (len + 1));

		// or:
//		arr[i] = (char*)malloc(sizeof(char) * (len + 1));


		// Wasteful to do this since doing snprintf next.
		// The zero-terminator would get overwritten immediately.
//		*(arr + i)[0] = '\0';

		// or:
//		arr[i][0] = '\0';

		// The string is over 30 chars so it will be cut off.
		snprintf(*(arr + i), len + 1, "item # %d of some really long line", (i + 1));

		// or:
//		snprintf(arr[i], len + 1, "item # %d of some really long line", (i + 1));

		// When accessing array items have to wrap the deref operator in parens.
//		char c = (*(arr + i))[1];
//		printf("c = %c\n", c);

		// Can not modify a "pointer to a character array", results in UB
		// as this is a pointer to a string constant:
		//
		//  	char* pa = "My Array";
		//
		// HOWEVER, looks like in this case we can mod it.  Probably because
		// we malloc'd the array.
		(*(arr + i))[1] = 'H';

		// or:
//		arr[i][1] = 'H';

		printf("arr[%d] = %s\n", i, arr[i]);
	}

	for (int i = 0; i < num_items; i++) {
		free(arr[i]);
	}
}

/***********************************************************************
 * NAME:		test_char_ptr_to_ptrs()
 *
 * DESCRIPTION:	Test a char* array of pointers.
 *
 *
 */
void test_char_ptr_to_ptrs() {

	int num_items = 5;
	int len_char_arr = 30;

	printf("****  test_char_ptr_to_ptrs  ****\n");
	printf("In this case there are %d + 1 blocks set assign for each char* array\n", len_char_arr);
	printf("totaling %d * %d.  Then for the outer array, there are %d more pointers\n", (len_char_arr + 1), num_items, num_items);
	printf("to each inner array.\n\n");

	char **arr = NULL;

	arr = (char**)malloc(sizeof(char*) * (num_items + 1));

	// arr points to arr[0].
	printf("Allocated memory arr address: %p\n", arr);

	for (int i = 0; i < num_items; i++) {
		*(arr + i) = (char*)malloc(sizeof(char) * (len_char_arr + 1));

		// Wasteful to do this since doing snprintf next.
		// The zero-terminator would get overwritten immediately.
//		*(arr + i)[0] = '\0';

		snprintf(*(arr + i), len_char_arr, "Some long string: %d other stuff", i);
	}

	/*
	 * In this case there are 30 + 1 blocks set assign for each char* array
	 * totaling 31 * 5.  The for the outer array, there are 5 more pointers
	 * to each inner array.
	 *
	 *
	 * arr + i -> This is the pointer address in the outer array that
	 * 			  points to the first location of each char* pointer.
	 *
	 * *(arr + i) -> This is the pointer to the fist location of the actual
	 * 				 char* pointer in memory.  Deref this to get the string.
	 *
	 * IMPORTANT: Note how the pointer address is consecutive 8 bytes
	 * 			  from the last.
	 *
	 * ALSO:	  Note how each *(arr + i) ptr is 30 bytes to the next char*,
	 * 			  note sure if this is always the case since using malloc.
	 */
	printf("Pointer address in the outer array that points to first location of each char*\n");
	for (int i = 0; i < num_items; i++) {
		printf("arr + i = %p where i = %d\n", (arr + i), i);
	}

	printf("Deref value and pointer to the inner array.\n");
	for (int i = 0; i < num_items; i++) {
		printf("*(arr + i) = %s : %p where i = %d\n", *(arr + i), *(arr + i), i);

		free(*(arr + i));
	}

	free(arr);
}






