# C Namespaces
Demos the different kinds of namespcaes in C along with different variable and function scopes.

## Extern

"extern" keyword allows a file to declare a variable HOWEVER, it must be defined elsewhere.

 * <b>Only use this if refering to a global variable before it is actually defined!</b>
 * <b>ALSO, if declaring in a separate source file than the definition, need extern as well!</b>
 * extern does NOT create the variable(s) or set aside storage.  That in ONLY done when they are defined elsewhere.
 * extern variables are guaranteed to be initialized to zero.
    * NOTE: Still initialized even if a function is called before the formal definition!



```
    externs.h
    
    extern int sp;
    extern char arr[];
```

```
    externs.c
    
    #define MAX 10
    int sp = ;
    arr[MAX];
```


## Statics

"static" keyword can be applied to both functions and variables.

 * For a static function and variables, they can only be used in the source file it is declared.
 * Static variable can be used inside of a function and the current value will be retained across multiple invocations of the function.
 * static variables are guaranteed to be initialized to zero.

```
    void do_stuff(int i) {
    
        // Don't need to init to 0 as it's guaranteed to be done that for you.
        // static int j = 0;
        static int j;
        
        // The current value is retained across multiple invocations.
        int k = i + j++;
    }

```

## Macros
 * Makes code inline to reduce the function call overhead to improve performance.
 * Biggest thing to worry about is doing any kind of logic in a substitution.  For example:

```
    // Line-continuation is "\"
    #define MAX(A, B) \ 
        ((A) > (B) ? (A) : (B))

    int i = 2
    int j = 4;
    
    MAX(i++, j++)
    
    // After the call, the returned value is 5 but j has been incremented twice so
    // j == 6 now since the test increments it THEN the return increments it again!

```

### Macro Stringification
Use the # in a macro to stringify the input:
 
```
    #define STRINGIFY(A) #A
    
    char* str = STRINGIFY(123)
    
    // Returns a char* that is = "123"
    
    char *s2 = STRINGIFY(void*);
    
    // Returns a char* that is = "void*"
```

### Macro printing
In order to print a macro, seems like you should use a macro to print it.
 
```
    #define PRINTF(X) printf("%s = %s\n", #X, STRINGIFY(X))
    
    #define TEST_FILE "test.h"
    
    // Prints "TEST_FILE = test.h"
    PRINTF(TEST_FILE);

```





