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
	char *name;
} p_struct;

// Unnamed structure.
struct un_struct {
	int id;
	char *name;
};

/***********************************************************************
 * NAME:		test_pbv()
 *
 * DESCRIPTION:	Tests struct pass by value.  This shows that passing
 * 				a struct by value does not alter the structure however,
 * 				it will alter the contents of the structre.
 *
 */
void test_pbv();

/***********************************************************************
 * NAME:		test_pba()
 *
 * DESCRIPTION:	Tests struct pass by address (reference).  This shows
 * 				that passing a struct by address wull alter the struc
 * 				itself.
 *
 */
void test_pba();

/***********************************************************************
 * NAME:		test_unnamed_struct()
 *
 * DESCRIPTION:	Tests an unnamed struct.
 *
 */
void test_unnamed_struct();

#endif /* INCLUDE_P_STRUCT_H_ */
