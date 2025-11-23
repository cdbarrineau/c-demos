# malloc notes

## General Forms:

For a 1-D int array:

```
int* arr = (int*) malloc (sizeof(slot_size) * num_slots)

(int*)malloc --> I want to create an array of ints

sizeof (int) --> I want to create slots of ints, each one must have the size of an int (4 bytes)

* num_slots  --> I want to create n slots of ints. 

```

## Char arrays

### 1-D Array

```
int num_items = 10;

char* arr = (char*)malloc(sizeof(char) * (num_items + 1)); // Make sure to add one for the NULL terminator.

```


### 2-D array

```
// Total number of arrays in the char**
int num_items = 10;

// Length of each inner char array in bytes.
int inner_len = 20;

char** arr = (char**)malloc(sizeof(char**) * (num_items + 1));   // Make sure to add one for NULL terminator.

char* item = (char*)malloc(sizeof(char*) * (inner_len + 1)); // Make sure to add one for NULL terminator.

// This only copies "0 - Some Really Long" because that is 20 bytes (inner_len).
snprintf(item, inner_len + 1, "%d - Some Really Long Test String", 0);

arr[0] = item;

printf(arr[0]);

free(arr[0]);
free(arr);

```


## Int arrays
