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
//struct point1 {
//	int x;
//	int y;
//	int z;
//};

/**
 * Named struct.
 */
typedef struct {
	int x;
	int y;
	int z;
} point;


/***********************************************************************
 * NAME:		add_one_pass_by_value(pint)
 *
 * DESCRIPTION:	Increments the data in the point by one.  This value is passed
 * 				by value so upon returning, the values will remain unchanged.
 * 				However, the returned point WILL indeed have the correct
 * 				incremented values.
 *
 * INPUTS:		p the point.
 *
 * OUTPUTS:		point Returns the point passed in with the correctly incremented
 * 				values.
 *
 */
point add_one_pass_by_value(point p);

//point* add_one_pbv(point p);

/***********************************************************************
 * NAME:		add_one_pass_by_ref(point)
 *
 * DESCRIPTION:	Increments the data in the point by one.  This value is passed
 * 				by reference so upon returning, the values will be changed since
 * 				we are passing in a pointer to the memory location of p.
 *
 * INPUTS:		p the point.
 *
 * OUTPUTS:		point Returns the point passed in with the correctly incremented
 * 				values.
 *
 */
point* add_one_pass_by_ref(point* p);

/***********************************************************************
 * NAME:		create(int, int, int)
 *
 * DESCRIPTION:	Creates and returns a point struct.
 *
 * INPUTS:		x the point's X.
 *              y the point's Y.
 *              z the point's Z.
 *
 * OUTPUTS:		point Returns the new point struct.
 *
 */
point create(int x, int y, int z);

point* create_ptr();

#endif /* INCLUDE_STRUCTS_H_ */
