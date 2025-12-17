/*
 * array_of_structs.c
 *
 *  Created on: Dec 16, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/array_of_structs.h"

// Must define this in a source file because doing it
// in an include file, that include gets lined in by
// multiple source files, get multiple definitions error.
struct key {
	char *word;
	int count;
} keytab[] = {
	{ "auto", 0 },
	{ "break", 0 },
	{ "case", 0 },
	{ "char", 0 }
};


// or sizeof(struct key) however, defining it above, that line
// does not need to change if the type changes.
#define NKEYS (sizeof(keytab) / sizeof(keytab[0]))

/***********************************************************************
 * NAME:		test_array_structs()
 *
 * DESCRIPTION:	Tests an array of structures.
 *
 *
 */
void test_array_structs() {

	printf("keytab is 8 char* and * int so 64 bytes.\n");
	printf("sizeof(keytab): %zu\n", sizeof(keytab));

	printf("sizeof(keytab[0].word): %zu\n", sizeof(keytab[0].word));

	printf("NKEYS = %lu\n", NKEYS);

	for (int i = 0; i < NKEYS; i++) {
		struct key s = keytab[i];

		printf("keytab[%d] = %s, %d\n", i, s.word, s.count);
	}
}

