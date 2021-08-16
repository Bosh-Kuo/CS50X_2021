#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long int Number;
    long int Number_cy;
    int sum = 0;
    int count = 1;
    int digit;

    do
    {
        Number = get_long("Number: ");
    }
    while (Number < 0);
    Number_cy = Number;

    do
    {
        if (count % 2 != 0)
        {
            sum += (Number % 10);
            Number /= 10;
        }
        else
        {
            if ((Number % 10) * 2 >= 10)
            {
                sum = sum + ((Number % 10) * 2) / 10 + ((Number % 10) * 2) % 10;
            }
            else
            {
                sum += (Number % 10) * 2;
            }

            Number /= 10;
        }

        count++;
    }
    while (Number > 0);

    digit = count - 1;

    // TODO: Judget
    if ((sum % 10 == 0) && ((digit == 13) || (digit == 15) || (digit == 16)))
    {
        if ((int)(Number_cy / pow(10, digit - 1)) == 4 && (digit == 13 || digit == 16))
        {
            printf("VISA\n");
        }
        else if (((int)(Number_cy / pow(10, digit - 2)) == 34 || (int)(Number_cy / pow(10, digit - 2)) == 37) && (digit == 15))
        {
            printf("AMEX\n");
        }
        else if (((int)(Number_cy / pow(10, digit - 2)) >= 51 && (int)(Number_cy / pow(10, digit - 2)) <= 55) && (digit == 16))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    // printf("digit :%i\n", digit);
    // printf("sum :%i\n", sum);
    // printf("first :%i\n",  (int) (Number_cy / (pow(10,digit-1))) );



}