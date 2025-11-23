/*
 * main.c
 *
 *  Created on: Nov 6, 2025
 *      Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "include/bit_utils.h"
#include "include/shift_bit_test.h"
#include "include/get_bit_test.h"
#include "include/set_bit_test.h"
#include "include/clear_bit_test.h"
#include "include/print_bits.h"
#include "include/invert_bits_test.h"
#include "include/right_shift_test.h"
#include "include/twos_compliment.h"

int main() {

//	test_get_bit_str();

//	run_shift_bit_test();

//	run_get_bit_test();

//	run_set_bit_test();

//	run_invert_bits_test();
//	run_clear_bit_test();

//	run_right_shift_test();

	run_twos_compliment_test();



//	printf("Num Bits: %d\n", (sizeof(int) * CHAR_BIT));






	// Test code from Shlemiel The Painter
	// https://wiki.c2.com/?ShlemielThePainter

	//	char str[] = "*Hello!";
	//	str[0] = sizeof(str)/sizeof(*str) - 2;
	////	str[0] = strlen(str) - 1;
	//
	//	int len1 = strlen(str) - 1;
	//
	//	printf("str: %s\n", str);
	//	printf("strlen(str) - 1 = %d", len1);
	//	printf("sizeof(str)/sizeof(*str) - 2 = %s\n", (sizeof(str)/sizeof(*str) - 2));

	//	str[0] = strlen(str) - 1;
	//	printf("First: %s\n", str);

	return 0;
}

