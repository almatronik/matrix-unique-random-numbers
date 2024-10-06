#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

#define range_max 100
#define range_min 0

// Function to clear the input buffer after every use of scanf.
void buffer_flushing()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        ;
    }
}

// Function to return the range of modulus to the main.
int get_mod_range()
{
    return (range_max - range_min) / 2; // Divided by 2 because only even numbers are allowed
}

// Function to ask the user of a positive number greater than 0.
int get_integer(char *message)
{
    int i = 0;
    do
    {
        printf("Enter the number of %s, the number must be > 0): \n", message);
        scanf("%d", &i);
        buffer_flushing();
    } while (i <= 0); // Keep asking until you get a positive number greater than 0.

    return i;
}

// Function to initialize all elements of the array to 0 before proceeding further. (Technically not needer but it is there for completeness).
void initialise_array2d(int R, int C, int (*array)[C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            *(*(array + i) + j) = 0;
        }
    }
}

void initialise_array1d(int len, int *array)
{
    for (int i = 0; i < len; i++)
    {
        *(array + i) = 0;
    }
}

// Function to create a random number in the range of range_min - range_max.
int create_random()
{
    int r;
    do
    {
        r = 2 * (range_min / 2 + rand() % (range_max / 2 - range_min / 2));
    } while (r % 2 == 1); // Keep asking until you get an even number.
    return r;
}

// Function to fill a pool of rundom numbers.
void fill_random_pool(int len, int *random_num_pool)
{
    for (int i = 0; i < len; i++)
    {
        *(random_num_pool + i) = create_random();
        for (int j = 0; j < i; j++)
        {
            if (*(random_num_pool + i) == *(random_num_pool + j))
            {
                i--;
            }
        }
    }
}

// Function to fill the array with random (NOT SO) unique numbers.
void fill_array(int R, int C, int (*array)[C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            do
            {
                *(*(array + i) + j) = create_random(); // Call the create function and receive a random number.
            } while ((check_uniqueness(R, C, array, *(*(array + i) + j), i, j) == -1)); // Keep doing that until you pass the uniqueness check.
        }
    }
}

// Function to fill the 2d array with numbers taken from the pool of random number.
void fill_array_from_random_pool(int R, int C, int (*array)[C], int *array1d)
{
    for (int i = 0, c = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            *(*(array + i) + j) = *(array1d + c++);
        }
    }
}
// Function to check if the passed number is unique or not. It doesn't work as intented.
int check_uniqueness(int R, int C, int (*array)[C], int a, int b, int c) // b and c correspond to index i and j in the function above. They are the upper limits to check.
{
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < c; j++) // This is probably endless loop. I need to set it to stop on the last filled element.
        {
            if (*(*(array + i) + j) == a)
            {
                return -1; // Return -1 if the check fails.
            }
        }
    }
    return 1;
}

// Function to print the 2d array to the terminal.
void print_array_2d(int R, int C, int (*array)[C])
{
    printf("\n\n");
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("%d ", *(*(array + i) + j));
        }
        printf("\n");
    }
}

// Function to sum per row.
void sum_vertical(int R, int C, int (*array)[C], int *sum_vertical_arr)
{
    for (int i = 0; i < C; i++)
    {
        int temp = 0;
        for (int j = 0; j < R; j++)
        {
            temp = temp + (*(*(array + j) + i));
        }
        *(sum_vertical_arr + i) = temp;
    }
}

// Function to sum per column
void sum_horizontal(int R, int C, int (*array)[C], int *sum_horizontal_arr)
{
    for (int i = 0; i < R; i++)
    {
        int temp = 0;
        for (int j = 0; j < C; j++)
        {
            temp = temp + (*(*(array + i) + j));
        }
        *(sum_horizontal_arr + i) = temp;
    }
}

// Function to print any 1d array to the terminal with custom title and a char at the end of each printf.
void print_array_1d(int *array, int len, char *text, char ch)
{
    printf("------------------\n%s:\n", text);
    for (int i = 0; i < len; i++)
    {
        printf("%d %c", *(array + i), ch);
    }
    printf("\n");
}
