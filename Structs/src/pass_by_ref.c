/*
 * pass_by_ref.c
 *
 *  Created on: Dec 30, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/pass_by_ref.h"

struct MyStruct {
	int i;
};

struct {
	int i;
} ms_two_t;

void modify_pbr_struct_values(PbrStruct *s);
void modify_pbr_struct_addr(PbrStruct *s);
PbrStruct* modify_pbr_struct_ptr(PbrStruct *s);
void modify_pbr_struct_ptr2(PbrStruct **s);

/***********************************************************************
 * NAME:		pass_by_ref()
 *
 * DESCRIPTION:	Tests passing structs by value.  Here whatever mods are
 * 				made to the struct itself are not persisted between calls
 * 				even to the contents in the struct are not persisted.
 */
void pass_by_ref() {

	struct MyStruct ms;
	ms.i = 10;

	struct MyStruct ms2;
	ms2.i = 20;

	printf("ms.i  = %d\n", ms.i);
	printf("ms2.i = %d\n", ms2.i);

	ms_two_t.i = 90;

	printf("\n");


	printf("*****  pass_by_ref  *****\n");

	/*
	 * NOTE: This works the same exact way for char* too!
	 */

	PbrStruct s = { .id = 1, .name = "Hello" };

	printf("BEFORE modify: id = %d, name = %s, addr = %p\n", s.id, s.name, &s);

	modify_pbr_struct_values(&s);

	printf("AFTER modify values: id = %d, name = %s, addr = %p\n", s.id, s.name, &s);

	modify_pbr_struct_addr(&s);

	printf("AFTER modify struct: id = %d, name = %s, addr = %p\n", s.id, s.name, &s);

	PbrStruct *s3 = modify_pbr_struct_ptr(&s);
	if (s3 == NULL) {
		return;
	}

	printf("AFTER modify struct ptr: id = %d, name = %s, addr = %p\n", s.id, s.name, &s);

	free(s3);

	PbrStruct *s2 = (PbrStruct*)malloc(sizeof(PbrStruct));
	if (s2 == NULL) {
		fprintf(stderr, "Unable to allocate memory!");
		return;
	}

	(*s2).id = 2;
	(*s2).name = "Hello 2";

	printf("BEFORE modify struct ptr: id = %d, name = %s, addr = %p\n", (*s2).id, (*s2).name, s2);

	s3 = modify_pbr_struct_ptr(s2);
	if (s3 == NULL) {
		return;
	}

	printf("AFTER modify struct ptr: id = %d, name = %s, addr = %p\n", (*s2).id, (*s2).name, s2);

	free(s2);
	free(s3);

	s2 = (PbrStruct*)malloc(sizeof(PbrStruct));
	if (s2 == NULL) {
		fprintf(stderr, "Unable to allocate memory!");
		return;
	}

	(*s2).id = 2;
	(*s2).name = "Hello 2";

	// Passing a pointer to the pointer makes the new struct in this function stick.
	modify_pbr_struct_ptr2(&s2);

	printf("AFTER modify struct dbl ptr: id = %d, name = %s, addr = %p\n", (*s2).id, (*s2).name, s2);

	/*
	 * This causes a double-free because in the above struct we're not
	 * mallocing so s2 leaks but for this test that's OK, we typically
	 * would not do things this way.
	 */
//	free(s2);

	// Again, passing the address to the address makes the new struct stick.
	PbrStruct s4 = { .id = 40, .name = "Forty" };
	PbrStruct *s5 = &s4;

	modify_pbr_struct_ptr2(&s5);

	printf("AFTER modify struct dbl ptr 2: id = %d, name = %s, addr = %p\n", (*s5).id, (*s5).name, s5);

}

/***********************************************************************
 * NAME:		modify_pbr_struct_values()
 *
 * DESCRIPTION:	Modifies the contents of the struct.  These values will
 * 				remain after this function returns because we're passing
 * 				by reference (address) so no copy is made like in PBV,
 * 				the actual memory address is passed.
 */
void modify_pbr_struct_values(PbrStruct *s) {

	(*s).id = 2;
	(*s).name = "Goodbye";
}

/***********************************************************************
 * NAME:		modify_pbr_struct_addr()
 *
 * DESCRIPTION:	Attempts to create a new struct and assign it's address
 * 				to the passed in struct.  This will NOT persist after
 * 				this function returns because ???
 */
void modify_pbr_struct_addr(PbrStruct *s) {

	PbrStruct s2 = { .id = 20, .name = "Goodbye Again" };

	s = &s2;
}

/***********************************************************************
 * NAME:		modify_pbr_struct_values()
 *
 * DESCRIPTION:	Allocates new memory and assigns it to the passed in
 * 				struct.  This also will not stick because the struct
 * 				is passed in.
 */
PbrStruct* modify_pbr_struct_ptr(PbrStruct *s) {

	PbrStruct *s2 = (PbrStruct*)malloc(sizeof(PbrStruct));
	if (s2 == NULL) {
		fprintf(stderr, "Unable to allocate memory!");
		return NULL;
	}

	(*s2).id = 10;
	(*s2).name = "Goodbye Again";

	s = s2;

	// This prints out the malloc'd address however,
	// after this function returns, "s" will still
	// point to the original address.
	printf("modify_pbr_struct_ptr s = %p\n", s);

	return s2;
}

/***********************************************************************
 * NAME:		modify_pbr_struct_ptr2()
 *
 * DESCRIPTION:	Assigns a new struct to the passed in one.  This WILL
 * 				stick because we're passing a reference to the pointer.
 */
void modify_pbr_struct_ptr2(PbrStruct **s) {

	PbrStruct s2 = { .id = 10, .name = "Goodbye Again2" };

	(*s) = &s2;
}


