#ifndef _ALGO_H_
#define _ALGO_H_

#include <stdio.h>
#include <math.h>

int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);

#endif /* _ALGO_H_ */
