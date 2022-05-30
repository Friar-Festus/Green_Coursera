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
#include <stdlib.h>
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
  uint8_t testCopy[SIZE]; // work on a sorted copy of the array

  /* Statistics and Printing Functions Go Here */
  for (uint8_t i = 0; i < SIZE; ++i) {
    testCopy[i] = test[i]; 
  }

  /* Calculating array length on the fly instead of using
   * SIZE to make this more generic, even though this is 
   * test code for the functions. */

  printf("Original array of values:\n\n");
  print_array(test, sizeof(test) / sizeof(test[0]));

  // Sort first so median works correctly
  sort_array(testCopy, sizeof(testCopy) / sizeof(testCopy[0]));

  printf("Sorted array of values:\n\n");
  print_array(testCopy, sizeof(testCopy) / sizeof(testCopy[0]));

  print_statistics(testCopy, sizeof(testCopy) / sizeof(testCopy[0]));
}

/* Add other Implementation File Code Here */
void print_statistics(uint8_t *ptrArray, uint8_t lenArray) {
  printf("\nStatistics related to the array:\n");
  printf("=================================\n");
  printf("Mean:    %d\n", find_mean(ptrArray, lenArray));
  printf("Median:  %d\n", find_median(ptrArray, lenArray));
  printf("Max:     %d\n", find_maximum(ptrArray, lenArray));
  printf("Min:     %d\n", find_minimum(ptrArray, lenArray));

}

void print_array(uint8_t *ptrArray, uint8_t lenArray) {
  printf(" Index | Value\n");
  printf("=======|=======\n");
  for (uint8_t i = 0; i < lenArray; ++i) {
    printf("%5d  |%5d\n", i, ptrArray[i]);
  }
}

uint8_t find_median(uint8_t *ptrArray, uint8_t lenArray) {
  /* The median value is in the center of the sorted array. If the
   * number of elements is even, average the middle two elements,
   * else use the entry at the center index. */
  uint8_t median = 0;
  uint8_t index = lenArray / 2;
  
  if ((lenArray % 2) == 0) { // Number of elements is even
    median = ((uint16_t) ptrArray[index] + (uint16_t) ptrArray[index-1]) / 2;
  } else { // Number of elements is odd
    median = ptrArray[index];
  }

  return median;
}

uint8_t find_mean(uint8_t *ptrArray, uint8_t lenArray) {
  uint16_t total = 0;
  for (uint8_t i = 0; i < lenArray; ++i) {
    total += ptrArray[i];
  }

  return total / lenArray;
}

uint8_t find_maximum(uint8_t *ptrArray, uint8_t lenArray) {
  uint8_t maximum = 0;
  for (uint8_t i = 0; i < lenArray; ++i) {
    if (ptrArray[i] > maximum) {
      maximum = ptrArray[i];
    }
  }

  return maximum;
}

uint8_t find_minimum(uint8_t *ptrArray, uint8_t lenArray) {
  uint8_t minimum = 255;
  for (uint8_t i = 0; i < lenArray; ++i) {
    if (ptrArray[i] < minimum) {
      minimum = ptrArray[i];
    }
  }

  return minimum;
}

void sort_array(uint8_t *ptrArray, uint8_t lenArray) {
  /* Copy to new array. Passing original to qsort() within
   * this function doesn't work due to pointer decay. */
  uint8_t newArray[SIZE];
  for (uint8_t i = 0; i < lenArray; ++i) {
    newArray[i] = ptrArray[i];
  }
  
  /* Sort the array using standard library function */
  qsort(newArray, lenArray, sizeof(uint8_t), compfunc);

  /* Copy back into the array passed in by reference. */
  for (uint8_t i = 0; i < lenArray; ++i) {
    ptrArray[i] = newArray[i];
  }
}

int compfunc (const void * a, const void * b) {
   return ( *(const uint8_t*)b - *(const uint8_t*)a );
}