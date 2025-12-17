/*
 * p_struct.h
 *
 *  Created on: Dec 17, 2025
 *  Author: mark2v
 */

#ifndef INCLUDE_P_STRUCT_H_
#define INCLUDE_P_STRUCT_H_

typedef struct p_struct_type {
	int id;
	char* name;
} p_struct;

/***********************************************************************
 * NAME:		test_array_structs()
 *
 * DESCRIPTION:	Tests struct pointer.
 *
 *
 */
void test_p_struct();

/***********************************************************************
 * NAME:		test_pass_by_value()
 *
 * DESCRIPTION:	Tests struct pass by value.  Specifically the char*
 * 				inside the structure.
 *
 *
 */
void test_pass_by_value();


#endif /* INCLUDE_P_STRUCT_H_ */
