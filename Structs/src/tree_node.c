/*
 * struct_defs_use_this.c
 *
 *  Created on: Dec 21, 2025
 *  Author: mark2v
 */
#include <stdio.h>
#include <stdlib.h>

#include "../include/tree_node.h"

// Create three new keywords called:
// 1) tnode2_ptr
// 2) tnode_ptr
// 2) tnode
//typedef struct node2 *tnode2_ptr;
typedef struct node *tnode_ptr;

typedef struct node {
	int field2;
	struct tnode *left;
	struct tnode *right;
} tnode;



/***********************************************************************
 * NAME:		test_tree_node()
 *
 * DESCRIPTION:	Tests a tree node struct and pointer.
 *
 */
void test_tree_node() {

	printf("*****  test_tree_node  *****\n");

	tnode tn;
	tn.field2 = 10;

	printf("tn = %d\n", tn.field2);

	tnode_ptr p = malloc(sizeof(tnode));
	(*p).field2 = 70;

	printf("(*p).field2 = %d\n", (*p).field2);

	free(p);



//	tnode2_ptr p2 = NULL;
			// This does not work as node2 is not a type:
			// 		malloc(sizeof(node2));
//	printf("\ntnode2_ptr = %p\n", p2);
}
