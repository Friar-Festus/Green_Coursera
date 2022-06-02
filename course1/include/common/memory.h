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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint-gcc.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Move an array of bytes from one location to another 
 *
 * Given a pointer to a byte data set, this will move the bytes
 * from a source address to a destination address.
 *
 * @param ptr Pointer to source array
 * @param ptr Pointer to destination 
 * @param Length of data to be moved
 *
 * @return ptr Pointer to destination
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copy an array of bytes from one location to another 
 *
 * Given a pointer to a byte data set, this will move the bytes
 * from a source address to a destination address.
 *
 * @param ptr Pointer to source array
 * @param ptr Pointer to destination 
 * @param Length of data to be copied
 *
 * @return ptr Pointer to destination
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Set all locations in a memory region to given value 
 *
 * Given a pointer to a memory location, a length and a value, 
 * set all locations in the memory region to the given value
 *
 * @param ptr Pointer to source array
 * @param Length of the memory region 
 * @param Value to set memory locations to
 *
 * @return ptr Pointer to source
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Set all locations in a memory region to zero 
 *
 * Given a pointer to a memory location, and a length, 
 * set all locations in the memory region to zero
 *
 * @param ptr Pointer to source array
 * @param Length of the memory region 
 *
 * @return ptr Pointer to source
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverse the order of bytes in a memory region
 *
 * Given a pointer to a memory location, and a length, 
 * reverse the order of the bytes in the memory region
 *
 * @param ptr Pointer to source array
 * @param Length of the memory region 
 *
 * @return ptr Pointer to source
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Reserve a number of words in dynamic memory
 *
 * Given a pointer to a memory location, and a length, 
 * reverse the order of the bytes in the memory region
 *
 * @param Number of words to reserve 
 *
 * @return ptr Pointer to memory if successful, else NULL
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Free up dynamically allocated memory
 *
 * Given a pointer to a memory location, free up the
 * memory stored in that location
 *
 * @param ptr Pointer to source array
 *
 * @return void
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
