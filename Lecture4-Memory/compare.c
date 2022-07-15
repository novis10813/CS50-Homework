#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{
    // All different
    // string s = get_string("s: ");
    // string t = get_string("t: ");

    // if (s == t)
    // {
    //     printf("Same\n");
    // }
    // else
    // {
    //     printf("Different\n");
    // }

    // This work
    char *s = get_string("s: ");
    char *t = get_string("t: ");
    // strcmp actually takes in the address of a string
    if (strcmp(s, t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}