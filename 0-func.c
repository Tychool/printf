#include "main.h"

/**
 * printf_c - character print
 * @typs: arg
 * @buf_array: arg array
 * @IDs:  active identifiers
 * @width: width
 * @precision: precision
 * @size: aize
 * Return: result
 */
int printf_c(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size)
{
	char c = va_arg(typs, int);

	return (_write_char(c, buf_array, IDs, width, precision, size));
}
/**
 * printf_str - print stringa
 * @typs: args
 * @buf_array: arg array
 * @IDs:  active identifiera
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int printf_str(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(typs, char *);

	UNUSED(buf_array);
	UNUSED(IDs);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (IDs & FUN_SUB)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}
/**
 * printf_percentage - print %
 * @typs: arg list
 * @buf_array: print array
 * @IDs:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: result
 */
int printf_percentage(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size)
{
	UNUSED(typs);
	UNUSED(buf_array);
	UNUSED(IDs);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * printf_int - print integera
 * @typs: arg lists
 * @buf_array: print buffer
 * @IDs:  Calculates active flags
 * @width: width
 * @precision: precision
 * @size: Size specifier
 * Return: result
 */
int printf_int(va_list typs, char buf_array[],
	int flags, int width, int precision, int size)
{
	int i = PRINT_BUFFER_SIZE - 2;
	int is_neg = 0;
	long int no = va_arg(typs, long int);
	unsigned long int number;

	no = size_converter_int(no, size);

	if (no == 0)
		buf_array[i--] = '0';

	buf_array[PRINT_BUFFER_SIZE - 1] = '\0';
	number = (unsigned long int)no;

	if (no < 0)
	{
		number = (unsigned long int)((-1) * no);
		is_neg = 1;
	}

	while (number > 0)
	{
		buf_array[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	return (_write_int(is_neg, i, buf_array, IDs, width, precision, size));
}
/**
 * printf_bin - print binary unsigned
 * @typs: arg list
 * @buf_array: print buffer
 * @IDs:  identifiers
 * @width: width
 * @precision: precision spec
 * @size: size
 * Return: rwsult
 */
int printf_bin(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size)
{
	unsigned int a, b, i, sum;
	unsigned int n[32];
	int indx;

	UNUSED(buf_array);
	UNUSED(IDs);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	a = va_arg(typs, unsigned int);
	b = 2147483648; /* (2 ^ 31) */
	n[0] = a / b;
	for (i = 1; i < 32; i++)
	{
		b /= 2;
		n[i] = (a / b) % 2;
	}
	for (i = 0, sum = 0, indx = 0; i < 32; i++)
	{
		sum += n[i];
		if (sum || i == 31)
		{
			char c = '0' + n[i];

			write(1, &c, 1);
			indx++;
		}
	}
	return (indx);
}
