/*
 * arr.c
 *
 *  Created on: Oct 12, 2025
 *      Author: mark2v
 */

#include <stdio.h>

#include "../include/two_d_array.h"

/***********************************************************************
 * NAME:		two_d_array()
 *
 * DESCRIPTION:	Creates and iterates a 2-D array and prints the result.
 *
 */
void two_d_array() {
	int x = 5;
	int y = 3;

	int arr[x][y];

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			arr[i][j] = (i * 2) + (j * 3);
		}
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
				printf ("Item [%d][%d] is %d\n", i, j, arr[i][j]);
		}
	}
}
