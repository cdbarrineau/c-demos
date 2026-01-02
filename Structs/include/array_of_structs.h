/*
 * array_of_structs.h
 *
 *  Created on: Dec 30, 2025
 *  Author: mark2v
 */

#ifndef INCLUDE_ARRAY_OF_STRUCTS_H_
#define INCLUDE_ARRAY_OF_STRUCTS_H_

/*
 * Need static here because if not then because this file
 * is included in multiple .c files, get multiple definitions
 * of keytab.
 *
 * Problem with static is that it breaks encapsulation.  That's fine
 * if that's the intent but probably not.
 */
//struct key {
//	char *word;
//	int count;
//} static keytab[] = {
//	{ "auto", 0},
//	{ "break", 0 },
//	{ "case", 0 },
//	{ "char", 0 }
//};

//#define NUM_KEYS (sizeof(keytab) / sizeof(keytab[0]))



/***********************************************************************
 * NAME:		test_array_of_structs()
 *
 * DESCRIPTION:	Runs various tests using an array of structures.
 *
 */
void test_array_of_structs();

#endif /* INCLUDE_ARRAY_OF_STRUCTS_H_ */
