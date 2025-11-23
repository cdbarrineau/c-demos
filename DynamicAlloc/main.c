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

#define MAX_NAME_LEN 50

typedef struct {
	char* name;
	int age;
} person;


void do_person_test() {
	// Create a new string for name on the heap.
	char* name = "Never fear, I, is here";
	int len = strnlen(name, MAX_NAME_LEN);

	person* p = (person*)malloc(sizeof(person));
	(*p).age = 50;	// Or p->age

	printf("CHAR_BIT: %ld bytes\n", sizeof(CHAR_BIT));

	p->name = (char*)malloc(len * CHAR_BIT);
	p->name[0] = '\0';

	// This works fine.
//	strcpy(p->name, name);

	// Need to add 1 for the NULL terminator.
//	strncpy(p->name, name + 1, len);
	strncpy(p->name, name, len + 1);
//	p->name[len + 1] = '\0';
//	p->name = name;

	// Or just assign some string:
//	p->name = "Me!";


	printf("Pointer to p: %p\n", p);
	printf("Person: name=%s age=%d\n", p->name, p->age);

	// Remember to clean up memory!!!
	free(p->name);
	free(p);
}

void to_str_arr_test() {
	int num_items = 10;
	char** arr = (char**)malloc(sizeof(char*) * num_items);

	for (int i = 0; i < num_items; i++) {
		char* list = (char*)malloc(sizeof(int) + 1);

		sprintf(list, "item: %d\n", i);

		arr[i] = list;
	}

	for (int i = 0; i < num_items; i++) {
		printf("inner item: %s\n", arr[i]);

		free(arr[i]);
	}



	free(arr);
}


int main() {
//	do_person_test();

	to_str_arr_test();


	return 0;
}
