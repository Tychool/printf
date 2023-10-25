#include "main.h"
#include <stdlib.h>

/**
 * _printf - hand made printf function
 * @format: string formating
 * Return: result (int)
 */
int _printf(const char *format, ...)
{
	char *buffer;
	int i = 0, count = 0;
	va_list arg_value;
	int (*spc)(char *, int, va_list);

	buffer = malloc(4000);
	if ((!format || !buffer) || (format[0] == '%' && format[1] == '\0'))
	{
		free(buffer);
		exit(1);
	}

	va_start(arg_value, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
			buffer[count] = format[i];
			count++;
		}
		else
		{
			spc = param_check(format[i + 1]);
			if (!func)
			{
				buffer[count] = '%';
				i++;
				count++;
				continue;
			}
			count = func(&buffer[count], count, arg_value);
			i++;
		}
		i++;
	}
	write(1, buffer, count);
	va_end(arg_value);
	free(buffer);
	return (count);
}
