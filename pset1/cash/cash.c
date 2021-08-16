#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int coins = 0;
    int cents;
    float dollars;
    
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    
    cents = round(dollars * 100);
    
    //TODO: Greedy Algorithms
    do
    {
        if (cents >= 25)
        {
            cents = cents - 25;
            coins ++;
        }
        else if (cents >= 10)
        {
            cents = cents - 10;
            coins ++;
        }
        else if (cents >= 5)
        {
            cents = cents - 5;
            coins ++;
        }
        else if (cents >= 1)
        {
            cents = cents - 1;
            coins ++;
        }
            
    }
    while (cents != 0);
    
    printf("%i\n", coins);
}
