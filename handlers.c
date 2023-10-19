#include "main.h"
/**
 * handle_print - print according to type
 * @fmt: print format
 * @list: arg
 * @ind: index
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *indx, va_list list, char buf_array[],
	int IDs, int width, int precision, int size)
{
	int i, x_len = 0, p_chars = -1;
	fmt_t fmt_typs[] = {
		{'c', printf_char}, {'s', printf_str}, {'%', printf_percentage},
		{'i', printf_int}, {'d', printf_int}, {'b', printf_bin},
		{'u', printf_unsign}, {'o', printf_oct}, {'x', printf_hex},
		{'X', printf_HEX}, {'p', printf_address}, {'S', printf_np},
		{'r', printf_rev}, {'R', printf_rot13encryt}, {'\0', NULL}
	};
	for (i = 0; fmt_typs[i].fmt != '\0'; i++)
		if (fmt[*indx] == fmt_typs[i].fmt)
			return (fmt_typs[i].fn(list, buf_array, IDs, width, precision, size));

	if (fmt_typs[i].fmt == '\0')
	{
		if (fmt[*indx] == '\0')
			return (-1);
		x_len += write(1, "%%", 1);
		if (fmt[*indx - 1] == ' ')
			x_len += write(1, " ", 1);
		else if (width)
		{
			--(*indx);
			while (fmt[*indx] != ' ' && fmt[*indx] != '%')
				--(*indx);
			if (fmt[*indx] == ' ')
				--(*indx);
			return (1);
		}
		x_len += write(1, &fmt[*indx], 1);
		return (x_len);
	}
	return (p_chars);
}
