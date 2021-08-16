#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int isInt(string word);
void caesar_Alogithm(string plaintext, string ciphertext, int key);

int main(int argc, string argv[])
{
    // TODO: Prompt for key
    if (argc != 2 || isInt(argv[1]) == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;  // Means something wrong
    }
    else
    {
        string plaintext = get_string("plaintext: ");
        int key = atoi(argv[1]);
        char ciphertext [strlen(plaintext)];

        // Use Caesar’s algorithm
        caesar_Alogithm(plaintext, ciphertext, key);
        printf("ciphertext: %s\n", ciphertext);
    }

}


int isInt(string word)
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (isdigit(word[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

void caesar_Alogithm(string plaintext, string ciphertext, int key)
{

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = 'A' + ((plaintext[i] - 'A') + key) % 26;
        }
        else if (islower(plaintext[i]))
        {
            ciphertext[i] = 'a' + ((plaintext[i] - 'a') + key) % 26;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

}