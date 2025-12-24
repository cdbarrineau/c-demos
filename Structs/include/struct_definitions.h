/*
 * struct_definitions.h
 *
 *  Created on: Dec 20, 2025
 *  Author: mark2v
 */

#ifndef INCLUDE_STRUCT_DEFINITIONS_H_
#define INCLUDE_STRUCT_DEFINITIONS_H_

/**
 * Can define basic struct because it's just a declaration.  This creates
 * a new **data type** and giving it the name "test1".
 *
 * Adds it to the "tag" namespace
 *
 * Trying to define a variable after it like:
 * 		} t1;
 *
 * Results in the multiple definitions of t1 if included in multiple files.
 */
struct test1 {
	int field;
} /* t1 Can't do this as this declares a variable, "t1" */;

/**
 * Can do this though.  This creates a new **name** NOT another data type,
 * only adds a new "name" for some existing type.
 *
 * Adds it to the "global" namespace.
 *
 */
typedef struct test2 {
	int field;
} t1;


/***********************************************************************
 * NAME:		test_struct_definitions()
 *
 * DESCRIPTION:	Tests the different ways a struct can be defined.
 *
 */
void test_struct_definitions();

#endif /* INCLUDE_STRUCT_DEFINITIONS_H_ */
