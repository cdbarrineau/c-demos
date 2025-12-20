/*
 * p_struct.c
 *
 *  Created on: Dec 17, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/p_struct.h"

void do_stuff_struct(p_struct ps);
void do_stuff_ps(p_struct *ps);
void change_addr(p_struct ps);
void print_name(char *name);

/***********************************************************************
 * NAME:		test_pbv()
 *
 * DESCRIPTION:	Tests struct pass by value.  This shows that passing
 * 				a struct by value does not alter the structure however,
 * 				it will alter the contents of the structre.
 *
 */
void test_pbv() {

	printf("\n*****  Pass by Value  *****\n");

	p_struct s;
	s.name = "One";
	s.id = 1;

	print_name(s.name);

	printf("&s = %p\n", &s);

	// This will NOT modify the contents of the struct.
	do_stuff_struct(s);

	printf("s.name = %s - s.id = %d\n", s.name, s.id);

	// Test with a pointer to the struct.
	// This WILL modify the contents of the struct.
	do_stuff_ps(&s);

	printf("s.name = %s - s.id = %d\n", s.name, s.id);
}

/***********************************************************************
 * NAME:		test_pba()
 *
 * DESCRIPTION:	Tests struct pass by address (reference).  This shows
 * 				that passing a struct by address will alter the struc
 * 				itself.
 *
 */
void test_pba() {

	printf("\n*****  Pass by Address  *****\n");
	p_struct *ps = malloc(sizeof(p_struct));
	(*ps).name = "One";
	(*ps).id = 1;

	printf("ps = %p\n", ps);
	printf("ps.name = %s - ps.id = %d\n", (*ps).name, (*ps).id);

	// This WILL modify the contents of the struct.
	do_stuff_ps(ps);

	printf("ps.name = %s - ps.id = %d\n", (*ps).name, (*ps).id);

	// This will NOT modify the contents or the address of the struct itself.
	do_stuff_struct(*ps);

	printf("ps.name = %s - ps.id = %d\n\n", (*ps).name, (*ps).id);

	// This will NOT change the address to this one.
	change_addr(*ps);
	printf("ps = %p\n", ps);
	printf("ps.name = %s - ps.id = %d\n", (*ps).name, (*ps).id);

	free(ps);
}


/***********************************************************************
 * NAME:		do_stuff_struct()
 *
 * DESCRIPTION: Illustrates that the passed in struct is a deep copy,
 * 				meaning	a whole new object with a different address.
 * 				This is a lot less efficient than passing by address
 * 				however, PBA will allow the contents of the struct to
 * 				be modified, this will not.
 *
 */
void do_stuff_struct(p_struct s) {

	printf("\n*  do_stuff_struct *\n");

	s.name = "Two";
	s.id = 2;

	printf("*  &s = %p\n", &s);
	printf("*  s.name = %s - s.id = %d\n", s.name, s.id);
	printf("*  END  *\n\n");
}



/***********************************************************************
 * NAME:		do_stuff_ps()
 *
 * DESCRIPTION:
 *
 */
void do_stuff_ps(p_struct *ps) {

	printf("\n*  do_stuff_ps *\n");

	// Modifying these will still be modified after this function returns.
	(*ps).name = "Three";
	(*ps).id = 3;

	printf("*  ps = %p\n", ps);
	printf("*  ps.name = %s - ps.id = %d\n", (*ps).name, (*ps).id);
	printf("*  END  *\n\n");
}


/***********************************************************************
 * NAME:		change_addr()
 *
 * DESCRIPTION:
 *
 */
void change_addr(p_struct ps) {
	p_struct ps2;
	ps2.name = "Four";
	ps2.id = 4;

	ps = ps2;

	printf("*  Changed address to %p\n", &ps);
}


/***********************************************************************
 * NAME:		print_name()
 *
 * DESCRIPTION:
 *
 */
void print_name(char *name) {

	printf("\n*  print_name() *\n");
	while (*name) {
		printf("name -> %s\n", name++);
	}

	printf("*  Done with print_name()  *\n");
}

/***********************************************************************
 * NAME:		test_unnamed_struct()
 *
 * DESCRIPTION:	Tests an unnamed struct.
 *
 */
void test_unnamed_struct() {

	printf("\n*****  Unnamed Struct  *****\n");

	struct un_struct us;

	us.name = "Ten";
	us.id = 10;

	printf("us.name = %s - id = %d\n", us.name, us.id);
}




















//
//
//
//
//
//
//
//
//void traverse_name(p_struct *ps);
//
//void struct_pbv(p_struct ps);
//void struct_pb_ptr(p_struct *ps);
//
//void print_str(char *p) {
//
//	/*
//	 * While the address is the same, a copy of the char*
//	 * is passed which means that we can modify the pointer
//	 * but when it returns, the mods are not there in the
//	 * calling function.
//	 */
//	printf("***  print_str  ***\n");
//
//	printf("p = %p\n", p);
//
//	while (*p) {
//		printf("*p = %s\n", p++);
//	}
//}
//
//void change_str(char *p) {
//
//	/**
//	 * This will change the value in [0]
//	 */
////	p[0] = '8';
//
//	// This will not change it as it's changing the copy of the
//	// pointer value itself passed in.
//	p = "8";
//}
//
//
///***********************************************************************
// * NAME:		test_array_structs()
// *
// * DESCRIPTION:	Tests struct pointer.
// *
// *
// */
//void test_p_struct() {
//
//	p_struct *ps = malloc(sizeof(p_struct));
//	(*ps).id = 10;
//	(*ps).name = (char*)malloc(sizeof(char) * 4);
//	*(*ps).name = '\0';
//	snprintf((*ps).name, 4, "One");
//
//	printf("ps = %p\n", ps);
//	printf("ps->name = %p\n", ps->name);
//
//	print_str(ps->name);
//
//	change_str(ps->name);
//
//	printf("(ptr) ps->name = %p\n", ps->name);
//
//	printf("(str) ps->name = %s\n", ps->name);
//
//	// Apparently the char* inside the struct is pass by reference?
//	traverse_name(ps);
//
//	printf("(*ps).name = %s\n", (*ps).name);
//
//	free((*ps).name);
//	free(ps);
//}
//
//
//
//
//
//void test_char(char *name) {
//	printf("\n** test_char **\n");
//
//	name = "Three";
//
//	printf("name = %p\n", name);
//	printf("name = %s\n", name);
//}
//
///***********************************************************************
// * NAME:		test_pass_by_value()
// *
// * DESCRIPTION:	Tests struct pass by value.  Specifically the char*
// * 				inside the structure.
// *
// *
// */
//void test_pass_by_value() {
//	p_struct *ps = malloc(sizeof(p_struct));
//	(*ps).name = "One";
//	(*ps).id = 5;
//
//	printf("ps = %p\n", ps);
//
//	/*
//	 * Passing a pointer to a struct passed by value HOWEVER,
//	 * can still modify the contents of the struct.  So, in
//	 * a function you can assign a new struct to the passed in
//	 * pointer but upon returning, it does not change the ptr to
//	 * the struct.
//	 *
//	 * So if pass a pointer to a struct into another function,
//	 * this is passed-by-address.  In order to not have the members
//	 * of the struct changed in the function, pass a dereferenced
//	 * pointer into a function that takes the struct itself--not
//	 * the pointer to it.
//	 *
//	 * However, passing just a char* by address (pointer), works fine.
//	 */
//
////	test_char(ps->name);
//
////	printf("ps->name = %p\n", ps->name);
////	printf("ps->name = %s\n", ps->name);
////
////	struct_pbv(*ps);
//
//	printf("ps->name = %p\n", ps->name);
//	printf("ps->name = %s - ps->id = %d\n", ps->name, ps->id);
//
//	struct_pb_ptr(ps);
//
//	printf("ps->name = %s - ps->id = %d\n", ps->name, ps->id);
//
//	free(ps);
//}
//
//
//
//
//void struct_pbv(p_struct ps) {
//	/**
//	 * Since this is passed by value, the updated values to not stick
//	 * and when this returns, the values go back to the original before
//	 * calling this function.
//	 *
//	 * IMPORTANT: The passed in ps, the whole struct is made of copy of
//	 * 		so even the address is different.
//	 */
//	printf("** struct_pbv **\n");
//	printf("ps = %p\n", &ps);
//
//	ps.name = "Two";
//	ps.id = 90;
//}
//
//void struct_pb_ptr(p_struct *ps) {
//	printf("** struct_pb_ptr **\n");
//
//	// When this returns, it does not change the original
//	// pointer so 56 and Zero are not assigned.
////	p_struct p;
////	p.id = 56;
////	p.name = "Zero";
////	ps = &p;
//
//	// Since the contents of the struct can be modified, this
//	// will stick after the function returns.
//	ps->name = "Two";
//	ps->id = 80;
//}
//
///***********************************************************************
// * NAME:		traverse_name()
// *
// * DESCRIPTION:	Does pointer arithmetic on the name.
// *
// *
// */
//void traverse_name(p_struct *ps) {
//
//	printf("\n***** traverse_name() *****\n");
//
//	printf("ps = %p\n", ps);
//	printf("ps->name = %p\n", ps->name);
//
//	char *c = ps->name;
//
//	printf("c = %p\n", c);
//
//	while (*c) {
//		printf("(*ps).name = %s\n", c++);
//	}
//
////	while (*(ps->name)) {
////		printf("(*ps).name = %s\n", ps->name++);
////	}
//}
