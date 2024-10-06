#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>

/**
 * @brief This function is used to sanitize the input buffer
 *
 * @return void
 */
void buffer_flushing();

/**
 * @brief This function is used to get an integer from the user and validate it.
 *
 * @param message Only the string "rows" or "columns" for the printf
 * @return int - A validated positive number greater than 0
 */
int get_integer(char *message);

/**
 * @brief Get the mod range object and pass it to main function.
 *
 * @return int The range of modulus divided by 2 because only even numbers are allowed
 */
int get_mod_range();

/**
 * @brief This function sets all elements of the array to zero
 *
 * @param R The number of rows.
 * @param C The number of columns.
 * @param array The 2d array itself passed by reference.
 * @return void
 */
void initialise_array2d(int R, int C, int (*array)[C]);
void initialise_array1d(int len, int *array);

/**
 * @brief This function creates a random number and keeps trying until the number is even.
 *
 * @return int - A random even number
 */
int create_random();

/**
 * @brief This function will call the create_random() function and fill the array with it.
 *
 * @param R The number of rows.
 * @param C The number of columns.
 * @param array The 2d array itself passed by reference.
 * @return void
 */
void fill_array(int R, int C, int (*array)[C]);
void fill_random_pool(int len, int *random_num_pool);
void fill_array_from_random_pool(int R, int C, int (*array)[C], int *array1d);

/**
 * @brief This function is supposed to check if the number passed exists already or not. (The results are not reliable!!!)
 *
 * @param R The number of rows.
 * @param C The number of columns.
 * @param array The 2d array itself passed by reference.
 * @param a The current number to be checked.
 * @param b The index i that corresponds to the value to be checked. It will be used as upper bound during the dublicity check.
 * @param c The index j that corresponds to the value to be checked. It will be used as upper bound during the dublicity check.
 * @return int -1 if the random number exists already hence not being unique. 1 otherwise.
 */
int check_uniqueness(int R, int C, int (*array)[C], int a, int b, int c);

/**
 * @brief This function prints a 2d the array to the terminal
 *
 * @param R The number of rows.
 * @param C The number of columns.
 * @param array The 2d array itself passed by reference.
 * @return void
 */
void print_array_2d(int R, int C, int (*array)[C]);

/**
 * @brief This function creates the vertical sum and stores the result in the respective array.
 *
 * @param R The number of rows.
 * @param C The number of columns.
 * @param array The 2d array itself passed by reference.
 * @param sum_vertical_arr The array of per row sum passed by reference.
 * @return void
 */
void sum_vertical(int R, int C, int (*array)[C], int *sum_vertical_arr);

/**
 * @brief This function creates the horizontal sum and stores the result in the respective array.
 *
 * @param R The number of rows.
 * @param C The number of columns.
 * @param array The 2d array itself passed by reference.
 * @param sum_horizontal_arr The array of per colum sum passed by reference.
 * @return
 */
void sum_horizontal(int R, int C, int (*array)[C], int *sum_horizontal_arr);

/**
 * @brief This is a function to print a one dimension array to the terminal
 *
 * @param array The 1d that holds the summary per rows and columns respectivelly passed by reference.
 * @param len The length of the array.
 * @param text The text to be printed above the summary.
 * @param ch A character (either '\n' or ' ') that will help formating the output since the same function is being used for both vertical and horizontal prints.
 * @return void
 */
void print_array_1d(int *array, int len, char *text, char ch);

#endif // MATRIX_H