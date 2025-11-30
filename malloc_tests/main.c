/*
 * main.c
 *
 *  Created on: Nov 22, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/one_d.h"


/**********************************************************************
 * Print 1 - 10 using the ASCII codes (0 in ASCII is 48 decimal).
 *
 */
void do_one_d_test() {

	int num_items = 10;

	char* list = (char*)malloc(sizeof(char) * (num_items + 1));
	list[0] = '\0';

	for (int i = 0; i < num_items; i++) {
		list[i] = i + 48;
	}

	// Always put a null at the end when assigning indexes directly.
	// build-in functions like strcat and whatnot will do this automagically.
	list[num_items - 1] = '\0';

	for (int i = 0; i < num_items; i++) {
		printf("list[%d] = %c\n", i, list[i]);

	}

	free(list);
}

void do_two_d_test() {

	/*
	 * char**  Each column is a char* so char** is just a list of char*
	 * 	- The whole char** is terminated by NULL.
	 * 	- Each char* string is terminated by NULL.
	 * 		- For each of these, need to allocate +1 to the size.
	 * -----------------------------------
	 * 		char*  | "Value 1" + \0
	 * 		char*  | "Value 2" + \0
	 * 		char*  | "Value 3" + \0
	 * 		char*  | "Value 4" + \0
	 * 		char*  | "Value 5" + \0
	 * 		char*  | "Value 6" + \0
	 * 		char*  | "Value 7" + \0
	 *		\0
	 */

	// Number of items in the outer array.
	int num_items = 10;

	// The size of the inner arrays to accommodate things like "Item: 1"
	int size_of_inner_str = 15;

	// Allocate enough space for a char pointer times the number of items
	// in the array plus 1 for the ASCII NUL (\0).
	// Make sure to assign the allocated memory to \0 (not NULL but ASCII NUL) char.
	char** list = (char**)malloc(sizeof(char*) * (num_items + 1));
	list[0] = NULL;
	for (int i = 0; i < num_items; i++) {

		// Allocate enough space for the char pointer timed the size of
		// each inner array plus one for the ASCII NUL (\0).
		// Make sure to assign the allocated memory to \0 (not NULL but ASCII NUL) char.
		list[i] = (char*)malloc(sizeof(char) * (size_of_inner_str + 1));
		list[i][0] = '\0';

		// Buffer, max num, string with format.
		snprintf(list[i], (size_of_inner_str + 1), "%d - Some Really Long String Here", i);
	}

	for (int i = 0; i < num_items; i++) {
		printf("Item [%d] = %s\n", i, list[i]);
	}

	for (int i = 0; i < num_items; i++) {
		free(list[i]);
	}

	free(list);
}

void do_md_test() {
	// Total number of arrays in the char**
	int num_items = 10;

	// Length of each inner char array in bytes.
	int inner_len = 20;

	char** arr = (char**)malloc(sizeof(char**) * (num_items + 1));   // Make sure to add one for NULL terminator.
	arr[0] = NULL;

	char* item = (char*)malloc(sizeof(char*) * (inner_len + 1)); // Make sure to add one for NULL terminator.
	item[0] = '\0';

	snprintf(item, inner_len + 1, "%d - Some Really Long Test String", 0);

	arr[0] = item;

	printf(arr[0]);

	free(arr[0]);
	free(arr);
}

int main() {

//	print_zero_to_nine();

	print_zero_to_nine_list();

//	do_one_d_test();
//
//	do_two_d_test();

//	do_md_test();

	return 0;
}

