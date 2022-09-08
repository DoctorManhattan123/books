# C

C is a general-purpose, imperative procedural, weak statically typed, low-level, hardware-near, compiled programming language. It is probably the widest used language and is mostly used to build low-level performance intensive programs like operating systems, device drivers. If you read this on some machine, it is almost certain that the underlying OS was written in C.

# C Standards

The most known C standards are:

* K&R C
* C89 (ANSI C, C90)
* C99
* C11
* C17 (C18)

Nowadays `C99` is probably the most common used one although some things like the Linux Kernel are still compiled with `-std=gnu89` (because it's a super big project which was started in 1991, where this was the newest standard). If you start a new project you should be using the new standards (e.g. C17). GCC for example compiles with the C11 standard if nothing is specified.  

# Major C Compilers

* GCC
* Clang

These compilers support most platforms that exist.

# Why C?

You will have to use C (or similar languages) to produce performance critical and/or hardware-near application. You manage everything yourself. Most importantly, the memory. In most other modern languages there is a garbage collector which from time to time looks at your heap and clears it with specific techniques. In C there is no such thing, because a garbage collector makes your program slower. You manage the memory yourself. Bear in mind that this is giga complicated and there are countless of security risks and normal bugs because of that. Nevertheless, this makes C one of the fastest languages (if used correctly).

# Concepts

Recursion is possible in C.

But the more interesting feature are pointers.

## Pointers

Most of the time in other languages a variable is just a variable. But in C you can get the adress of where the variable is stored. A pointer doesnt store a variable, it stores the adress where the variable is located.

### Simple int example

```c
int a = 5; // this is a normal variable declaration
int* p; // to declare p as a pointer we have to write an asterisk
// the type is not here to say how big p will be, but rather how big the type will be to which the pointer will be pointing. The pointer itself will be the length of the adress, so 32/64 bit depending on the machine.
printf("%i", p); // this will print an adress, something like 0x56fc76ab
// To print the value that is stored in this adress we have to dereference the pointer.
printf("%i", *p); // 5
/*
Because we declared p as an pointer to an int, C knows that it has to look at the 32 bits from this adress on and interpret those 32 bit as an integer.
*/
```

### Simple array example

In most other languages this is trivial, but in C you have to manage the memory yourself, so before contructing an array you have to allocate memory for this array. And later you have to free the memory, because if you never give back the memory at some point you will have no memory left to write to.

```c
// the length of the array will be 10
int length = 10;
// To create an array you have to allocate memory on the heap, you have to specify how much memory you want to allocate. In this case we want to allocate an array for 10 integers. An integer is sizeof(int) big, which varies but in most cases is 4 byte. So in this case the compiler would allocate 10*4=40 bytes of uninitilized/free memory and it return a pointer to the beginning of the memory space. 
int* array = (int*) malloc(length * sizeof(int))
// We now have a pointer which points to the adress where our array begins.

// The memory right now as not initialized. So lets write something into it.
for (int i = 0; i < length; i++) {
    array[i] = i;
}
// [0,1,2,3,4,5,6,7,8,9]
// this is equivalent but with pointer arithmetics
for (int i = 0; i < length; i++) {
        *(array+i) = i;
}

// Lets now print
for (int i = 0; i < length; i++) {
    printf("%i", *(array+i)) // print array[i]
}

// When we dont need the array anymore, e.g. when going out of scope, we have to free the pointer pointing at the array, so the C compiler knows that it can use the memory for other things. Never freeing will cause memory leaks when writing any application which is not 10 lines long.
free(array);
```

Note that the following two lines are equivalent:
```c
array[i];
*(array+i); // adding or substracting from pointers, is called pointer arithmetics
```

# Examples

The entry function into a C program is the main function.

## Basics

```c
// main.c
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Hello world!")
}
```

We will use GCC as the example compiler.

This compiles the C program with the entry file `main.c` and outputs a binary with the name `main`
```shell
gcc main.c -o main
```

Execute the binary and you get printed `Hello world!`.

```shell
./main
> Hello world!
```

```c
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Hello world!\n");
    int a = 5;
    // if, else
    if (1 == 1)
    {
        printf("Variable a will be interpreted as an  integer and will get printed here: %i\n", a);
        printf("The bits where of variable a will be interpreted as a double (see IEEE floating numbers) and will get printed here: %f\n", a);
    }
    else if (2 == 1)
    {
        // this branch will not be executed and will probably be optimized away by the C compiler, because our of contains an constant expression.
    }
    else
    {
        // same as before
    }

    // for, while

    for (int i = 0; i < a; i++)
    {
        printf("This will count to 4 starting at 0: %i\n", i);
    }

    // infite loop:
    for (;;)
    {
        printf("iteration of the loop, remove break to be truly infinite.\n");
        break; // well it would be without the break, but we want to program to continue;
        // break tells to get out of the current control flow, like the following: for, while, switch
    }

    while (a < 7)
    {
        printf("a (%i) right now smaller than 7 so we are inside the while loop.\n", a);
        a++;
    }

    // infite loop, 1 means true, 0 means false
    while (1)
    {
        printf("iteration of the loop, remove break to be truly infinite.\n");
        break; // well it would be without the break, but we want to program to continue;
    }
}
```