/*
 * strings.c
 *
 *  Created on: Oct 28, 2025
 *      Author: mark2v
 */

#include <stdio.h>

#include "../include/strings.h"

/***********************************************************************
 * NAME:		doStr()
 *
 * DESCRIPTION:	Tests a string array as a pointer printing out the values
 * 				at each index.  Also prints out past the length of the string
 * 				in order to print out the random bytes of memory not allocated.
 *
 *
 */
void doStr() {

	char* name = "John";
	for (int i = 0; i < 30; i++) {
		if (name[i] == '\0') {
			printf("Found EOL at index %d\n", i);
		}
		printf("%d = %c\n", i, name[i]);
	}
}


