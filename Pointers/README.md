# Pointers

Collection ot tests that demonstrate pointers.

## const keyword variants

 * char array[] = "hello"
    * Creates the string "hello" in writable memory so can modify contents.
    * Can NOT just assign a different char[] to another array because arr[0]
            decays to it's first index as a pointer and that pointer is not
            modifyable.
            Have to use strncpy or memcpy.
 * char *
    * If define with constant string, that string is stored in read-only memory, can't modify string.
    * Normal, can assign chars (if not read-only) or reassign pointer to char*
        * Init with malloc, can assign char to any location in array.
 * const char *
    * Constant array contents, can't assign chars but can reassign pointer.
    * Can create another const char* and assign it to first.
    * Can't do things like strcpy, snprintf, etc. causes core dump and get compiler warning.
    *
    
 * char * const
    * Constant array pointer.  Can assign chars but not the pointer to the char *array.
 * const char * const
    * Constant array contents and constant pointer, can't assign either.

## Decay
When an array is assigned to a pointer and the array looses information such as its size.

### No Decay
An array does not decay when:
* Using the sizeof() macro
* When assigning to a pointer of type:
    * Must use 'T (*)[N]' like below:

```
    int arr[] = { 1, 2, 3 };
    
    // This is a pointer to an array of 3 elements.
    int (*pa)[3] = &arr;
    
    // Must use deference to get array info:
    size_t len = sizeof(*pa) / sizeof(int);
    printf("len = %zu\n", len);
    printf("sizeof(pa) = %zu\n", sizeof(*pa));
```

## Pointers vs. Multi-dimentional Arrays
* Page 100 from C book.

```
  * In this case there are 30 + 1 blocks set asside for each char* array
  * totaling 31 * 5.  The for the outer array, there are 5 more pointers
  * to each inner array.
  *
  *
  * arr + i -> This is the pointer address in the outer array that
  *            points to the first location of each char* pointer.
  *
  * *(arr + i) -> This is the pointer to the fist location of the actual
  *               char* pointer in memory.
                 *** Deref this to get the string. ***
  *
  * IMPORTANT: Note how the pointer address is consecutive 8 bytes
  *            from the last. in arr + 1
  *
  * ALSO:      Note how each *(arr + i) ptr is 30 bytes to the next char*
  *            note sure if this is always the case since using malloc.
  
  int num_items = 5;
  int len_char_arr = 30;
  
  char **arr = (char**)malloc(sizeof(char*) * (num_items + 1));
  
  for (int i = 0; i < num_items; i++) {
    *(arr + i) = (char*)malloc(sizeof(char) * (len_char_arr + 1));
    
    snprintf(*(arr + i), len_char_arr, "Some long string: %d other stuff", i);
    
    // OR:
    // arr[i]  but in C the deref operator is more widly used.
  }
  
  Output:
  
    Allocated memory arr address: 0x562d259f96b0
    Pointer address in the outer array that points to first location of each char*
    arr + i = 0x562d259f96b0 where i = 0
    arr + i = 0x562d259f96b8 where i = 1
    arr + i = 0x562d259f96c0 where i = 2
    arr + i = 0x562d259f96c8 where i = 3
    arr + i = 0x562d259f96d0 where i = 4
    Deref value and pointer to the inner array.
    *(arr + i) = Some long string: 0 other stu : 0x562d259f96f0 where i = 0
    *(arr + i) = Some long string: 1 other stu : 0x562d259f9720 where i = 1
    *(arr + i) = Some long string: 2 other stu : 0x562d259f9750 where i = 2
    *(arr + i) = Some long string: 3 other stu : 0x562d259f9780 where i = 3
    *(arr + i) = Some long string: 4 other stu : 0x562d259f97b0 where i = 4
```
  
## Modify the pointer itself

 * In order to modify the pointer itself, must pass a pointer to a pointer (char **).
 
```
char *s = "Hello";

mod_str(&s);

// s is now "Goodbye" with a different address.

void mod_str(char **s) {

    (*s) = "Goodbye";
}

```
