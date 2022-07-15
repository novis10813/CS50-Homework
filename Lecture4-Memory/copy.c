#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {
    // When change t, s change, too.
    // string s = get_string("s: ");
    // string t = s;

    // t[0] = toupper(t[0]);

    // printf("%s\n", s);
    // printf("%s\n", t);

    char *s = get_string("s: ");
    char *t = malloc(strlen(s) + 1); // 1 for \0
    if (t == NULL){
        return 1;
    }
    
    strcpy(t, s);

    if (strlen(t) > 0){
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);

    free(t);
    return 0;
}