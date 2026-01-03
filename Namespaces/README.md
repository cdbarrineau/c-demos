# C Namespaces
Demos the different kinds of namespcaes in C along with different variable and function scopes.

## Extern

"extern" keyword allows a file to declare a variable HOWEVER, it must be defined elsewhere.

 * <b>Only use this if refering to a global variable before it is actually defined!</b>
 * <b>ALSO, if declaring in a separate source file than the definition, need extern as well!</b>
 * extern does NOT create the variable(s) or set aside storage.  That in ONLY done when they are defined elsewhere.



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

```
    void do_stuff(int i) {
        static int j = 0;
        
        // The current value is retained across multiple invocations.
        int k = i + j++;
    }

```