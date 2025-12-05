/*
 * str_pointer_arithmetic.c
 *
 *  Created on: Dec 1, 2025
 *  Author: mark2v
 */
#include <stdio.h>

#include "../include/str_pointer_arithmetic.h"

/***********************************************************************
 * NAME:		test_str_ptr_addresses()
 *
 * DESCRIPTION:	Tests an array as opposed to a pointer to a string.
 *
 *
 */
void test_str_ptr_addresses() {

	printf("****  test_str_ptr_addresses  ****\n");

	char str[] = "One";
	char c = '\0';
	char* cp = NULL;

	// These two print out the same address.
	printf("str as a pointer is %p\n", str);
	printf("&str as a pointer is %p\n", &str);

	printf("&c = %p -- cp = %p\n\n", &c, cp);

	// This assigns str[i] to c.  Since c is a
	// variable with its own address, this only
	// assigns the value at str[i] to c but the
	// address of c never changes, since it has
	// its own address.
	printf("These are c = *(str + i) so all addresses are the same which is address of local var 'c'\n");
 	for (int i = 0; i < 3; i++) {
 		// or c = arr[i]
		c = *(str + i);
		printf("index %d : &c = %c : %p\n", i, c, &c);
	}

 	printf("\n");

 	// Assigns the address of str[i] to pointer cp.
 	// NOTE how the address of cp when i = 0 is the
 	// same as the base address of str.
 	for (int i = 0; i < 3; i++) {
 		cp = &(*(str + i));
 		printf("&(*(str + %d) = %c : %p\n", i, *cp, cp);
 	}

 	printf("\n&c = %p -- cp = %p\n", &c, cp);

	// Exact as above only without assigning variable.
	for (int i = 0; i < 3; i++) {
		// str[i] or *(str + i)
		printf("&(*(str + %d) = %c : %p\n", i, *(str + i), &(*(str + i)));
	}
}


/***********************************************************************
 * NAME:		test_arr_ptr()
 *
 * DESCRIPTION:	Tests an array as opposed to a pointer to a string.
 *
 *
 */
void test_arr_ptr() {
	// This is an array.
	char str[] = "One";

	// Prints out the array's contents.
//	printf("str: %s\n", str);

	// Prints out the whole char array start with the index of i
	// so str[0] = One
	//    str[1] = ne
	//    str[2] = e
//	for (int i = 0; i < 3; i++) {
//		char* c = str + i;
//		printf("c at index %d: %s\n", i, c);
//	}

//	for (int i = 0; i < 3; i++) {
//		char* c = str + i;
//		printf("&c at index %d: %p\n", i, &c);
//	}

	// Prints out each array index's contents as the char at that index.
//	for (int i = 0; i < 3; i++) {
//		char c = *(str + i);
//		printf("str[%d] = %c\n", i, c);	// or str[i]
//	}
	// Prints out the same address for each which is the
	// pointer to the first element.
	for (int i = 0; i < 3; i++) {
		char c = *(str + i);
		printf("&(*(str + %d) %c = %p\n", i, c, &c);
	}

	for (int i = 0; i < 3; i++) {
		printf("&(*(str + %d) = %p\n", i, &(*(str + i)));
	}

	// Prints out the address of each array's contents.
//	for (int i = 0; i < 3; i++) {
//		void* p = &str[i];
//		printf("&str[%d] = %p\n", i, p);
////		printf("&str[%d] = %p\n", i, &str[i]);
//	}
//
//	for (int i = 0; i < 3; i++) {
//		char c = str[i];
//		printf("&str[%d] = %p\n", i, &c);
//	}


//	// This is a pointer to a STRING CONSTANT.
	char *pstr = "Two";

	for (int i = 0; i < 3; i++) {
		char c = *(pstr + i);
		printf("&(*(pstr + %d) %c = %p\n", i, c, &c);
	}

	for (int i = 0; i < 3; i++) {
		printf("&(*(pstr + %d) = %p\n", i, &(*(pstr + i)));
	}


//
//	// Prints out the whole string in the STRING CONSTANT.
//	printf("pstr = %s\n", pstr);
//
//	// Prints out the whole char array start with the index of i
//	// so str[0] = Two
//	//    str[1] = wo
//	//    str[2] = 0
//	for (int i = 0; i < 3; i++) {
//		char* c = pstr + i;
//		printf("c at index %d: %s\n", i, c);
//		printf("&c [%d] = %p\n", i, &c);
//	}
//
//	// Prints the contents of each pointer to a char in the array.
//	for (int i = 0; i < 3; i++) {
//		char c = *(pstr + i);
//		printf("pstr[%d] = %c\n", i, c);
//	}
//
//	// Prints the char* pointer to each
//	for (int i = 0; i < 3; i++) {
//		printf("pstr[%d] = %p\n", i, (pstr + i));
//	}
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
