/*
 * sum.c
 *
 * Shows how static variables inside of a function live past the function
 * invocation and maintain their value acorss different invocations.
 *
 *  Created on: Oct 18, 2025
 *      Author: mark2v
 */
#include <stdio.h>

/*
 * Forward-declare the function.  Needed if we're going to be calling it
 * before it's defined--we can just tell the compiler that we're defining
 * the implementation later.
 */
int sum(int to_add);


int main() {

	for (int i = 0; i < 10; i++) {
		printf("Sum adding %d: %d\n", (i + 1), sum(i + 1));
	}

	return 0;
}

/***********************************************************************
 * NAME:		sum(int)
 *
 * DESCRIPTION:	Adds the specified value to a running total.
 *
 * INPUTS:		int to_add The amount to add to the running total.
 *
 * OUTPUTS:		int Returns The new total.
 *
 */
int sum(int to_add) {
	static int total = 0;

	total += to_add;

	return total;
}


