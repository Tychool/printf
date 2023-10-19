#include "main.h"

/**
 * g_precision - precision
 * @frmt: print fkrmat
 * @i: buffrr print
 * @list: args
 * Return: result
 */
int g_precision(const char *frmt, int *i, va_list list)
{
	int cue = *i + 1;
	int pre = -1;

	if (frmt[cue] != '.')
		return (pre);

	pre = 0;

	for (cue += 1; frmt[cue] != '\0'; cue++)
	{
		if (check_digit(formt[cue]))
		{
			pre *= 10;
			pre+= frmt[cue] - '0';
		}
		else if (frmt[cue] == '*')
		{
			cue++;
			pre = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cue - 1;

	return (pre);
}
