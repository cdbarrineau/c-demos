/*
 * mod_str_in_function.h
 *
 *  Created on: Jan 2, 2026
 *  Author: mark2v
 */

#ifndef INCLUDE_MOD_STR_IN_FUNCTION_H_
#define INCLUDE_MOD_STR_IN_FUNCTION_H_

/***********************************************************************
 * NAME:		test_mod_str_in_function()
 *
 * DESCRIPTION:	Tests passing a double pointer to a function that will
 * 				modify the string address itself.
 */
void test_mod_str_in_function();

/***********************************************************************
 * NAME:		test_mod_malloc_str_in_function()
 *
 * DESCRIPTION:	Tests passing a double pointer to a function that will
 * 				modify the string address itself using malloc to
 * 				specifically test how to handle the allocated memory.
 */
void test_mod_malloc_str_in_function();

#endif /* INCLUDE_MOD_STR_IN_FUNCTION_H_ */
