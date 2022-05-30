# Intro to Embedded Systems - Course 1 Final Assessment

## Expanded Build System and Memory

**Author**: Thomas Green

`stats.c` and `stats.h` - Include functions to:
- Calculate median value of an array
- Calculate mean value of an array
- Determine the minimum and maximum values of an array
- Sort an array in descending order
- Print out a summary of calculated statistics

Note that the result in integer math division is always truncated (rounded down); no additional math functions are required for rounding down as specified in the assignment.

The standard library function `qsort()` is used to sort the array rather than implementing a sorting algorithm.

`main()` includes a test array to use for testing the functions.

