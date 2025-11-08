/*
 * main.c
 *
 *  Created on: Nov 2, 2025
 *      Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/structs.h"


int main() {

	// Create an unnamed struct.
//	struct point1 p1;
//	p1.x = 10;
//	p1.y = 20;
//	p1.z = 30;
//
//	printf("P1 x=%d, y=%d, z=%d\n", p1.x, p1.y, p1.z);

	point p;
	p.x = 100;
	p.y = 200;
	p.z = 300;

//	printf("(0) x=%d, y=%d, z=%d\n", p.x, p.y, p.z);

	// Here, the address printed in the function is different than the address
	// of p here because the function is pass-by-value.
	// Also, since it's passed by value the updates to the data are not set
	// on the struct after it returns--it's the initial values from above.
	printf("Address of p: %p\n", &p);
	add_one_pass_by_value(p);
	printf("Values do not change: x=%d, y=%d, z=%d\n\n", p.x, p.y, p.z);

	// Since the function is pass by value the returned address will
	// be different because it creates a copy of the returned value
	// even though in the function we're returning the address of the
	// passed in struct.  But the values in the returned struct WILL be
	// the updated values that the function updates however the original
	// p will not be modified.
	point p2 = add_one_pass_by_value(p);
	printf("Address of returned p2: %p\n", &p2);
	printf("PBV values no not change: x=%d, y=%d, z=%d\n", p.x, p.y, p.z);
	printf("Returned point values changed: x=%d, y=%d, z=%d\n\n", p2.x, p2.y, p2.z);

	// Passing by reference.  Address of p will be the same after the
	// call returns and the updates to the x, y, & z will be set to
	// what the function set them to.
	add_one_pass_by_ref(&p);
	printf("Address of p (again): %p\n", &p);
	printf("PBR values changed: x=%d, y=%d, z=%d\n\n", p2.x, p2.y, p2.z);

	// Modify p2.  Even though it was returned as the arg of p, this will
	// not change p because the compiler made of copy when returning the
	// passed in point, p.
	p2.x = 1;
	p2.y = 2;
	p2.z = 3;

	printf("Modified return p2. Original p is unmodified: x=%d, y=%d, z=%d\n", p.x, p.y, p.z);
	printf("Modified return p2. Point values changed: x=%d, y=%d, z=%d\n\n", p2.x, p2.y, p2.z);


//	printf("(3) x=%d, y=%d, z=%d\n", p.x, p.y, p.z);

	// Compiler warning on this one as the function returns the address of a local var.
//	point* p2 = add_one_pbv(p);
//	printf("Address of p2: %p\n", &p2);

	point pc = create(1, 2, 3);
	printf("Address of created pc: %p\n\n", &pc);
//	printf("(3) x=%d, y=%d, z=%d\n\n", pc.x, pc.y, pc.z);

//	printf("short: %d bytes\n", sizeof(short));
//	printf("long: %d bytes\n", sizeof(long));
//	printf("long long: %d bytes\n", sizeof(long long));
//	printf("double: %d bytes\n", sizeof(double));


	point* ptr_to_point = create_ptr();
	printf("Address of ptr_to_point: %p\n", ptr_to_point);
	printf("ptr_to_point: x=%d, y=%d, z=%d\n\n", ptr_to_point->x, ptr_to_point->y, ptr_to_point->z);

	free(ptr_to_point);

	return 0;
}

