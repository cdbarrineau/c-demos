/*
 * hello_world.c
 *
 *  Created on: Oct 11, 2025
 *      Author: mark2v
 */

#include <stdio.h>

#include "bool.h"

int main() {
	printf ("Hello, World!");

	for (int i = 0; i < 10; i++) {
		const char b = i % 2 == 0 ? TRUE : FALSE;

		printf ("\n%d is %d", i, b);
	}

	return 0;
}

