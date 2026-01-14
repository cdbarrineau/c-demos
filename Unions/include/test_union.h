/*
 * test_union.h
 *
 *  Created on: Jan 13, 2026
 *  Author: mark2v
 */

#ifndef INCLUDE_TEST_UNION_H_
#define INCLUDE_TEST_UNION_H_

union union_1 {
	int ival;
	char *cval;
};

typedef union {
	int ival;
	char *cval;
} union_2;

// Can also typedef this.
enum u_discriminator {
	INT,
	FLOAT,
	CHAR
};

struct s_type {
	int id;
	char *name;
};


typedef union {
	int ival;
	float fval;
	char *cval;
	long long llval;
	struct s_type s_data;
} u_data;

struct u_type_s {
	enum u_discriminator discriminator;
	u_data data;
};

typedef union {

	int ival;

	struct {
		int ival;
		char *cval;
	} s;

} inner_struct_union;

typedef struct {

	int ival;

} s2_t;

typedef union {
	int ival;
	s2_t s2;
} inner_struct_union_2;

/***********************************************************************
 * NAME:		test_union()
 *
 * DESCRIPTION:	Tests different unions.
 *
 */
void test_union();


#endif /* INCLUDE_TEST_UNION_H_ */
