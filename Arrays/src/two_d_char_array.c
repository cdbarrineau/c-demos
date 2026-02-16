/*
 * two_d_char_array.c
 *
 *  Created on: Oct 12, 2025
 *      Author: mark2v
 */
#include <stdio.h>
#include "../include/two_d_char_array.h"

#define Y 5

/***********************************************************************
 * NAME:		two_d_char_array()
 *
 * DESCRIPTION:	Creates and iterates a 2-D char array and prints the result.
 *
 */
void two_d_char_array() {
	int x = 2;

	// Cannot have x or y in this kind of array, must be a constant.
	char string[][Y] = {
	    {'A', 'E', 'I', 'O', 'U'},
	    {'a', 'e', 'i', 'o', 'u'}
	};

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < Y; j++) {
			printf ("Item [%d][%d] is %c\n", i, j, string[i][j]);
		}
	}
}
