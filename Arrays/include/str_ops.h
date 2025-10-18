/*
 * str_ops.h
 *
 *  Created on: Oct 12, 2025
 *      Author: mark2v
 */

#ifndef STR_OPS_H_
#define STR_OPS_H_

/***********************************************************************
 * NAME:		compare(char*, char*)
 *
 * DESCRIPTION:	Compares the specified str against the string to compare.
 *
 * INPUTS:		char* str The string to compare against.
 * 				char* to_compare The string to compare against.
 *
 * OUTPUTS:		int Returns -1 if str is "before" to_compare,
 * 					0 if the two strings are equal, and 1 if str
 * 					is "after" to_compare.
 *
 */
int compare(char* str, char* to_compare);

/***********************************************************************
 * NAME:		length(char*)
 *
 * DESCRIPTION:	Gets the length of a string.
 *
 * INPUTS:		char* str The string to get the length of
 *
 * OUTPUTS:		int Returns the length of the string.
 *
 */
int length(char* str);

/***********************************************************************
 * NAME:		concat(char*, char*)
 *
 * DESCRIPTION:	Concat two strings.
 *
 * INPUTS:      char* dest The destination to append onto.
 *              const char* src The source to append from.
 *
 * OUTPUTS:		char* Returns the combined dest value.
 */
char* concat(char* dest, const char* src);

#endif /* INCLUDE_STR_OPS_H_ */
