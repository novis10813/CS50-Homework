#include <stdio.h>
#include <cs50.h>


void pyramid(int n)
{
    for (int i=0; i < n; i++)
    {
        for (int j=n; j>i+1 ; j--)
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

void pyramid(int n);

int main(void)
{
    int Num;
    do
    {
        Num = get_int("Height:");
    }
    while (!(Num > 0 && Num < 9));
    pyramid(Num);
    return 0;
}