#include <stdio.h>
#include <stdlib.h>

int main(void) {


    // int list[3]; // put memory on stack
    int *list = malloc(3 * sizeof(int)); // put memory on heap
    if (list == NULL){
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // A more pointer method
    // *list = 1;
    // *(list +1) = 2;
    // *(list +2) = 3;
    
    // When you realize you need more space.

    // int *tmp = malloc(4 * sizeof(int));
    // if (tmp == NULL){
    //     free(list);
    //     return 1;
    // }

    // for (int i = 0; i <3; i++){
    //     tmp[i] = list[i];
    // }

    // use realloc instead
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL){
        free(list);
        return 1;
    }

    // add new value
    tmp[3] = 4;

    // free old array
    // free(list);

    // assign tmp address to new `list`
    list = tmp;

    for (int i = 0; i <4; i++){
        printf("%i\n", list[i]);
    }
    free(list);
    return 0;
}