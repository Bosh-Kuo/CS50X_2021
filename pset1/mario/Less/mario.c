#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int spaces;
    int hashes;
    
    // TODO: Prompt for height
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    // TODO: print pyramid
    for (int i = 0; i < height; i++)
    {
        spaces = height - i - 1;
        hashes = i + 1;
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < hashes; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}