#include <stdio.h>
#include <cs50.c>

int main(void)
{
    int num = 7 ; //get_int("Height:");
    // while (num <= 0 || num >8)
    // {
    //     int num = get_int("Please enter a positive number between 1 and 8:  ");
    // }

    for (int i=0; i<num; i++)
    {
        for (int j=num; j>i+1 ; j--)
        {
            printf(" ");
        }
        for (int k=0; k<i+1; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int l=0; l<i+1; l++)
        {
            printf("#");
        }
        printf("\n");
    }

}