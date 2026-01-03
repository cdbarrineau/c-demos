/*
 * externs.c
 *
 *  Created on: Jan 3, 2026
 *  Author: mark2v
 */
#include <stdio.h>
#include <string.h>

#include "../include/externs.h"

#define MAX 15

int sp = 0;
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
