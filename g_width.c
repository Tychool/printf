#include "main.h"

/**
 * g_width - width
 * @frmt: print format
 * @i: buffer
 * @list: args
 *
 * Return: result
 */
int g_width(const char *format, int *i, va_list list)
{
	int cue;
	int wid = 0;

	for (cue = *i + 1; frmt[cue] != '\0'; cue++)
	{q
		if (check_digit(frmt[cue]))
		{
			wid *= 10;
			wid += frmt[cue] - '0';
		}
		else if (frmt[cue] == '*')
		{
			cue++;
			wid = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cue - 1;

	return (wid);
}
