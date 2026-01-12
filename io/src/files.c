/*
 * files.c
 *
 *  Created on: Jan 11, 2026
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/files.h"


/***********************************************************************
 * NAME:		test_puts_gets()
 *
 * DESCRIPTION:	Tests puts and gets using a file.
 *
 */
void test_puts_gets() {
	printf("***  test_puts_gets  ***\n");

	char *fname = "marks.txt";

	FILE *fp = fopen(fname, "r");
	if (fp == NULL) {
		fprintf(stderr, "Unable to open file %s\n", fname);

		return;
	}

	char *line = NULL;
	size_t buf_size = 0;

	// getline() also returns the \n char.
	while(getline(&line, &buf_size, fp) != EOF) {
		printf("%s", line);
	}

	free(line);

	// Resets the file pointer to the beginning of the file.
	rewind(fp);

	printf("\n*********************\n");

	// fgets reads characters, not the line.
	// reads n chars but this n value must also
	// account for the \0.
	// So gets with n = 2 will read one character.
	char buf[10];
	fgets(buf, 2, fp);
	printf("%s\n\n", buf);

	rewind(fp);

	while (fgets(buf, 10, fp) != NULL) {
		printf("Read from fgets: %s\n", buf);
	}

	fclose(fp);

	// Print the date from the date command.
	system("date");
}
