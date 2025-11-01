/*
 * deref.c
 *
 *  Created on: Oct 28, 2025
 *      Author: mark2v
 */

#include <stdio.h>
#include <string.h>

#include "../include/deref.h"



/***********************************************************************
 * NAME:		pointerStuff()
 *
 * DESCRIPTION:	Runs various tests dealing with pointer manipulation.
 *
 *
 */
void pointerStuff() {
	char* str = "abcd";
//	char str[] = "abcd";

	// Without the newline it will run on for a while.
//	char str[] = {'a', 'b', 'c', 'd'};
//	char str[] = {'a', 'b', 'c', 'd', '\0'};

	// Print the address pointed to the beginning of the str array.
	printf("str ptr: %p\n", str);

	// Print the actual value of the char* array.
	// IMPORTANT: %s starts as the pointer location of the first until it
	// encounters any null char (\0)
	printf("str arr: %s\n", str);

	// Print the first item in the str array via indexing.
	printf("str[0]: %c\n", str[0]);

	// Print the first item in the str array via dereferencing the string at index 0.
	printf("str[0]: %c\n", *str);

	// Print the second item in the str array via dereferencing the string ar index 1.
	printf("str[1]: %c\n", (*str + 1));

	// Print the address of the second item in the array.
	printf("str[1]: %p\n", (str + 1));

	// Create a new pointer to the second item in the array.
	char* secondPtr = str + 1;

	printf("str ptr (again): %p\n", str);
	printf("secondPtr: %p\n", secondPtr);

	for (int i = 0; i < strlen(str); i++) {
		printf("For Loop [%d]: %c Address: %p\n", i, (*str + i), (str + i));
	}

}

// Forward declaration of a function called elsewhere.
void printJ(int* j);

/***********************************************************************
 * NAME:		derefInt()
 *
 * DESCRIPTION:	Runs various tests using an int pointer.
 *
 *
 */
void derefInt() {
	int i = 1;

	// Define a pointer (the address of i) and point it to i.
	int* ptr = &i;

	printf("Value of i is %d\n", i);
	printf("Pointer to i is %p\n", ptr);

	int j = 12;

	printJ(&j);
}

/***********************************************************************
 * NAME:		printJ()
 *
 * INPUT:		A pointer to an int.
 *
 * DESCRIPTION:	Internal function tha simply prints out the address of
 * 				the pointer and its value by dereferencing the point.
 *
 *
 */
void printJ(int* j) {

	// Dereference the pointer to it's actual value.
	int k = *j;

	printf("J actual value: %d\n", k);
	printf("Pointer to J: %p\n", j);
}
