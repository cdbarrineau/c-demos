/*
 * pointer_arithmetic.c
 *
 *  Created on: Nov 30, 2025
 *  Author: mark2v
 */

#include <stdio.h>

#include "../include/int_pointer_arithmetic.h"

/***********************************************************************
 * NAME:		test_int_array()
 *
 * DESCRIPTION:	Does basic pointer arithmetic on a int array.
 *
 *
 */
void test_int_array() {

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

	// Set a pointer to the first element of the array (a[0]).
	// This will be the same value as "a" which is a pointer to the array.
	int *pa = &a[0];

	printf("pa: %p\n", pa);

	// On x86 the size of a pointer is 8 bytes.
	printf("sizeof(pa): %zu\n", sizeof(pa));

	// Deref the pointer to array (value in a[0] which is 10).
	int ten = (*pa);
	printf("*pa = %d\n", ten);

	// Get the address of a[1].
	// This is pa + 4 bytes for the int.
	int *pa1 = &a[1];
	printf("pa1 = %p\n", pa1);

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
 * NAME:		test_char_array()
 *
 * DESCRIPTION:	Does basic pointer arithmetic on a char array.
 *
 *
 */
void test_char_array() {
	printf("\n***********  char arrays  ***********\n");

	// b is the same as a above.
	char b[] = "hello";

	// p, here is an unnamed static array of chars.
	char *p = "hello";

	printf("b: %s\n", b);
	printf("p: %s\n", p);

	b[0] = 'p';
	printf("b after b[0] = 'p': %s\n", b);

	// This will crash the program.
//	p[0] = '1';
	printf("p[0] = '1' will crash the program since it's an unnamed static array.\n");

	// Prints 123
	char c[] = {'1', '2', '3', '\0'};
	printf("c: %s\n", c);
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
