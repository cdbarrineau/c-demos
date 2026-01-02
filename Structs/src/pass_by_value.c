/*
 * pass_by_value.c
 *
 *  Created on: Dec 30, 2025
 *  Author: mark2v
 */
#include <stdio.h>

#include "../include/pass_by_value.h"

void modify_struct_contents(PbvStruct s);
void modify_strct_ref(PbvStruct s);

/***********************************************************************
 * NAME:		pass_by_value()
 *
 * DESCRIPTION:	Tests passing structs by value.  Here whatever mods are
 * 				made to the struct itself are not persisted between calls
 * 				even to the contents in the struct are not persisted.
 */
void pass_by_value() {

	printf("*****  pass_by_value  *****\n");

	PbvStruct pbv_s;
	pbv_s.name = "Hello!";
	pbv_s.id = 1;

	printf("BEFORE mod contents,\tname = %s, id = %d, address = %p\n",
			pbv_s.name,
			pbv_s.id,
			&pbv_s);

	modify_struct_contents(pbv_s);

	printf("AFTER mod contents,\tname = %s, id = %d, address = %p\n",
			pbv_s.name,
			pbv_s.id,
			&pbv_s);

	/*
	 * Doing this will pass a copy of the struct.  The passed in
	 * struct will have a different memory address!!
	 *
	 * char* works the same exact way, see pointer_array::test_pbv.
	 */

	modify_strct_ref(pbv_s);

	printf("AFTER mod struct,\tname = %s, id = %d, address = %p\n",
			pbv_s.name,
			pbv_s.id,
			&pbv_s);
}



/***********************************************************************
 * NAME:		modify_struct_contents(PbvStruct)
 *
 * DESCRIPTION:	Tests passing structs by value.  Here whatever mods are
 * 				made to the struct itself are not persisted between calls
 * 				even to the contents in the struct are not persisted.
 */
void modify_struct_contents(PbvStruct s) {

	s.name = "Goodbye";
	s.id = 2;
}

/***********************************************************************
 * NAME:		modify_strct_ref(PbvStruct)
 *
 * DESCRIPTION:	Tests passing structs by value but inside of this function
 * 				the struct is reassigned a different struct.  Once returned,
 * 				the original struct is present in the calling function.
 */
void modify_strct_ref(PbvStruct s) {

	printf("IN mod struct\t\toriginal address\t\t= %p\n", &s);

	PbvStruct s2;
	s2.name = "Modified";
	s2.id = 3;

	/*
	 * This will NOT change the address of "s".  It will change the
	 * contents of the struct but since he struct is on the stack,
	 * we don't manage the memory, the compiler does that.  In order
	 * to change the address we'd have to malloc it.
	 *
	 * char* works the same exact way, see pointer_array::test_pbv.
	 */
	s = s2;

	printf("IN mod struct,\t\tname = %s, id = %d, address = %p\n",
				s.name,
				s.id,
				&s);

	printf("IN mod struct \t\tnew struct address: \t\t%p\n", &s2);
}




