#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    float owed;
    do
    {
        owed = get_float("Change owed:  \n");
    } while (!(owed>0));

    int changes = 0;

    //convert dollars to cents
    int cents = round(owed * 100);

    //check cents that you owed
    int div_by_25 = cents / 25;
    int remain_cents_25 = cents % 25;

    // Record how many coins you need to give
    changes = changes + div_by_25;

    int div_by_10 = remain_cents_25 / 10;
    int remain_cents_10 = remain_cents_25 % 10;

    changes = changes + div_by_10;

    int div_by_5 = remain_cents_10 / 5;
    int remain_cents_5 = remain_cents_10 % 5;

    changes = changes + div_by_5 + remain_cents_5;
    printf("%d\n", changes);
}