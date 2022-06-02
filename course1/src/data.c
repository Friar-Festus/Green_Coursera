/**
 * @file data.c
 * @brief Integer <-> ASCII Functions
 *
 * This implementation file provides functions to convert an
 * integer to an ASCII string or an ASCII string to an integer.
 * Bases from 2 to 16 are supported.
 *
 * @author Thomas Green
 * @date June 1 2022
 *
 */

#include "data.h"
#include "platform.h"
#include <stdint-gcc.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    uint8_t digits = 0;
    uint8_t addDigits = 0;

    if ((base < 2) || (base > 16)) {
        PRINTF("Base %d not supported!\n", base);
        return(0);
    }

    unsigned char ascDigits[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
                                    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    
    uint32_t startFactor[17] = {
        0, 0, 2147483648, 3486784401, 1073741824,
        1220703125, 2176782336, 1977326743, 1073741824,
        3486784401, 100000000, 2357947691, 429981696,
        815730721, 105413504, 170858375, 268435456 };

    if (data < 0) {
        *(ptr + digits) = '-';
        ++digits;
        data *= -1;
    }

    uint32_t factor = startFactor[base];
    uint32_t temp;
    while (factor >= base){
        temp = data / factor;
        if (temp) {
            *(ptr + digits) = ascDigits[temp];
            data -= temp * factor;
            ++digits;
            addDigits = 1;
        } else if (addDigits) {
            *(ptr + digits) = ascDigits[0];
            ++digits;
        }

        factor /= base;
    }

    *(ptr + digits) = ascDigits[data];
    ++digits;

    // Add null termination
    *(ptr + digits) = '\0';
    ++digits;

    return digits;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    // Convert ASCII to integer w/ base
    int32_t signed_int = 0;
    int8_t neg = 1;
    uint8_t mult = 0;
    uint32_t factor = 1;
    uint8_t value = 0;

    for (int8_t i = 0; i < digits-1; ++i) {
        if (ptr[i] == '-'){
            neg = -1;
            continue;
        }

        if (ptr[i] - '0' <= 9) {
            value = ptr[i] - '0';
        } else {
            value = ptr[i] - '7';
        }

        if (i == digits - 1) {
            signed_int += value;
            continue;
        } else {
            mult = digits - (i + 2);
        }

        for (uint8_t j = 0; j < mult; j++){
            factor = factor * base;
        }

        signed_int += value * factor;

        factor = 1;
    }


    return(signed_int * neg);
}