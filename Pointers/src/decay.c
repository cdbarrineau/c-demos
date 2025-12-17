/*
 * decay.c
 *
 *  Created on: Dec 1, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change_int_arr(int *arr);
void do_int_decay(int *arr);
void do_str_decay(char *arr);

/***********************************************************************
 * NAME:		test_no_decay()
 *
 * DESCRIPTION:	Tests when no pointer decay happens.
 *
 *
 */
void test_no_decay() {

	printf("\n***** test_no_decay() *****\n");

	int arr[] = { 10, 20, 30 };

	printf("arr: %p\n", arr);

	// Decay does not happen on sizeof.
	// This yields 12 bytes, 3 items * 4 bytes for an int.
	printf("sizeof(arr) = %zu\n", sizeof(arr));

	// This is the address of arr[0] which prints 8 bytes.
//	printf("sizeof(&arr) = %zu\n", sizeof(&arr));

	// This decays.
//	int *pa = &arr[0];

	// This is not valid.
//	int (*pa)[] = &arr;

	// Here we go, this does NOT decay.
	// This is a pointer to an array of 3 elements.

	// Parens are IMPORTIANT because it ensures that the pointer
	// points to the entire array, not just a single element.
	int (*pa)[3] = &arr;
//	int *pa = &arr[0];

	size_t len = sizeof(*pa) / sizeof(int);
	printf("len = %zu\n", len);
	printf("sizeof(*pa) = %zu\n", sizeof(*pa));

	// Same address as arr.
	printf("*pa = %p\n", *pa);

	// Same as above.
	printf("pa = %p\n", pa);


	printf("\n");
	// Contents of pa[0].
	size_t len2 = sizeof(arr) / sizeof(int);
	for (int i = 0; i < len2; i++) {
		printf("*arr[i] = %d : %p\n", arr[i], &arr[i]);
//		printf("*pa[i] = %d : %p\n", *pa[i], pa[i]);

		// This is how to index into an pointer to an array of N elements.
		// This first line will get the next pointer address after...
		int *p3 = *pa + i;
		printf("*pa + %d = %d : %p\n", i, *p3, p3);
	}


	// This prints the size of the decayed pointer.
//	printf("sizeof(&pa) = %zu", sizeof(&pa));


}

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
void test_char_arr_no_decay() {

	printf("\n***** test_char_arr_no_decay() *****\n");

	// This rule simply means that the following does not decay:
	// char str[] = "foo":

	char str[] = "foo";
	printf("str: %p\n", str);
	printf("sizeof(str) = %zu\n", sizeof(str));

	// This does not work, decays.
//	char *ps = str;

	// This works but it's the same as any other array like in above,
	char (*ps)[4] = &str;

	printf("*ps: %s\n", *ps);

	printf("ps: %p\n", ps);
	printf("sizeof(ps) = %zu\n", sizeof(ps));
	printf("sizeof(*ps) = %zu\n", sizeof(*ps));
	printf("sizeof(&ps) = %zu\n", sizeof(&ps));
}

void iterate_char(char *pa) {

	// Since we iterate over the pointer pa, the
	// first loop iterates pa.  In order to iterate
	// it again, we can assign a new pointer:
	// NOTE: There is no directly way to just reset it
	// to the beginning, have to store the beginning address
	// or do this.
	char* pa2 = pa;

	for (int i = 0; (*pa); i++, pa++) {
		printf("(*pa)++ (%d) (%p) = %c\n", i, pa, *pa);
	}

	printf("\nWhile Loop:\n");

	int j = 0;
	while (*pa2) {
		printf("sizeof(pa2) %zu : sizeof(*pa) %zu\n", sizeof(pa2), sizeof(*pa));
		printf("(*pa2)++ (%d) (%p) = %c\n", j, pa2, *pa2);
		pa2++;
		j++;
	}
}

/***********************************************************************
 * NAME:		test_str_function_decay()
 *
 * DESCRIPTION:	Tests pointer decay when calling a function, iterating
 * 				over the array in the function.
 *
 *
 */
void test_str_function_decay() {

	// This gives each *pa size 1 with pa 8 for the pointer to *pa
	char arr[] = "Hello";
	iterate_char(arr);

	printf("\n\n");

	// This gives exact same thing as above.
	char* pa = (char*)malloc(sizeof(char) * (5 + 1));
	strncat(pa, "Hello", 6);
	iterate_char(pa);

	free(pa);
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
	printf("Decayed pa: %p\n", pa);

	// Can't do this as arr has decayed when assining to pa.
	// This gives a warning:
	// 		warning: division ‘sizeof (int *) / sizeof (int)’ does not
	//		compute the number of array elements [-Wsizeof-pointer-div]
//	size_t len2 = sizeof(pa) / sizeof(int);
//
//	printf("\ndo_int_decay_ref len: %zu\n", len2);
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
	// NOTE: This is the same as:
	// pa2 = arr;
	char *pa2 = &arr[0];
	printf("pa2 = %p\n", pa2);
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

	printf("change_arr(int*): arr: %p sizeof(arr) = %zu\n", arr, sizeof(arr));

	*(arr) = 90;

	for (int i = 0; i < 3; i++) {
		printf("arr[%d] = %d : %p\n", i, arr[i], &arr[i]);
	}
}

