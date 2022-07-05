#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>


int main(void)
{
    string sentence = get_string("Text: ");
    int letter_num = 0;
    int word_num = 1; // count the space instead
    int sentence_num = 0;
    for (int i = 0; i < strlen(sentence); i++)
    {
        if (isalpha(sentence[i]))
        {
            letter_num++;
        }
        else if (sentence[i] == ' ')
        {
            word_num++;
        }
        else if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            sentence_num++;
        }
    }
    // DO NOT use `float` here, use `double` or the grade will fluctuates!
    double L = (double) letter_num / (double) word_num * 100;
    double S = (double) sentence_num / (double) word_num * 100;
    int score = round(0.0588 * L - 0.296 * S - 15.8);
    
    if (score > 16)
    {
        printf("Grade 16+\n");
    }
    else if (score < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", score);
    }
}
