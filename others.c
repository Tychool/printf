#include "main.h"

/**
 * check_printable - check if char in is printable
 * @c: Char
 * Return: 1 true, 0 false
 */
int check_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * ap_hex- enlist ASSCI of hex to buffer
 * @buf_array: buffer
 * @i: Index
 * @ascode: ASSCI
 * Return: result 3
 */
int ap_hex(char ascode, char buf_array[], int i)
{
	char mapping[] = "0123456789ABCDEF";
	if (ascode < 0)
		ascode *= -1;

	buf_array[i++] = '\\';
	buf_array[i++] = 'x';

	buf_array[i++] = mapping[ascode / 16];
	buf_array[i] = mapping[ascode % 16];

	return (3);
}

/**
 * check_digit - check if input digit
 * @c: in
 * Return: result
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * size_converter_int - convert int
 * @num: number
 * @size: size
 *
 * Return: return
 */
long int size_converter_int(long int num, int size)
{
	if (size == SWEET_LNG)
		return (num);
	else if (size == SWEET_SHRT)
		return ((short)num);

	return ((int)num);
}

/**
 * size_converter_uint - convert unsigned int
 * @num: Number
 * @size: size
 *
 * Return: result
 */
long int size_converter_uint(unsigned long int num, int size)
{
	if (size == SWEET_LNG)
		return (num);
	else if (size == SWEET_SHRT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
