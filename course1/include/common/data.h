/**
 * @file data.h
 * @brief Integer <-> ASCII Functions
 *
 * This header file provides functions to convert an
 * integer to an ASCII string or an ASCII string to an integer.
 * Bases from 2 to 16 are supported.
 *
 * @author Thomas Green
 * @date June 1 2022
 * *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint-gcc.h>

#define BASE_2      2U
#define BASE_8      8U
#define BASE_10     10U
#define BASE_16     16U

/**
 * @brief Convert an integer to an ASCII array 
 *
 * Given an integer, a pointer to a memory location, and
 * a base, this function will convert the integer to the 
 * given base and fill the memory location with characters
 * representing the value in that base.
 *
 * @param data Integer to convert
 * @param ptr Pointer to data array
 * @param base Base to convert to (2 to 16)
 *
 * @return Number of characters in array, including terminator.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Convert an ASCII array to an integer 
 *
 * Given a pointer to a char data set, the number of digits 
 * contained in the set, and the base to convert from, this 
 * function will convert the string to an integer.
 *
 * @param ptr Pointer to data array
 * @param digits The number of digits in the data array
 * @param base Base to convert from (2 to 16)
 *
 * @return Resulting integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
