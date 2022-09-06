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