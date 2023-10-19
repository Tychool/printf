#include "main.h"
/**
 * printf_unsign - unsingned int
 * @typs: args
 * @buf_array: print buffer
 * @IDs: identifiers
 * @width: width
 * @precision: precision
 * @size: size
 * Return: result
 */
int printf_unsign(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size)
{
	int i = PRINT_BUFFER_SIZE - 2;
	unsigned long int numIN = va_arg(typs, unsigned long int);

	numIN = size_converter_uint(numIN, size);

	if (numIN == 0)
		buf_array[i--] = '0';

	buf_array[PRINT_BUFFER_SIZE - 1] = '\0';

	while (numIN > 0)
	{
		buf_array[i--] = (numIN % 10) + '0';
		numIN /= 10;
	}

	i++;

	return (_write_uint(0, i, buf_array, IDs, width, precision, size));
}

/**
 * printf_oct - octal
 * @typs: args
 * @buf_array: print buffer
 * @IDs:  identifier
 * @width: width
 * @precision: precision
 * @size: size
 * Return: result
 */
int printf_oct(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size)
{

	int i = PRINT_BUFFER_SIZE - 2;
	unsigned long int numIN = va_arg(typs, unsigned long int);
	unsigned long int init_numIN = numIN;

	UNUSED(width);

	numIN = size_converter_uint(numIN, size);

	if (numIN == 0)
		buf_array[i--] = '0';

	buf_array[PRINT_BUFFER_SIZE - 1] = '\0';

	while (numIN > 0)
	{
		buf_array[i--] = (numIN % 8) + '0';
		numIN /= 8;
	}

	if (IDs & FUN_HASH && init_numIN != 0)
		buf_array[i--] = '0';

	i++;

	return (_write_uint(0, i, buf_array, IDs, width, precision, size));
}

/**
 * printf_hex - hexadecimal in lowercase
 * @typs: args
 * @buf_array: print buffer
 * @IDs: idemtifiers
 * @width: width
 * @precision: precision
 * @size: size
 * Return: result
 */
int printf_hex_help(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size)
{
	return (printf_hexa_help(typs, "0123456789abcdef", buf_array,
		IDs, 'x', width, precision, size));
}

/**
 * printf_HEX - HEXADECIMAL in uppercase kike that
 * @typs: args
 * @buf_array: print buffer
 * @IDs: idemtifiers
 * @width: width
 * @precision: orecision
 * @size: size
 * Return: result
 */
int printf_HEX(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size)
{
	return (printf_hexa_help(typs, "0123456789ABCDEF", buf_array,
		IDs, 'X', width, precision, size));
}

/**
 * printf_hexa_help - print hexadecimal
 * @types: arg
 * @mapping: mapping array
 * @buf_array: print buffer
 * @IDs: identifiers
 * @flaging: idenifiers
 * @width: get width
 * @precision: precisionn
 * @size: size
 * @size: size
 * Return: result
 */
int print_hexa_help(va_list typs, char mapping[], char buf_array[],
	int IDs, char flaging, int width, int precision, int size)
{
	int i = PRINT_BUFFER_SIZE - 2;
	unsigned long int numIN = va_arg(typs, unsigned long int);
	unsigned long int init_numIN = numIN;

	UNUSED(width);

	num = size_converter_uint(numIN, size);

	if (numIN == 0)
		buf_array[i--] = '0';

	buf_array[PRINT_BUFFER_SIZE - 1] = '\0';

	while (numIN > 0)
	{
		buf_array[i--] = mapping[numIN % 16];
		numIN /= 16;
	}

	if (IDs & FUN_HASH && init_numIN != 0)
	{
		buf_array[i--] = flaging;
		buf_array[i--] = '0';
	}

	i++;

	return (_write_uint(0, i, buf_array, IDs, width, precision, size));
}
