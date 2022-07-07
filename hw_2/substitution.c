#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substituition key");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!(isalpha(argv[1][i])))
        {
            printf("Usage: ./substituition key");
            return 1;
        }
        
        argv[1][i] = toupper(argv[1][i]);

        for (int j=i+1; j<26-i; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Usage: ./substituition key");
                return 1;
            }
        }
    }

    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    int letter;
    for (int j = 0; j < strlen(text); j++)
    {
        if (islower(text[j]))
        {
            letter = text[j] - 97;
            printf("%c", tolower(argv[1][letter]));
        }
        else if (isupper(text[j]))
        {
            letter = text[j] - 65;
            printf("%c", argv[1][letter]);
        }
        else
        {
            printf("%c", text[j]);
        }
    }
    return 1;
}