/*
 * struct_definitions.c
 *
 *  Created on: Dec 20, 2025
 *  Author: mark2v
 */
#include <stdio.h>

#include "../include/struct_definitions.h"

/*
 * Most basic form.  Defines a new **type** and gives it the name "str_1"
 * in the "tag" namespace.
 *
 * Can later define variables of type str_1:
 * 			struct str_1 s1 = { 1, 2 };
 *
 * 					or for out or oder:
 * 			struct str1_ s2 = { .field2 = 20, .field = 30 };
 */
struct str_1 {
	int field;
	int field2;
};

/**
 * Like above, also defines a type.  Pretty much the same as:
 * 			int str_4, str_5;
 *
 * Refer to these as:
 * 			str_4.field = 10;
 */
struct {
	int field;
} str_4, str_5;


/*
 * typedef creates new data type names, NOT a new type and adds it to the
 * "global" namespace.
*/
typedef struct str_3_type {
	int field;
} str_3;

/*
 * Generates compiler warning:
 * 	useless storage class specifier in empty declaration
 *
 * 		struct td_struct s;
 * 		s.field = 100;
 * 		printf("%d\n", s.field);
 */
//typedef struct td_struct {
//	int field;
//};


/*
 * Not sure when you'd want to do this.  This can be used as either
 * 			str_2.field = 10
 *
 * 				or
 * 			struct st2_type s2;
 * 			s2.field = 60;
 */
//struct str_2_type {
//	int field;
//} str_2;


/**
 * Structure containing a pointer to another structure.  Used for binary trees,
 * linked lists, etc.
 *
 * Can only accomplish this with a pointer to the next node.
 */

typedef struct tnode *Treeptr;

typedef struct tnode {

	struct tnode *left;
	struct tnode *right;
} Treenode;


// This is for a bit field.  The "1" is the width so here
// since it's an int, it used 4 bytes.  However, only 2 bits
// will be used to store the value.

// See bit_field.c
struct {
	unsigned int one : 1;
} bit_field;

void test_str_1();
//void test_str_2();
void test_str_3();
void test_str_4();


/***********************************************************************
 * NAME:		test_struct_definitions()
 *
 * DESCRIPTION:	Tests the different ways a struct can be defined.
 *
 */
void test_struct_definitions() {

	printf("*****  test_struct_definitions  *****\n");

	test_str_1();

	// This looks like there is only one variable and
	// setting this sets it for the whole application.
//	str_2.field = 2;
//	test_str_2();

	test_str_3();

	// This does the same thing as str_2.
	str_4.field = 4;

	test_str_4();
}

void test_str_1() {

	printf("\n** test_str_1() **\n");

	// Declares a struct variable s2 of type str_1.
	// Declared in the "tag" namespace.
	// str_1 definition can later declare variable like s1.
	struct str_1 s1 = { 1 };
	//	s1.field = 1;


	// For non-contingous or out of order initialization:
	struct str_1 s2 = { .field2 = 2, .field = 1 };

	printf("str_1.field = %d .field2 = %d\n", s1.field, s2.field2);
}

//void test_str_2() {
//
//	printf("\n** test_str_2() **\n");
//
////	str_2.field = 2;
//
//	struct str_2_type s2;
//	s2.field = 60;
//
//	printf("str_2.field = %d\n", str_2.field);
//
//	printf("s2.field = %d\n", s2.field);
//
//}

void test_str_3() {

	/*
	 * typedef struct str_3_type {
	 * 		int field;
	 * 	} str_3;
	 */

	printf("\n** test_str_3() **\n");

	str_3 s3 = { .field = 3 };
	//	s3.field = 1;

	printf("s3.field = %d\n", s3.field);

}

void test_str_4() {

	printf("\n** test_str_4() **\n");

	str_5.field = 50;

	printf("str_4.field = %d\n", str_4.field);
}




