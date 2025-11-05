/*
 * main.c
 *
 *  Created on: Nov 2, 2025
 *      Author: mark2v
 */
#include <stdio.h>

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
	printf("(1) x=%d, y=%d, z=%d\n", p.x, p.y, p.z);

	// Since the function is pass by value the returned address will
	// be different because it creates a copy of the returned value
	// even though in the function we're returning the address of the
	// passed in struct.  But the values in the returned struct WILL be
	// the updated values that the function updates however the original
	// p will not be modified.
	point p2 = add_one_pass_by_value(p);
	printf("Address of returned p2: %p\n", &p2);
	printf("(2) x=%d, y=%d, z=%d\n", p2.x, p2.y, p2.z);

//	add_one_pass_by_ref(&p);

//	printf("(3) x=%d, y=%d, z=%d\n", p.x, p.y, p.z);

	// Compiler warning on this one as the function returns the address of a local var.
//	point* p2 = add_one_pbv(p);
//	printf("Address of p2: %p\n", &p2);

	point pc = create(1, 2, 3);
	printf("Address of created pc: %p\n", &pc);
	printf("(3) x=%d, y=%d, z=%d\n", pc.x, pc.y, pc.z);

	return 0;
}

