#include "main.h"

void print_buf(char buf_array[], int *buf_ind);

/**
 * _printf - Printf function
 * @format: print formatting
 * Return: print
 */
int _printf(const char *frmt, ...)
{
	int i, p = 0, p_chars = 0;
	int IDs, width, precision, size, buf_ind = 0;
	va_list list;
	char buf_array[PRINT_BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buf_array[buf_ind++] = format[i];
			if (buf_ind == PRINT_BUFFER_SIZE)
				print_buf(buf_array, &buf_ind);i
			p_chars++;
		}
		else
		{
			print_buf(buf_array, &buf_ind);
			IDs = g_IDs(format, &i);
			width = g_width(format, &i, list);
			precision = g_precision(format, &i, list);
			size = g_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buf_array, IDs, width, precision, size);
			if (printed == -1)
				return (-1);
			p_chars += p;
		}
	}

	print_buf(buf_array, &buf_ind);

	va_end(list);

	return (p_chars);
}

/**
 * printf_buf - Print buffer content
 * @buf_array: char array
 * @buf_ind: infex
 */
void printf_buf(char buf_array[], int *buf_ind)
{
	if (*buf_ind > 0)
		write(1, &buf_array[0], *buf_ind);

	*buf_ind = 0;
}
