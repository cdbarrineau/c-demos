/*
 * one_d_array.c
 *
 *  Created on: Oct 12, 2025
 *      Author: mark2v
 */

#include <stdio.h>
#include "../include/one_d_array.h"

void one_d_array() {
	int numItems = 10;

	int numbers[numItems];

	for (int i = 0; i < numItems; i++) {
		numbers[i] = i * 2;
	}

	for (int i = 0; i < numItems; i++) {
		printf("Number at index %d is %d\n", i, numbers[i]);
	}
}

