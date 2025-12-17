/*
 * const_test.c
 *
 *  Created on: Dec 4, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/const_test.h"

/***********************************************************************
 * NAME:		test_const_arr_itens_and_ptr()
 *
 * DESCRIPTION:	Tests when both the array items and the pointer are
 * 				readonly:
 *
 * 					const int * const ptr;
 *
 */
void test_const_arr_itens_and_ptr() {

	printf("\n*********  test_const_arr_itens_and_ptr *********\n");

	int arr[] = { 2, 4, 6 };

	const int * const pa = arr;

	printf("arr: %p\n", arr);
	printf("pa:  %p\n", pa);

	// Should not be allowed to do this:
//	*(pa + 1) = 20;

	// Or this:
//	int arr2[] = { 8, 10 };
//	pa = arr2;
}


/***********************************************************************
 * NAME:		test_const_ptr()
 *
 * DESCRIPTION:	Tests when the array items are mutable but the
 * 				pointer is not:
 * 					int * const ptr;
 *
 */
void test_const_ptr() {

	printf("\n*********  test_const_ptr *********\n");

	// Defined this way, items in the array can be changed
	// but the pointer itself cannot.
	int arr[] = { 2, 4, 6 };

	// NOTE: NO & since arr is already a named array.
	// However, can do this either of these:
	int * const addr_of = &arr[0];

	int * const pa = arr;

	printf("&arr = %p\n", &arr);
	printf("pa   = %p\n", pa);
	printf("addr_of = %p\n", addr_of);

	// Should be able to change an item in the array but not the pointer itself.
	*(pa) = 20;

	printf("*pa   = %d\n", *pa);

	// Should not be able to do this though.
//	int arr2 = { 8, 10 };
//	pa = arr2;

	int i = 10;

	// This changes the value, not the pointer address.
	// NOTE where the * is, BEFORE the const.
	int * const pi = &i;
	printf("*(pi) = %d : pi = %p\n", *pi, pi);

	*pi = 11;
	printf("*(pi) = %d : pi = %p\n", *pi, pi);
}

/***********************************************************************
 * NAME:		test_const_arr_items()
 *
 * DESCRIPTION:	Tests when the pointer is mutable but the items in
 * 				an array, or even a single value, is readonly:
 *
 * 					const int *ptr;
 *
 */
void test_const_arr_items() {

	printf("\n*********  test_const_arr_itens *********\n");

	// Pointer to array is mutable but contents are not mutable.
	const int arr[] = { 2, 4, 6 };

	size_t len = sizeof(arr) / sizeof(int);

	// Can't do this because contents are not mutable.
	//	for (int i = 0; i < len; i++) {
	//		arr[i] = i;
	//	}

	// Obviously for this as well.
	//	arr[1] = 10;

	const int *pa = arr;

	printf("arr: %p\n", arr);
	printf("pa:  %p\n", pa);

	for (int i = 0; i < len; i++) {
		printf("pa[%d] = %d : %p\n", i, *(pa + i), &(*(pa + i)));
	}

	printf("\nRe-assigning pa to a2...\n");

	// Can't do this either as it still points to readonly memory.
//	*(pa) = 10;

	// Can't do this either, guessing because they are named arrays.
	//	const int a2[] = { 3, 5, 7 };
	//	arr = a2;

	// Cannot assign one array to another like this.
	//	int a2[] = { 0, 1 };
	//	int a3[] = { 2, 3 };
	//	&a3 = a2;


	// Allowed to reassign the pointer address.
	int a2[] = { 1, 2 };

	pa = a2;
	printf("a2: %p\n", a2);
	printf("pa: %p\n", pa);

	size_t len2 = sizeof(a2) / sizeof(int);

	for (int i = 0; i < len2; i++) {
		printf("pa[%d] = %d : %p\n", i, *(pa + i), &(*(pa + i)));
	}

	printf("\nDoing single int ptr...\n");

	/*
	 * Now to single int pointers.
	 *
	 */
	int i = 10;
	const int *pa2 = &i;

	printf("*(pa2) = %d : pa2 = %p\n", (*pa2), pa2);

	// Can't do this as it's readonly.
//	*(pa2) = 11;

	int j = 11;
	const int *pa3 = &j;

	printf("*(pa3) = %d : pa3 = %p\n", (*pa3), pa3);

	int k = 12;
	pa3 = &k;

	printf("*(pa3) = %d : pa3 = %p : &k = %p\n", (*pa3), pa3, &k);
}
