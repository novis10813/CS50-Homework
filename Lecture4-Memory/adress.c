#include <stdio.h>
#include <cs50.h>

int main(void) {
    // int is stored with 4 byte
    // int n = 50;

    // // pointers, shows where the data is stored.
    // int *p = &n;
    // printf("%p\n", p);
    // printf("%i\n", *p);

    // s is the address of the first character in the string
    // string s = "HI!";
    // char *p = &s[0];
    // printf("%p\n", s);
    // printf("%p\n", p);

    // string s = "HI!";
    char *s = "HI!";
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);
    printf("%c\n", s[3]);
}