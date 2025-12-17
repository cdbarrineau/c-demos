/*
 * decay.h
 *
 *  Created on: Dec 1, 2025
 *  Author: mark2v
 */

#ifndef INCLUDE_DECAY_H_
#define INCLUDE_DECAY_H_

/***********************************************************************
 * NAME:		test_no_decay()
 *
 * DESCRIPTION:	Tests when no pointer decay happens.
 *
 *
 */
void test_no_decay();

/***********************************************************************
 * NAME:		test_char_arr_no_decay()
 *
 * DESCRIPTION:	Tests the third case of when no decay happens:
 *
 * 		When it's a string literal of type char [N + 1] or a wide
 * 		string literal of type wchar_t [N + 1] (N is the length of
 * 		the string) which is used to initialize an array, as in
 *
 * 		char str[] = "foo"; or wchar_t wstr[] = L"foo";.
 *
 *
 */
void test_char_arr_no_decay();

/***********************************************************************
 * NAME:		test_str_function_decay()
 *
 * DESCRIPTION:	Tests pointer decay when calling a function, iterating
 * 				over the array in the function.
 *
 *
 */
void test_str_function_decay();

/***********************************************************************
 * NAME:		test_str_ptr_decay()
 *
 * DESCRIPTION:	Tests pointer decay with an char* array.
 *
 *
 */
void test_str_ptr_decay();

/***********************************************************************
 * NAME:		test_int_ptr_decay()
 *
 * DESCRIPTION:	Tests pointer decay with an int* array.
 *
 *
 */
void test_int_ptr_decay();

/***********************************************************************
 * NAME:		test_int_decay()
 *
 * DESCRIPTION:	Tests pointer decay with a named int array.
 *
 *
 */
void test_int_decay();

#endif /* INCLUDE_DECAY_H_ */
