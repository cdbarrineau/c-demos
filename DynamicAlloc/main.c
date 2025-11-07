/*
 * main.c
 *
 *  Created on: Nov 6, 2025
 *      Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
	char* name;
	int age;
} person;


int main() {

	// Create a new string for name on the heap.
	char* name = "Never fear, I, is here";
	int len = strnlen(name, MAX_NAME_LEN);

	person* p = (person*)malloc(sizeof(person));
	(*p).age = 50;	// Or p->age

	p->name = (char*)malloc(50);
	strncpy(p->name, name, len);

	// Or just assign some string:
//	p->name = "Me!";


	printf("Pointer to p: %p\n", p);
	printf("Person: name=%s age=%d\n", p->name, p->age);

	// Remember to clean up memory!!!
	free(p->name);
	free(p);

	return 0;
}
