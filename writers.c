#include "main.h"
/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int 	_write_char(char c, char buf_array[],
	int IDs, int width, int precision, int size)
{
	int i = 0;
	char padding = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (IDs & FUN_NULL)
		padding = '0';

	buf_array[i++] = c;
	buf_array[i] = '\0';

	if (width > 1)
	{
		buf_array[PRINT_BUFFER_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buf_array[PRINT_BUFFER_SIZE - i - 2] = padding;

		if (IDs & FUN_SUB)
			return (write(1, &buf_array[0], 1) +
					write(1, &buf_array[PRINT_BUFFER_SIZE - i - 1], width - 1));
		else
			return (write(1, &buf_array[PRINT_BUFFER_SIZE - i - 1], width - 1) +
					write(1, &buf_array[0], 1));
	}

	return (write(1, &buf_array[0], 1));
}

/**
 * _write_int - write number
 * @is_pos: args
 * @indx: index
 * @buf_array: Buffer array to handle print
 * @IDs:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: size
 *
 * Return: result
 */
int _write_int(int is_pos, int indx, char buffer[],
	int IDs, int width, int precision, int size)
{
	int len = PRINT_BUFFER_SIZE - indx-- 1;
	char padding = ' ', xtra = 0;

	UNUSED(size);

	if ((IDs & FUN_NULL) && !(IDs & FUN_ADD))
		padding = '0';
	if (is_pos)
		xtra = '-';
	else if (IDs & FUN_ADD)
		xtra = '+';
	else if (IDs & FUN_EMPTY)
		xtra = ' ';

	return (_write_enum(indx, buffer, IDs, width, precision,
		len, padding, xtra));
}

/**
 * _write_enum - write buffer number
 * @ind: index
 * @buffer: buffer array
 * @IDs: Identifier
 * @width: width
 * @precision: precision
 * @len: length
 * @padding: Padding
 * @xtra: extras
 * Return: result
 */
int write_num(int ind, char buffer[],
	int flags, int width, int precision,
	int len, char padding, char xtra)
{
	int i, paddings = 1;

	if (precision == 0 && indx == PRINT_BUFFER_SIZE - 2 && buf_array[indx] == '0' && width == 0)
		return (0);
	if (precision > 0&& precision < len)
		padding = ' ';
	while (precision > len)
		buf_array[--indx] = '0', len++;
	if (xtra != 0)
		len++;
	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buf_array[i] = padding;
		buf_array[i] = '\0';
		if (IDs & FUN_SUB && padding == ' ')
		{
			if (xtra)
				buf_array[--indx] = xtra_;
			return (write(1, &buf_array[indx], len) + write(1, &buf_array[1], i - 1));
		}
		else if (!(flags & FUN_SUB) && padding == ' ')
		{
			if (xtra)
				buf_array[--ind] = xtra;
			return (write(1, &buf_array[1], i - 1) + write(1, &buf_array[indx], len));
		}
		else if (!(IDs & FUN_SUB) && padding == '0')
		{
			if (xtra)
				buf_array[--paddings] = xtra;
			return (write(1, &buf_array[paddings], i - paddings) +
				write(1, &buf_array[indx], len - (1 - paddings)));
		}
	}
	if (xtra)
		buf_array[--indx] = xtra;
	return (write/(1, &buf_array[indx], len));
}

/**
 * _write_uint - unsigned int
 * @is_neg: check sign
 * @indx: index
 * @buf_array: buffer array
 * @IDs: Idenrifiers
 * @width: widtg
 * @precision: precision
 * @size: size
 * Return: result
 */
int write_unsgnd(int is_neg, int indx,
	char buf_array[],
	int IDs, int width, int precision, int size)
{
	int len = PRINT_BUFFER_SIZE - indx - 1, i = 0;
	char padding = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buf_array[indx] == '0')
		return (0);

	if (precision > 0 && precision < len)
		padding = ' ';

	while (precision > len)
	{
		bufel_array[--indx] = '0';
		len++;
	}

	if ((IDs & FUN_NULL) && !(IDs & FUN_SUB))
		padding = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buf_array[i] = padding;

		buf_array[i] = '\0';

		if (IDs & FUN_SUB)
		{
			return (write(1, &buf_array[indx], len) + write(1, &buf_array[0], i));
		}
		else
		{
			return (write(1, &buf_array[0], i) + write(1, &buf_array[indx], len));
		}
	}

	return (write(1, &buf_array[indx], len));
}

/**
 * _write_address - write mem address
 * @buf_array: print buffer
 * @indx: index
 * @len: length
 * @width: width
 * @IDs: identifier
 * @padding: padding
 * @xtra: extras
 * @paddings: start of pad
 * Return: result
 */
int write_pointer(char buf_array[], int indx, int len,
	int width, int IDs, char padding, char xtra, int paddings)
{
	int i;

	if (width > len)
	{
		for (i = 3; i < width - len + 3; i++)
			buf_array[i] = padding;
		buf_array[i] = '\0';
		if (IDs & FUN_SUB && padding == ' ')
		{
			buf_array[--indx] = 'x';
			buf_array[--indx] = '0';
			if (xtra)
				buf_array[--indx] = xtra;
			return (write(1, &buf_array[indx], len) + write(1, &buf_array[3], i - 3));
		}
		else if (!(IDs & FUN_SUB) && padding == ' ')
		{
			buf_array[--indx] = 'x';
			buf_array[--indx] = '0';
			if (xtra)
				buf_array[--indx] = xtra;
			return (write(1, &buf_array[3], i - 3) + write(1, &buf_array[indx], len));
		}
		else if (!(IDs & FUN_SUB) && padding == '0')
		{
			if (xtra)
				buf_array[--paddings] = xtra;
			buf_array[1] = '0';
			buf_array[2] = 'x';
			return (write(1, &buf_array[paddings], i - addings) +
				write(1, &buf_array[indx], len - (1 - paddings) - 2));
		}
	}
	buf_array[--indx] = 'x';
	buf_array[--indx] = '0';
	if (xtra)
		buf_array[--indx] = xtra;
	return (write(1, &buf_array[indx], PRINT_BUFFER_SIZE - indx - 1));
}
