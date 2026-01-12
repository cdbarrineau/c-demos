/*
 * io.c
 *
 *  Created on: Nov 27, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "../include/io.h"

/*
 * Don't really need this since we are exiting in the sigin
 * but keep it here because volatile is useful knowledge.
 *
 * volatile is used to turn off compiler optimizations when
 * a variable can be updated outside of the main program code
 * such as here, catching a signal.
 *
 */
static volatile BOOL keep_running = TRUE;

/*
 * Handler that gets registered for CTR-C (sigint) signals.
 */
void sigint_hanlder(int sig) {
	printf("\n\tGot sigint 2: %d\n", sig);
	keep_running = FALSE;

	exit(0);
}

void print_chars(int len);


/***********************************************************************
 * NAME:		read_std_in()
 *
 * DESCRIPTION:	Reads from stdin and prints out the numbers from 1-n
 * 				where n is the number entered by the user.
 *
 *
 */
void read_std_in() {
	signal(SIGINT, sigint_hanlder);

	char* line = NULL;
	size_t len = 0;
	size_t line_size = 0;
	int num_items = 0;

	return;

	// Don't really need keep_running here since exiting in sig int handler.
	while(num_items == 0 && keep_running) {
		printf("Enter number of iterations: ");
		line_size = getline(&line, &len, stdin);

		// This will return at a minimum 1 for the newline char if
		// only ENTER is pressed so check for -1 instead:
		// If an error occurs or end of file is reached without any bytes read, getline returns -1.
		if (line_size != -1) {
//			printf("line_size: %zu\n", line_size);

			// atoi converts a string to a number.  If a non-numeric value
			// is encountered that char and everything after it discarded.
			num_items = atoi(line);
			if (num_items > 0) {
				print_chars(num_items);
			}
//			printf("num_items: %d\n", num_items);
		}

//		printf("Line is %s", line);
		if (line) {
			free(line);
			line = NULL;
		}
	}
}


/***********************************************************************
 * NAME:		print_chars()
 *
 * DESCRIPTION:	Prints an array of numbers from 0 to len.
 *
 * INPUT:		len The length of the array to create and print.
 *
 */
void print_chars(int len) {
	printf("Len: %d\n", len);

	char* str = (char*)malloc(sizeof(char) * (len + 1));
	str[0] = '\0';

	for (int i = 0; i < len; i++) {
		str[i] = 48 + i;
		printf("str[%d] = %c\n", i, str[i]);
	}

	// Always append the null.
	// Space was allocated for len + 1 so index into len in the array.
	str[len] = '\0';

	printf("Full str: %s\n", str);

	free(str);
}


