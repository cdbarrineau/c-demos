/*
 * externs.c
 *
 *  Created on: Jan 3, 2026
 *  Author: mark2v
 */
#include <stdio.h>
#include <string.h>

#include "../include/externs.h"

/***********************************************************************
 * NAME:		test_pre_dec()
 *
 * DESCRIPTION:	Tests the extern when the formal definition has not
 * 				beed made yet.
 */
void test_pre_dec() {

	printf("*****  test_pre_dec  *****\n");
	printf("sp = %d\n", sp);
}

#define MAX 15

int sp = 1;
char arr[MAX];

/***********************************************************************
 * NAME:		test_extern()
 *
 * DESCRIPTION:	Tests the extern keyword.
 */
void test_extern() {

	printf("*****  test_extern  *****\n");

	strncpy(arr, "EXTERN TEST", MAX);

	printf("arr = %s\n", arr);
}
