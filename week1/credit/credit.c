#include <cs50.h>
#include <stdio.h>

long get_card_number(void);
bool is_valid_card(long number);
int get_card_length(long number);
int get_first_two_digits(long number);
void print_card_brand(long number);

int main(void)
{
    long card_number = get_card_number();
    if (is_valid_card(card_number))
    {
        print_card_brand(card_number);
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

long get_card_number(void)
{
    return get_long("Number: ");
}

bool is_valid_card(long number)
{
    int sum = 0;
    int position = 0;
    long working_number = number;

    while (working_number > 0)
    {
        int digit = working_number % 10;

        if (position % 2 == 1)
        {
            int doubled = digit * 2;
            sum += (doubled / 10) + (doubled % 10);
        }
        else
        {
            sum += digit;
        }

        working_number /= 10;
        position++;
    }

    return (sum % 10 == 0);
}

int get_card_length(long number)
{
    int length = 0;
    while (number > 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

int get_first_two_digits(long number)
{
    while (number >= 100)
    {
        number /= 10;
    }
    return (int) number;
}

void print_card_brand(long number)
{
    int length = get_card_length(number);
    int first_two_digits = get_first_two_digits(number);

    if ((length == 15) && (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
    }
    else if ((length == 16) && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && (first_two_digits / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
