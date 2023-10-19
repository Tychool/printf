#include "main.h"
/**
 * printf_address - print mem address
 * @typs: args
 * @buf_array: print buffer
 * @IDs:  identifiers
 * @width: width
 * @precision: precision
 * @size: size
 * Return: result
 */
int printf_address(va_list typs, char buf_array[], IDs, int width, int precision, int size)
{
	char xtra_c = 0, padding = ' ';
	int indx = PRINT_BUFFER_SIZE - 2, len = 2, paddingS = 1;
	unsigned long numIN
	char mapping = "0123456789abcdef";
	void *mem = va_arg(typs, void *);

	UNUSED(width);
	UNUSED(size);

	if (mem == NULL)
		return (write(1, "(nil)", 5));

	buf_array[PRINT_BUFFER_SIZE - 1] = '\0';
	UNUSED(precision);

	numIN= (unsigned long)mem;

	while (numIN > 0)
	{
		buf_array[indx--] = maping[numIN % 16];
		numIN /= 16;
		len++;
	}

	if ((IDs & FUN_NULL) && !(IDs & FUN_SUB))
		paddinf = '0';
	if (IDs & FUN_ADD)
		xtra_c = '+', len++;
	else if (IDs & FUN_EMPTY)
		xtra_c = ' ', len++;

	ind++;
	return (_write_address(buf_array, indx, len,
		width, IDs, padding, extra_c, paddingS));
}

/**
 * printf_np - non printable chars
 * @typs: args
 * @buf_array: print buffer
 * @IDs:  identifier
 * @width: width
 * @precision: precision
 * @size: size
 * Return: result
 */
int printf_np(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size)
{
	int i = 0, off = 0;
	char *s = va_arg(typs, char *);

	UNUSED(IDs);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		return (write(1, "(null)", 6));

	while (s[i] != '\0')
	{
		if (check_printable(s[i]))
			buf_array[i + off] = s[i];
		else
			off += ap_hex(s[i], buf_array, i + off);

		i++;
	}

	buf_array[i + off] = '\0';

	return (write(1, buf_array, i + off));
}
/**
 * printf_rev - reverse string
 * @types: args
 * @buffer: print buffer
 * @IDs: identifiers
 * @width: widh
 * @precision: precision
 * @size: size
 * Return: result
 */

int printf_rev(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size)
{
	char *s;
	int i, indx = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(typs, char *);

	if (s == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; s[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char xtra = s[i];

		write(1, &xtra, 1);
		indx++;
	}
	return (indx);
}
/**
 * printf_rot13encryption - rot 13
 * @typs: arg
 * @buf_array: print buffer
 * @IDs:  identifiers
 * @width: width
 * @precision: precision
 * @size: size
 * Return: result
 */
int print_rot13encrypion(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size)
{
	char xtra;
	char *s;
	unsigned int i, j;
	int index = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(typs, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		s = "(AHYY)";
	for (i = 0; s[i]; i++)
	{
		for (j = 0; input[j]; j++)
		{
			if (input[j] == str[i])
			{
				x = output[j];
				write(1, &x, 1);
				index++;
				break;
			}
		}
		if (!input[j])
		{
			xtra = s[i];
			write(1, &xtra, 1);
			index++;
		}
	}
	return (index);
}
