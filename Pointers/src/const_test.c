/*
 * const_test.c
 *
 *  Created on: Dec 4, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/const_test.h"

void update_char(char* c) {
	printf("Updating %s with c[0] = G\n", c);
	c[0] = 'G';
}

/***********************************************************************
 * NAME:		quick_const_test()
 *
 * DESCRIPTION:	Tests all three variants or const keyword.
 *
 */
void quick_const_test() {

	printf("*********  char test  *********\n");
	/******************************************************
	 * Defining it this way allocates the string in writeable
	 * memory so can do anything.
	 *
 	 */
	char arr1[] = "Hello, World!";
	arr1[0] = 'P';
	printf("arr1 = %s\n", arr1);

	// Can't just reassign because the pointer decays.
	// Have to use strncpy or memcpy.
	char arr2[] = "Goodbye";
//	arr1 = arr2;
	memcpy(arr1, arr2, 5);

	// Prints: "Goodb, World!"
	printf("after memccpy: arr1 = %s\n", arr1);




	/******************************************************
	 * Can reassign pointer but not the chars in the array.
	 *
 	 */
	char *c0 = "Zero";
	// Can't do this, core dumps.  Does NOT cause
	// any compiler warnings, just UB.
//	update_char(c0);
//	c0[0] = 'O';
	printf("c0 = %s\n", c0);

	char* c01 = (char*)malloc(sizeof(char) * 6);
	snprintf(c01, 6, "Zero2");
	c01[0] = 'L';
	printf("c01 = %s\n", c01);

	/******************************************************
	 * Can reassign pointer but not the chars in the array.
	 *
	 */
	const char *c1 = "One";
	// Can't do this as the contents read-only.
//	c1[0] = 'T';
	// This causes a seg fault.
//	update_char(c1);
	printf("c1 = %s\n", c1);

	const char *c11 = "OneOne";
	c1 = c11;
	c1 = "One";
	printf("c1 = %s\n", c1);

	// Can reassign the pointer.
	const char *c2 = "Two";
	c1 = c2;
	printf("c1 = %s\n", c1);

	// Try with dynamic memory.
	// NOTE: Probably don't want to do this.  If want a const,
	// malloc to a char* then assign to const char * then free
	// original char*.
//	const char *c3 = malloc(sizeof(char) * 6);

	char *c4 = (char*)malloc(sizeof(char) * 6);
	snprintf(c4, 6, "Hello");
	const char *c5 = c4;

	printf("c4 = %s ptr = %p\n", c4, c4);
	printf("c5 = %s ptr = %p\n", c5, c5);

//	free(c3);
	free(c4);

	printf("c5 = %s ptr = %p\n", c5, c5);

	// Can not do this as it's read-only memory.
//	c3[0] = '\0';

//	strcpy(c3, "Hello");
//	printf("c3 = %s\n", c3);
//	free(c3);





	// Get a warning about discarding const qualifier but allowable.
//	snprintf(c3, 6, "Three");
//	printf("c3 = %s\n", c3);

	// Get same warning about discaring const qualifier but allowable.
//	update_char(c3);
//	printf("c3 = %s\n", c3);


	// *****************************************************





//	const char *t1 = "Test 1";
//
//	// Can't change the contents, it's read-only memory.
////	t1[1] = 'L';
//
//	// Can reassign the pointer.
//	t1 = "Again";
//
//	printf("t1 = %s\n", t1);
//
//	// *****************************************************
//	char * const t2 = "Test 2";
//
//	// Can't change the pointer assignment.
////	t2 = "2 Again";
//
//	// Can't change an index in the array as the string literal is in read-only
//	// memory.  There are no compiler errors, just a seg fault.
////	t2[0] = 'F';
//	printf("t2 = %s\n", t2);
//
//	// Try with dynamic memory.
//	// Can change a char with this though.
//	char * const t3 = malloc(sizeof(char) * 6);
//	snprintf(t3, 6, "Three");
//	t3[0] = 'K';
//	printf("t3 = %s\n", t3);
//
//	// Can't do this as the const makes the pointer read-only.
////	t2 = t3;
//
//	// Can't do this as that assignment is to read-only memory.
//	char tmp[2];
//	tmp[1] = '\0';
//	tmp[0] = 'Z';
////	t3 = tmp;
////	t3 = &tmp;
//
//	free(t3);
//
//	const char * const tmp1 = "cc";
//	printf("tmp1 = %s\n", tmp1);
//
//
//	// *****************************************************
//	const char * const t4 = "Test 4";
//
//	// Can't do this because of first const, it's read-only memory.
////	t4[1] = 'L';
//	printf("t4 = %s\n", t4);
//
//	// Can't do this either, it's still read-only memory but again
//	// no compiler errors, just core dump.
//	char * const t5 = "Test 5";
////	t5[0] = 'F';
//	printf("t5 = %s\n", t5);
//
//	const char * const t6 = malloc(sizeof(char) * 4);
//	// Can't do this, compiler warning it discards the const pointer
//	// also core dumps.
////	snprintf(t6, 4, "Six");
//	printf("t6 = %s\n", t6);
//
//	// Can't even do this, compiler error assigning to read-only memory.
////	t6[0] = '\0';
//
//
//	// Can't do this, will seg fault.
////	char * t41 = t4;
////	t41[1] = 'L';
}





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
