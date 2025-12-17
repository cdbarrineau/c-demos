/*
 * structs.h
 *
 *  Created on: Nov 2, 2025
 *      Author: mark2v
 */

#ifndef INCLUDE_STRUCTS_H_
#define INCLUDE_STRUCTS_H_

/*
 * Typical non-named struct.
 */
struct point1 {
	int x;
	int y;
	int z;
};

/**
 * Named struct.
 */
typedef struct {
	int x;
	int y;
	int z;
} point;

// Used to allocate the struct and the string inside of it.
typedef struct {
	char* str;
	int len;
} inner_data;

typedef struct {
	point p;
	inner_data id;
} outer_point;


/***********************************************************************
 * NAME:		test_outer_struct()
 *
 * DESCRIPTION:	Runs a test on the outer_point structure.
 *
 *
 */
void test_outer_struct();

/***********************************************************************
 * NAME:		test_malloc()
 *
 * DESCRIPTION:	Runs a test on the with mallocing a structure.
 *
 *
 */
void test_malloc();

/***********************************************************************
 * NAME:		test_unnamed()
 *
 * DESCRIPTION:	Runs a test on tan unnamed structure.
 *
 *
 */
void test_unnamed();


#endif /* INCLUDE_STRUCTS_H_ */
