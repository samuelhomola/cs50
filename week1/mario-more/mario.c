#include <cs50.h>
#include <stdio.h>

void print_mario(int height);

int main(void)
{
    // Prompt user for height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print Mario
    print_mario(height);
}

void print_mario(int height)
{
    for (int i = 0; i < height; i++)
    {
        // Print spaces
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Print hashes
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        // Print gap
        printf("  ");

        // Print hashes
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        // Print new line
        printf("\n");
    }
}
