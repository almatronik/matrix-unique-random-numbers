/**
 * @file matrix.h
 * @author Alexander Markantonis (alexander.markantonis@ya.se)
 * @brief A program to create a 2D array with a number of rows and columns
 *          entered by the user. The array then gets filled with unique even numbers.
 *          1) A function to get rows and columns with input validation
 *          2) A function to sanitize the input buffer after every scanf.
 *          3) A function to initialize the array with zeros.
 *          4) A function to create a random even number.
 *          5) A function to check if the random number is unique or not.
 *          6) A function to fill the array with random numbers
 *          7) A function to print the array to the terminal
 *          8) A function to sum all elements verticall and store them in an array.
 *          9) A function to sum all elements horizontally and store them in an array.
 *
 * @version 0.2
 * @date 2023-12-06
 *
 * @copyright GPL v3.0
 *
 */

#include "matrix.h"
#include <stdio.h>
#include <stdlib.h> //stdlib needed for the srand function
#include <time.h>   // time needed to seed the random function with the current time.

int R, C; // No need to set to zero because they get initialized to zero inside the get_integer().

int main(void)
{
    srand(time(NULL));

    int R = 0;
    int C = 0;
    do
    {
        R = get_integer("rows");
        C = get_integer("columns");
    } while (R * C > get_mod_range() && printf("%d * %d = %d while the maximum possible unique numbers given the modulus range is = %d.\nThis will lead to an endless loop. Try again with lower numbers:\n", R, C, R * C, get_mod_range()));

    int random_num_pool[R * C];
    initialise_array1d(R * C, random_num_pool);
    print_array_1d(random_num_pool, R * C, "Random number pool, initialized to zero", ' ');
    fill_random_pool(R * C, random_num_pool);
    print_array_1d(random_num_pool, R * C, "Random number pool filled with random numbers", ' ');

    int array[R][C];                 // Declaration of variably length 2d array.
    initialise_array2d(R, C, array); // Sets all elements to zero
    // fill_array(R, C, array); // Fills the array with unique random numbers.     // Switch those two lines and you
    fill_array_from_random_pool(R, C, array, random_num_pool); // will see dublicates in the matrix.
    print_array_2d(R, C, array);                               // Prints the 2d array to the terminal.

    int sum_horizontal_arr[R];                                      // Declaring an array for the horizontal array to be stored.
    int sum_vertical_arr[C];                                        // Declaring an array for the vertical sum to be stored.
    sum_horizontal(R, C, array, sum_horizontal_arr);                // Creates the sum per row and stores it in the sum rows array.
    sum_vertical(R, C, array, sum_vertical_arr);                    // Creates the sum per column and stores it in the sum columns array.
    print_array_1d(sum_horizontal_arr, R, "Summury per row", '\n'); // Prints the summury of each column to the terminal. This is the bottom horizontal print.
    print_array_1d(sum_vertical_arr, C, "Summury per col", ' ');    // Prints the summury of each row to the terminal. This is the vertical print.

    return 0;
}
