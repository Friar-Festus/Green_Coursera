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
 * @file stats.c
 * @brief Calculate statistics on arrays of unsigned 8-bit values
 *
 * Calculate statistics on arrays of unsigned 8-bit values, including
 * mean, median, maximum and minimum values. Includes functions to 
 * print out a summary of the statistics and to sort a given array in 
 * descending order.
 *
 * @author Thomas Green
 * @date May 21, 2022
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/* Test statistics functions */
void main() { 

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  uint8_t sorted_array[SIZE];

  /* The following may not be necessary since they will be
   * calculated **inside** print_statistics(), but including
   * them for "Second Commit" */
  uint8_t median = 0;
  uint8_t mean = 0;
  uint8_t minimum = 255;
  uint8_t maximum = 0;

  // Void out "unused vars" for "Second Commit" to allow compilation w/ -Werror
  (void) median;
  (void) mean;
  (void) minimum;
  (void) maximum;

  (void) test;
  (void) sorted_array;

  /* Statistics and Printing Functions Go Here */
}

/* Add other Implementation File Code Here */
void print_statistics(uint8_t *ptrArray) {
  (void) ptrArray;

}

void print_array(uint8_t *ptrArray, uint8_t lenArray) {
  (void) ptrArray;
  (void) lenArray;
}

uint8_t find_median(uint8_t *ptrArray, uint8_t lenArray) {
  (void) ptrArray;
  (void) lenArray;

  return 0;
}

uint8_t find_mean(uint8_t *ptrArray, uint8_t lenArray) {
  (void) ptrArray;
  (void) lenArray;

  return 0;
}

uint8_t find_maximum(uint8_t *ptrArray, uint8_t lenArray) {
  (void) ptrArray;
  (void) lenArray;

  return 0;
}

uint8_t find_minimum(uint8_t *ptrArray, uint8_t lenArray) {
  (void) ptrArray;
  (void) lenArray;

  return 0;
}

void sort_array(uint8_t *ptrArray, uint8_t lenArray) {
  (void) ptrArray;
  (void) lenArray;
}
