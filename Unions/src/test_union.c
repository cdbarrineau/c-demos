/*
 * test_union.c
 *
 *  Created on: Jan 13, 2026
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/test_union.h"

void print_u(u_data *u, enum u_discriminator disc);


/***********************************************************************
 * NAME:		test_union()
 *
 * DESCRIPTION:	Tests different unions.
 *
 */
void test_union() {

	inner_struct_union isu;
	isu.s.cval = "Hello";
	isu.s.ival = 10;

	inner_struct_union isu2;
	isu2.s.cval = "Goodbye";
	isu2.s.ival = 20;

	printf("isu.s.cal   = %s\n", isu.s.cval);
	printf("isu.s.ival  = %d\n", isu.s.ival);
	printf("isu2.s.cal  = %s\n", isu2.s.cval);
	printf("isu2.s.ival = %d\n", isu2.s.ival);

	inner_struct_union_2 isu22;
	isu22.s2.ival = 30;
	printf("isu22.s2.ival = %d\n", isu22.s2.ival);


	union union_1 u1;
	u1.ival = 1;

	printf("u1.ival = %d\n", u1.ival);

	union_2 u2;
	u2.ival = 2;

	printf("u2.ival = %d\n\n", u2.ival);

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

