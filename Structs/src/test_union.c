/*
 * test_union.c
 *
 *  Created on: Dec 19, 2025
 *  Author: mark2v
 */

#include <stdio.h>
#include <stdlib.h>

#include "../include/test_union.h"

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


typedef union u_type {
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


void print_u(u_data *u, enum u_discriminator disc);

/***********************************************************************
 * NAME:		test_union()
 *
 * DESCRIPTION:	Tests the union data type.
 *
 */
void test_union() {

	struct u_type_s u_type;
	u_type.discriminator = CHAR;
	u_type.data.cval = "Hello, World!";

	printf("sizeof(u_type) = %zu\n", sizeof(u_type));

	switch (u_type.discriminator) {
		case INT:
			break;
		case FLOAT:
			break;
		case CHAR:
			break;
		default:
			printf("\nUnknown discriminator: %d\n", u_type.discriminator);
	}


	u_data u;
	u.ival = 1;
	u.fval = 2.0;
	u.cval = "Three";

	printf("* u *\n");
	print_u(&u, CHAR);

	u_data *pu = malloc(sizeof(u_data));
	if (pu == NULL) {
		fprintf(stderr, "Unable to allocate memory for u_data!");
		return;
	}

	// Since a union has the last assigned member value only, can't
	// null this out after the fact.
	// ALSO IMPORTANT: When ival is assigned, cval goes to invalid
	// memory so NULL value goes away.
	pu->cval = NULL;
	pu->ival = 2;
	pu->s_data.id = 2;
	pu->s_data.name = "Two";

	printf("\n* pu *\n");
	print_u(pu, INT);

	free(pu);
}

void print_u(u_data *u, enum u_discriminator disc) {
	printf("sizeof(u.s_data) = %zu\n", sizeof(u->s_data));
	printf("sizeof(u) = %zu\n", sizeof(u));
	printf("u.ival = %d\n", (*u).ival);
	printf("u.fval = %f\n", (*u).fval);

	if (disc == CHAR) {
		printf("u.cval = %s\n", (*u).cval);
	}
	else {
		printf("u.cval -> discriminator is not CHAR\n");
	}
}
