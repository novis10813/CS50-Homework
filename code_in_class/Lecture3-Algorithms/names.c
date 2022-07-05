#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    string names[] = {"Bill", "Sam", "Fred", "Ron", "Chad", "Smith", "OK"};
    
    // don't use "==" to check names[i] e
    for (int i = 0; i < strlen(names); i++)
    {
        if (strcmp("Ron", names[i])) // if in, return true
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}