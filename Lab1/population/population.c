#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startSize;
    int endSize;
    int size;
    int year = 0;

    // TODO: Prompt for start size
    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    size = startSize;
    while (size < endSize)
    {
        size = (size * 4 / 3) - (size / 4);
        year ++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", year);
}