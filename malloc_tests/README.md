# malloc notes

## ASCII
char uses the ASCII Table so:

```
ASCII   Decimal     Code
A       65          char c = (char)65;
                    printf("%c\n", c);
```

## General Forms:

For a 1-D int array:

```
int* arr = (int*) malloc (sizeof(slot_size) * num_slots)

(int*)malloc --> I want to create an array of ints

sizeof (int) --> I want to create slots of ints, each one must have the size of an int (4 bytes)

* num_slots  --> I want to create n slots of ints. 

```

## Char arrays

* Always include a byte for the NULL terinator for ALL string arrays so:

```
char* arr = (char*)malloc(sizeof(char) * (num_slots + 1));
arr[0] = '\0';

char** arr_list = (char**)malloc(sizeof(char*) * (num_slots + 1));
arr_list[0] = '\0';

```

### 1-D Array

    /*
     * char*  Each column is char
     *  - Each char* string is terminated by NULL.
     *  - For each of these, need to allocate +1 to the size.
     *  - So for a string array (char*) of "Hello":  "Hello" + \0;
     * -----------------------------------
     *      char[0]  | 'H'
     *      char[1]  | 'e'
     *      char[2]  | 'l'
     *      char[3]  | 'l'
     *      char[4]  | 'o'
     *      char[5]  | '\0'
     */

```
int num_items = 10;

char* arr = (char*)malloc(sizeof(char) * (num_items + 1)); // Make sure to add one for the NULL terminator.
arr[0] = '\0';

```


### 2-D array

    /*
     * char**  Each column is a char* so char** is just a list of char*
     *  - The whole char** is terminated by NULL.
     *  - Each char* string is terminated by NULL.
     *      - For each of these, need to allocate +1 to the size.
     *  - Each char* can be indexed into the main char** array as follows:
     * -----------------------------------
     *      char* [0]  | "Value 1" + \0
     *      char* [1]  | "Value 2" + \0
     *      char* [2]  | "Value 3" + \0
     *      char* [3]  | "Value 4" + \0
     *      char* [4]  | "Value 5" + \0
     *      char* [5]  | "Value 6" + \0
     *      char* [6]  | "Value 7" + \0
     *      \0
     */

```
// Total number of arrays in the char**
int num_items = 10;

// Length of each inner char array in bytes.
int inner_len = 20;

char** arr = (char**)malloc(sizeof(char**) * (num_items + 1));   // Make sure to add one for NULL terminator.
arr[0] = '\0';

char* item = (char*)malloc(sizeof(char*) * (inner_len + 1)); // Make sure to add one for NULL terminator.
item[0] = '\0';

// This only copies "0 - Some Really Long" because that is 20 bytes (inner_len).
snprintf(item, inner_len + 1, "%d - Some Really Long Test String", 0);

arr[0] = item;

printf(arr[0]);

free(arr[0]);
free(arr);

```


## Int arrays

* Do NOT need to include NULL terminator, that is ONLY for string arrays.



