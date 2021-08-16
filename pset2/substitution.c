#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


void caesar_Alogithm(string plaintext, string key);

int main(int argc, string argv[])
{
    // TODO: Prompt for key
    if (argc != 2 )
    {
        printf("Usage: ./substitution key\n");
        return 1;  // Means something wrong
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;  // Means something wrong
    }
    else
    {
        //check invalid characters in key
        string key = argv[1];
        for (int i = 0; i < strlen(key); i++)
        {
            if (!isalpha(key[i]))
            {
                printf("Key contain non-alphabetic characters.\n");
                return 1;
            }
            for (int j = 0; j < strlen(key); j++)
            {
                if (toupper(key[i]) == toupper(key[j]) && i != j)
                {
                    printf("Key contain repeated characters.\n");
                    return 1;
                }
            }

        }

        string plaintext = get_string("plaintext: ");
        // Use Caesar’s algorithm
        caesar_Alogithm(plaintext, key);
        return 0;
    }
}


void caesar_Alogithm(string plaintext, string key)
{
    int index_i;
    char ciphertext[strlen(plaintext)];
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            index_i = plaintext[i] - 'A';
            ciphertext[i] = toupper(key[index_i]);
        }
        else if (islower(plaintext[i]))
        {
            index_i = plaintext[i] - 'a';
            ciphertext[i] = tolower(key[index_i]);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    printf("ciphertext: %s\n", ciphertext);

}

