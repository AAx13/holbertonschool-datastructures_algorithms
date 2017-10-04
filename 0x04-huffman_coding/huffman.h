#ifndef _HUFF_H_
#define _HUFF_H_

/**
 * struct symbol_s - Stores a char and its associated frequency
 *
 * @data: The character
 * @freq: The associated frequency
 */
typedef struct symbol_s
{
	char data;
	size_t freq;
} symbol_t;

#endif /* _HUFF_H_ */
