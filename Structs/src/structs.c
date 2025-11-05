/*
 * structs.c
 *
 *  Created on: Nov 3, 2025
 *      Author: mark2v
 */
#include <stdio.h>

#include "../include/structs.h"

/***********************************************************************
 * NAME:		add_one_pass_by_value(point)
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
point add_one_pass_by_value(point p) {
	p.x++;
	p.y++;
	p.z++;

	printf("Address 1 passed in (and return value): %p\n", &p);

	// This will return a copy of p so the returned addess will be different.
	return p;
}

//point* add_one_pbv(point p) {
//	p.x++;
//	p.y++;
//	p.z++;
//
//	printf("Address 2 passed in: %p\n", &p);
//
//	// Compiler warning: function returns address of local variable.
//	return &p;
//}

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
point* add_one_pass_by_ref(point* p) {

	// Can access the data either way (dereference here:
//	(*p).x++;
//	(*p).y++;
//	(*p).z++;

//	printf("Address passed in 2: %p\n", p);

	// But let's do it the standard pointer way.
	p->x++;
	p->y++;
	p->z++;

	return p;
}


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
point create(int x, int y, int z) {
	point p;
	p.x = x;
	p.y = y;
	p.z = z;

	return p;
}



