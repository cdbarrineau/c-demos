/*
 * decay.c
 *
 *  Created on: Dec 1, 2025
 *  Author: mark2v
 */
#include <stdio.h>

void change_int_arr(int *arr);
void do_int_decay(int *arr);
void do_str_decay(char *arr);



/***********************************************************************
 * NAME:		test_str_ptr_decay()
 *
 * DESCRIPTION:	Tests pointer decay with an char* array.
 *
 *
 */
void test_str_ptr_decay() {

	printf("\n**** test_str_ptr_decay ****\n");
	char arr[] = "Hello";

	// This is 6, 5 items plus the newline.
	//
	// sizeof(char) == 1 so no need for it.
	size_t len = sizeof(arr) / sizeof(char);

	printf("arr = %s\n", arr);
	printf("len = %zu\n", len);

	/*
	 * REMEMBER:
	 *
	 * 		char *pa = arr;
	 * 			and
	 * 		char *pa = &arr[0]
	 *
	 * are EXACTLY the same thing!!
	 * Both addresses are the same!
	 *
	 */

	// array has decayed here.
	char *pa = arr;
	printf("pa = %s\n", pa);

	printf("Address of arr[0] = %p\n", &arr[0]);
	printf("Address of *pa    = %p\n", pa);


//	size_t l2 = sizeof(pa) / sizeof(char);
//	printf("l2 = %zu\n", l2);

	// Array has decayed here too.
	char *pa2 = &arr[0];
	printf("pa2 = %s\n", pa2);
//
//	size_t l2 = sizeof(pa2) / sizeof(char);
//	printf("l2 = %zu\n", l2);

	// Can not pass in &arr because arr is already a
	// named array pointing to the first element in the array.
//	do_str_decay(arr);
}

void do_str_decay(char *arr) {

	// Still prints "Hello"
	printf("*arr = %s\n", arr);

	// Here, array has decayed.  Prints 8 for the width of the address.
//	size_t len = sizeof(arr) / sizeof(char);
//	printf("len = %zu\n", len);
}


/***********************************************************************
 * NAME:		test_int_ptr_decay()
 *
 * DESCRIPTION:	Tests pointer decay with an int* array.
 *
 *
 */
void test_int_ptr_decay() {

	printf("\n**** test_int_ptr_decay ****\n");

	int arr[] = { 11, 13, 15 };

	// Get the length of arr.
	size_t len = sizeof(arr) / sizeof(int);
	printf("arr[] size: %zu\n", len);

	// This is not valid to do as it gives the following warning:
	// 		warning: initialization of ‘int *’ from incompatible
	//		pointer type ‘int (*)[3]’ [-Wincompatible-pointer-types]
	//  int *pa = &arr;
	//
	//
	// This is the way to do it.  Returns a pointer to the first item
	// in the array.
	// int *pa = &arr[0];
	//
	// Or the best way way:
	int *pa = arr;

	printf("arr: %p\n", arr);
	printf("pa:  %p\n", pa);

	// Print out all items in the array.
	for (int i = 0; i < len; i++) {
		int val = *(pa + i);

		// Each address is 4 bytes from the last where
		// i = 0, is the same address as the ptr to a[0].
		printf("arr[%d] = %d : %p  &arr[%d] = %p\n", i, val, (pa + i), i, &arr[i]);
	}

	do_int_decay(arr);

	// See what happens when we try it with the pointer.
	// This gives a warning:
	// 		warning: division ‘sizeof (int *) / sizeof (int)’ does not
	//		compute the number of array elements [-Wsizeof-pointer-div]
//	size_t p_len = sizeof(ap) / sizeof(int);
//	printf("p_len size: %zu\n", p_len);

}

/***********************************************************************
 * NAME:		test_int_decay()
 *
 * DESCRIPTION:	Tests pointer decay with an int array.
 *
 *
 */
void test_int_decay() {

	printf("\n**** test_int_decay ****\n");

	int arr[] = { 11, 13, 15 };

	size_t len = sizeof(arr) / sizeof(int);

	printf("arr: %p  sizeof(arr) = %zu\n", arr, len);

	// Print out the values and addresses.
	for (int i = 0; i < 3; i++) {
		printf("arr[%d] = %d : %p \n", i, *(arr + i), &(*(arr + i)));
	}

	printf("\n");

	// Change index 0 to something different.  Note how this
	// function prints out the same addresses and values, including
	// the changed arr[0].
	// NOTE: That the address of arr[0] did NOT change, only the value.
	change_int_arr(arr);

	printf("\nReturned array pass by ref (ptr)\n");

	// Since arr was passed by reference above (int *), the updated
	// value in arr[0] remains and add addresses remain as well.
	for (int i = 0; i < 3; i++) {
		printf("arr[%d] = %d : %p\n", i, *(arr + i), &(*(arr + i)));
	}

	do_int_decay(arr);

	int *pa = &arr[0];
	printf("pa: %p\n", pa);
//
//	size_t len2 = sizeof(pa) / sizeof(int);
//
//	printf("\ndo_int_decay_ref len: %zu\n", len2);
}


// NOTE: Because of decay, arr no longer contains information about
// it's size.
//
// sizeof(arr) returns 8 because it not longer refers to an array
// but refers to a pointer which is 8 bytes on this system.
//
// Therefore computing len below will not work and returns 2 (8 / 4).
//
// Compiler gives this warning:
// 		warning: division ‘sizeof (int *) / sizeof (int)’ does not compute
// 		the number of array elements [-Wsizeof-pointer-div]
void do_int_decay(int *arr) {

	size_t len = sizeof(arr);

	printf("\ndo_decay sizeof(arr) = %zu\n", len);

	// This will not work due to decay as the array losses it's size.
	// This will calculate to be 2 since sizeof(arr) is 8.
//	size_t len2 = sizeof(arr) / sizeof(int);
//
//	printf("change_arr len: %zu\n", len2);
}

// This does change the array [0] and it retains the changed value
// after return.
void change_int_arr(int *arr) {

	printf("change_arr(int*): arr: %p\n", arr);

	*(arr) = 90;

	for (int i = 0; i < 3; i++) {
		printf("arr[%d] = %d : %p\n", i, arr[i], &arr[i]);
	}
}

