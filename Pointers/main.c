/*
 * main.c
 *
 *  Created on: Oct 18, 2025
 *      Author: mark2v
 */

#include <stdio.h>

#include "include/deref.h"
#include "include/int_pointer_arithmetic.h"
#include "include/str_pointer_arithmetic.h"
#include "include/decay.h"
#include "include/const_test.h"
#include "include/pointer_array.h"
#include "include/function_pointers.h"
#include "include/mod_str_in_function.h"

static void print_chars(char *name) {
	for (; *name; name++) {

		printf("%c\n", *name);
	}
}

static void print_chars_again(char *name) {
	while (*name) {
		printf("%c\n", (*name));

		name++;
	}
}

int main() {

	char *name = "Hello";

	// Since this is incrementing the pointer, need
	// it in a separate function so that that function
	// gets a copy of the pointer.
	//
	// Putting it right here, the next printf will only
	// print the \0.
	print_chars(name);
	print_chars_again(name);

	printf("name: %s\n", name);

//	test_fcn_ptr(0);
//	test_fcn_ptr(1);


//	test_pbv();
//	test_int_ptr_array();
//	test_char_ptr_array();
//	test_char_ptr_to_ptrs();



//	doStr();

//	derefInt();

//	pointerStuff();

//	print_int_arr_deref();
//	pointers_and_addresses();
//	test_int_array();
//	test_int_array_and_pointers();
//	test_arr_like_char();

//	test_char_array();

//	test_arr_ptr();

//	test_str_ptr_addresses();




//	test_int_decay();
//	test_int_ptr_decay();
//	test_str_ptr_decay();

//	test_no_decay();
//	test_char_arr_no_decay();
//	test_str_function_decay();

//	quick_const_test();
//	test_const_arr_items();
//	test_const_ptr();
//	test_const_arr_itens_and_ptr();

//	test_mod_str_in_function();
//	test_mod_malloc_str_in_function();

	return 0;
}

