/*
 * pass_by_ref.h
 *
 *  Created on: Dec 30, 2025
 *  Author: mark2v
 */

#ifndef INCLUDE_PASS_BY_REF_H_
#define INCLUDE_PASS_BY_REF_H_

typedef struct {
	char *name;
	int id;
} PbrStruct;

/***********************************************************************
 * NAME:		pass_by_ref()
 *
 * DESCRIPTION:	Tests passing structs by value.  Here whatever mods are
 * 				made to the struct itself are not persisted between calls
 * 				even to the contents in the struct are not persisted.
 */
void pass_by_ref();

#endif /* INCLUDE_PASS_BY_REF_H_ */
