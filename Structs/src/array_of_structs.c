/*
 * array_of_structs.c
 *
 *  Created on: Dec 30, 2025
 *  Author: mark2v
 */
#include <stdio.h>

#include "../include/array_of_structs.h"

struct key {
	char *word;
	int count;
} keytab[] = {
	{ "auto", 0 },
	{ "break", 1 },
	{ "case", 2 },
	{ "char", 3 }
};

#define NUM_KEYS (sizeof(keytab) / sizeof(keytab[0]))

/***********************************************************************
 * NAME:		test_array_of_structs()
 *
 * DESCRIPTION:	Runs various tests using an array of structures.
 *
 */
void test_array_of_structs() {

	printf("*****  test_array_of_structs  *****\n");

	// Type if NUM_KEYS is a long unisgned int so "lu".
	printf("Number of keytabs: %lu\n", NUM_KEYS);

	// Print out each keytab.
	for (int i = 0; i < NUM_KEYS; i++) {
		printf("keytab[%d] word = %s count = %d\n", i, keytab[i].word, keytab[i].count);
	}
}

