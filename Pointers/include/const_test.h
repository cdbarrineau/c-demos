/*
 * const_test.h
 *
 *  Created on: Dec 4, 2025
 *  Author: mark2v
 */

#ifndef INCLUDE_CONST_TEST_H_
#define INCLUDE_CONST_TEST_H_

/***********************************************************************
 * NAME:		quick_const_test()
 *
 * DESCRIPTION:	Tests all three variants or const keyword.
 *
 */
void quick_const_test();

/***********************************************************************
 * NAME:		test_const_arr_itens_and_ptr()
 *
 * DESCRIPTION:	Tests when both the array items and the pointer are
 * 				readonly:
 *
 * 					const int * const ptr;
 *
 */
void test_const_arr_itens_and_ptr();

/***********************************************************************
 * NAME:		test_const_ptr()
 *
 * DESCRIPTION:	Tests when the array items are mutable but the
 * 				pointer is not:
 * 					int * const ptr;
 *
 */
void test_const_ptr();

/***********************************************************************
 * NAME:		test_const_arr_items()
 *
 * DESCRIPTION:	Tests when the pointer is mutable but the items in
 * 				an array, or even a single value, is readonly:
 *
 * 					const int *ptr;
 *
 */
void test_const_arr_items();

#endif /* INCLUDE_CONST_TEST_H_ */
