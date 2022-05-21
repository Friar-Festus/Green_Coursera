/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief Calculate and print array statistics
 *
 * Function prototypes for the calculation and 
 * display of statistics for a given array, such
 * as minimum, maximum, mean, etc.
 * 
 * I subscribe to the Ganssle view that standard types should always be used,
 * therefore uint8_t data type is used instead of unsigned char, though 
 * unsigned char is guaranteed to be 8 bits. I just find it weird to use 
 * "char" for numerical values.
 *
 * @author Thomas Green
 * @date May 21, 2022
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#pragma GCC diagnostic ignored "-Wmain"

#include <inttypes.h>

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Print calculated statistics to console
 *
 * Print a table of statistics for the given array
 * of integers to the console, including maximum,
 * minimum, mean, median and length.
 *
 * @param *ptrArray Pointer to the array
 *
 * @return void
 */
void print_statistics(uint8_t *ptrArray);

/**
 * @brief Print out a table of the array
 *
 * Print the array in tabular format.
 *
 * @param *ptrArray Pointer to the array
 * @param lenArray  Length of the input array
 *
 * @return void
 */
void print_array(uint8_t *ptrArray, uint8_t lenArray);

/**
 * @brief Determine the median value in the array
 *
 * Iterate through the array to determine the median
 * value.
 *
 * @param *ptrArray Pointer to the array
 * @param lenArray  Length of the input array
 *
 * @return Median value of the array
 */
uint8_t find_median(uint8_t *ptrArray, uint8_t lenArray);

/**
 * @brief Determine the mean value for the array
 * 
 * Calculate the mean of the values in the array.
 *
 * @param *ptrArray Pointer to the array
 * @param lenArray  Length of the input array
 *
 * @return Mean value of the array
 */
uint8_t find_mean(uint8_t *ptrArray, uint8_t lenArray);

/**
 * @brief Find the maximum value in the array
 *
 * Find and return the maximum value in the array.
 *
 * @param *ptrArray Pointer to the array
 * @param lenArray  Length of the input array
 *
 * @return Maximum value in the array
 */
uint8_t find_maximum(uint8_t *ptrArray, uint8_t lenArray);

/**
 * @brief Find the minimum value in the array
 *
 * Find and return the minimum value in the array.
 *
 * @param *ptrArray Pointer to the array
 * @param lenArray  Length of the input array
 *
 * @return Minimum value in the array
 */
uint8_t find_minimum(uint8_t *ptrArray, uint8_t lenArray);

/**
 * @brief Sort the input array in descending order
 *
 * Sort the input array in descending order. Array must 
 * be passed in by reference since it is not possible 
 * to return arrays.
 *
 * @param *ptrArray Pointer to the array
 * @param lenArray  Length of the input array
 *
 * @return void - Array is sorted in place
 */
void sort_array(uint8_t *ptrArray, uint8_t lenArray);

#endif /* __STATS_H__ */
