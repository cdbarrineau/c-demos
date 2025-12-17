/*
 * array_of_structs.h
 *
 *  Created on: Dec 16, 2025
 *  Author: mark2v
 */

#ifndef INCLUDE_ARRAY_OF_STRUCTS_H_
#define INCLUDE_ARRAY_OF_STRUCTS_H_

// From K&R book page 118.


// Can't do it this way, must be done with unnamed way.
//typedef struct {
//	char *word;
//	int count;
//} keytab[] = {
//	{"", 0}
//};

// Can not define this in include file because
// it gets defined in more than one source file.
//struct key {
//	char *word;
//	int count;
//} keytab[] = {
//	{ "auto", 0 }
//};

/***********************************************************************
 * NAME:		test_array_structs()
 *
 * DESCRIPTION:	Tests an array of structures.
 *
 *
 */
void test_array_structs();

#endif /* INCLUDE_ARRAY_OF_STRUCTS_H_ */
