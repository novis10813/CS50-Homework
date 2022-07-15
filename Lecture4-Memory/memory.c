#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int *x = malloc(3 * sizeof(int));
    x[1] = 72; // didn't start from zero
    x[2] = 73;
    x[3] = 33; // touching the memory you shouldn't
    free(x);
}