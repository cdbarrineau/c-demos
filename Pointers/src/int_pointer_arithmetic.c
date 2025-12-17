/*
 * pointer_arithmetic.c
 *
 *  Created on: Nov 30, 2025
 *  Author: mark2v
 */

#include <stdio.h>

#include "../include/int_pointer_arithmetic.h"

/***********************************************************************
 * NAME:		test_arr_like_char()
 *
 * DESCRIPTION:	Tests the weird behavior with arrays as seen in chars.
 *
 *
 */
void test_arr_like_char() {
	int arr[] = { 11, 13, 15 };

	printf("arr = %p\n", arr);

	int c = 0;
	int *cp = NULL;

	printf("\nc = %p -- cp = %p\n", &c, cp);

	/*
	 * Any time you assign an address to
	 * a variable like:
	 * 		int c = *(arr + i);
	 * 			or
	 * 		int c = &(*(arr + i));
	 *
	 * c points to the same address because it is
	 * the address of "c" that is being printed, not
	 * the address of the array index.
	 *
	 */

	// This assigns the VALUE in arr[i] to the variable
	// c.  Since c is already allocated, the address of
	// c remains unchanged but it's value, arr[i] is
	// the only thing that changes.
	for (int i = 0; i < 3; i++) {
		c = *(arr + i);
		printf("&(*(arr + %d) = %d : %p\n", i, c, &c);
	}

	printf("\n");

	// This assigns the address of arr[i] to the pointer cp
	// therefore, the values for cp are different since they
	// point to a different index in the array.

	// NOTE how the first pointer address is the same address
	// as arr[0] AND how each address is 4 bytes from the last
	// address.
	for (int i = 0; i < 3; i++) {
		cp = &(*(arr + i));
		printf("&(*(arr + %d) = %d : %p\n", i, *cp, cp);
	}

	printf("\nc = %p -- cp = %p\n", &c, cp);

	// Same exact thing as above, only not assigning any tmp variables.
	for (int i = 0; i < 3; i++) {
		// arr[i] or *(arr + i)
		printf("&(*(arr + %d) = %d : %p\n", i, *(arr + i), &(*(arr + i)));
	}
}

/***********************************************************************
 * NAME:		test_int_array_and_pointers()
 *
 * DESCRIPTION:	Runs the same tests on both array and pointers.
 *
 *
 */
void test_int_array_and_pointers() {

	// Define an array.
	int arr[] = { 11, 14, 16 };

	printf("arr: %p\n", arr);

	for (int i = 0; i < 3; i++) {
		int val = *(arr + i);

		printf("val[%d] = %d\n", i, val);
	}

	for (int i = 0; i < 3; i++) {
		int *val = arr + i;

		printf("val[%d] = %p\n", i, val);
	}
}


/***********************************************************************
 * NAME:		print_int_arr_deref()
 *
 * DESCRIPTION:	Prints an int array's pointer address and value.
 *
 *
 */
void print_int_arr_deref() {

	printf("\n***********  print_int_arr_deref  ***********\n");

	// NOTE: "a" is refereed to as "array name".
	int a[] = { 10, 20, 30 };

	size_t size = sizeof(a) / sizeof(int);

//	printf("*a = %d\n", *a);
//	printf("*a + 1 = %d\n", *a + 1);

	// Set a pointer to point to element zero of a.
	// Or just can use "a"
	// This is the same as:
	//		pa = a  Since a is the location of initial element
//	int *pa = &a[0];
	int *pa = a;

	// So both of these pointer addresses are the same.
	printf("pa = %p\n", pa);
	printf("a  = %p\n", a);

	// Deref the element at index 0.
	printf("*pa = %d\n", *pa);

	// Could just use a[i] but C compiler will convert to *(pa + i).
	// Adding i to the address of a which gives the next
	// pointer location, then dereferencing that address.
	// So it gives 10, 20, 30
	for (int i = 0; i < size; i++) {
		// The value stored in index i.
		int val = *(pa + i);
		printf("*(pa + %d) = %d\n", i, val);
	}

	// Could just use a[i] but C compiler will convert to *(pa + i).
	// Same thing as above with:
	// 			int *n = *(a + 1);
//	for (int i = 0; i < size; i++) {
//		int val = *(a + i);
//		printf("*(a + %d) = %d\n", i, val);
//	}

	// This one will defref a and add one (i.e. "i") to a[0].
	// Values will be: 10, 11, 12
	// BECAUSE first dereferencing a then adding i to the value in a[0].
	for (int i = 0; i < size; i++) {
		int val = (*a + i);
		printf("(*a + %d) = %d\n", i, val);
	}

	// This is the same address as a + 0.
	printf("a = %p\n", a);
	printf("pa = %p\n", pa);

	// Can index with pa, so pa is the same as a.  p[1] = 11.
	printf("pa[1] = %d\n", pa[1]);

	for (int i = 0; i < size; i++) {
		// The address of the pointer in a[i].
		// Notice how each address if 4 byte offset from the previous
		// because size of an int is 4 bytes and the array is
		// contiguous in memory.
		printf("(a + %d) = %p\n", i, (a + i));
	}
}

/***********************************************************************
 * NAME:		test_int_array()
 *
 * DESCRIPTION:	Does basic pointer arithmetic on a int array.
 *
 *
 */
void test_int_array() {

//	print_int_arr_deref();

	printf("\n***********  int pointer arithmetic  ***********\n");

	int a[] = {10, 11, 12, 13, 14};



	// This outputs 20 which is the number of bytes allocated
	// (5 ints * 4 bytes per int).
	printf("size of a[]: %zu\n", sizeof(a));

	// Dereference the first item in a: 10.
	// NOTE: to print the whole array must loop to print each one.
	printf("*a: %d\n", (*a));

	// Prints the pointer address to a[0].
	printf("a:  %p\n", a);

	printf("a[0]: %d\n", a[0]);
	printf("*a: %d\n", (*a));

	printf("a[1]: %d\n", a[1]);

	printf("&a[0]: %p\n", &a[0]);
	printf("&a[1]: %p\n", &a[1]);

	// Set a pointer to the first element of the array (a[0]).
	// This will be the same value as "a" which is a pointer to the array.
	int *pa = &a[0];

	printf("pa: %p\n", pa);

	// On x86 the size of a pointer is 8 bytes.
	printf("sizeof(pa): %zu\n", sizeof(pa));

	// Deref the pointer to array (value in a[0] which is 10).
	int ten = (*pa);
	printf("*(pa) = %d\n", ten);

	// Get the address of a[1].
	// This is pa + 4 bytes for the int.
	int *pa1 = &a[1];
	printf("pa1 (&a[1]) = %p\n", pa1);

	// Get the next address of pa + 1.  This is exactly the same as *pa1
	int *pa1_1 = pa + 1;
	printf("pa + 1 = %p\n", pa1_1);

	// Use pointer arithmetic to get the next value.
	// This refers to the contents of a[1] which is 11.
	int eleven = (*pa + 1);
	printf("(*pa + 1) = %d\n", eleven);

	// The contents of a[1] is equal to (*pa + 1) which is 11.
	printf("a[1] = %d\n", a[1]);
}


/***********************************************************************
 * NAME:		pointers_and_addresses()
 *
 * DESCRIPTION:	Does basic pointer pointer and address tests.
 *
 *
 */
void pointers_and_addresses() {
	int x = 1;
	int y = 2;
	int z[10];

	// Book example does not do this so it contains garbage value.
	z[0] = 10;

	// ip is a pointer to an int.
	int *ip;

	ip = &x; /* ip now points to x */
	printf("ip = %p\n", ip);
	printf("ip val = %d\n", (*ip));

	y = *ip; /* y is now 1 */
	printf("y = %d\n", y);

	*ip = 0; /* x is now 0 */
	ip = &z[0]; /* ip now points to z[0] */
	printf("ip = %p\n", ip);
	printf("ip val = %d\n", (*ip));
	printf("z[0] = %d\n", z[0]);

	printf("\n");

	int *iq = ip;
	printf("iq = %p\n", iq);

	(*iq) = 30;
	printf("ip val = %d\n", (*ip));
	printf("iq val = %d\n", (*iq));
}
