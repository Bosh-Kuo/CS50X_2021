#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    float word_num = 1;
    float letter_num = 0;
    float sentence_number = 0;
    int index;
    
    // Get input texts
    string text = get_string("Text: ");
    for (int i = 0; i < strlen(text) ; i++)
    {
        if (isspace(text[i]))
        {
            word_num += 1;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence_number += 1;
        }
        else if (isalpha(text[i]))
        {
            letter_num += 1;
        }
    }
    
    index = round(0.0588 * (letter_num * 100 / word_num) - 0.296 * (sentence_number * 100 / word_num) - 15.8);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    
    

}