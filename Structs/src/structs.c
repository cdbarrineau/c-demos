/*
 * structs.c
 *
 *  Created on: Nov 3, 2025
 *      Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/structs.h"

/***********************************************************************
 * NAME:		new_inner_data()
 *
 * DESCRIPTION:	Creates a new inner_data struct with it and the char*
 *              data initialized.
 *
 * INPUTS:		str_size - The number of bytes to allocate for the data string.
 *
 * OUTPUTS:		Returns a pointer to the inner data struct.
 *
 */
inner_data* new_inner_data(int str_size) {
	inner_data* data = (inner_data*)malloc(sizeof(inner_data));

	if (data == NULL) {
		return NULL;
	}

	data->str = (char*)malloc(str_size);
	if (data->str == NULL) {
		free(data);

		return NULL;
	}

	data->str[0] = '\0';

	return data;
}

/***********************************************************************
 * NAME:		free_inner_data()
 *
 * DESCRIPTION:	Frees all data in the provided struct.
 *
 * INPUTS:		data - The data to free..
 *
 * OUTPUTS:		None.
 *
 */
void free_inner_data(inner_data* data) {
	if (data != NULL) {
		if (data->str != NULL) {
			free(data->str);
		}

		free(data);
	}
}

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

point* create_ptr() {
	point* p = (point*)malloc(sizeof(point));
	p->x = 10;
	p->y = 11;
	p->z = 12;

	(*p).x = 10;

	printf("Address of create_ptr(): %p\n", p);

	return p;
}

void change_outer(outer_point *op) {
	op->id.len = 6;
	op->id.str = "OneTwo";

	(*op).p.x = 10;
	(*op).p.y = 20;

}

/***********************************************************************
 * NAME:		test_outer_struct()
 *
 * DESCRIPTION:	Runs a test on the outer_point structure.
 *
 *
 */
void test_outer_struct() {

	printf("\n***** test_outer_struct *****\n");

	inner_data id;
	id.len = 3;
	id.str = "One";

	point p;
	p.x = 1;
	p.y = 2;
	p.z = 3;

	outer_point op;
	op.id = id;
	op.p = p;

	change_outer(&op);

	printf("op.id.len = %d\n", op.id.len);
	printf("op.p.x = %d\n", op.p.x);
}

/***********************************************************************
 * NAME:		test_malloc()
 *
 * DESCRIPTION:	Runs a test on the with mallocing a structure.
 *
 *
 */
void test_malloc() {

	printf("\n***** test_malloc *****\n");

	// ---------------  Create struct with inner malloc array and init 0-9 ---

	int str_len = 10;

	inner_data* in_data = new_inner_data(str_len);
	if (in_data == NULL) {
		fprintf(stderr, "Unable to allocate inner_data");
	}

	// In ASCII, 0 starts on the integer 48:
	// https://www.asciitable.com/

	// That's the reason we can just add 0 to i because it
	// will set i to 48 + whatever i is equal.
	int j = (int)'0';

	printf("%d\n", j);

	for (int i = 0; i < str_len; i++) {
		// To convert from an int to a char, simply add the char '0';
		in_data->str[i] = i + '0';
	}

	printf("in_data->str = %s\n", in_data->str);
	printf("in_data->str length = %lu\n", strlen(in_data->str));

	free_inner_data(in_data);
}

/***********************************************************************
 * NAME:		test_unnamed()
 *
 * DESCRIPTION:	Runs a test on tan unnamed structure.
 *
 *
 */
void test_unnamed() {

	printf("\n***** test_unnamed *****\n");

	// Create an unnamed struct.
	struct point1 p1;
	p1.x = 10;
	p1.y = 20;
	p1.z = 30;

	printf("P1 x=%d, y=%d, z=%d\n", p1.x, p1.y, p1.z);

	point p;
	p.x = 100;
	p.y = 200;
	p.z = 300;

	printf("(0) x=%d, y=%d, z=%d\n", p.x, p.y, p.z);

	// Here, the address printed in the function is different than the address
	// of p here because the function is pass-by-value.
	// Also, since it's passed by value the updates to the data are not set
	// on the struct after it returns--it's the initial values from above.
	printf("Address of p: %p\n", &p);
	point ret_p = add_one_pass_by_value(p);
	printf("Values do not change: x=%d, y=%d, z=%d\n", p.x, p.y, p.z);

	printf("Returned point: x=%d, y=%d, z=%d\n\n", ret_p.x, ret_p.y, ret_p.z);

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


	printf("Next two pointer addresses are the same\n");
	point* ptr_to_point = create_ptr();
	printf("Address of ptr_to_point: %p\n", ptr_to_point);
	printf("ptr_to_point: x=%d, y=%d, z=%d\n\n", ptr_to_point->x, ptr_to_point->y, ptr_to_point->z);

	free(ptr_to_point);
}
