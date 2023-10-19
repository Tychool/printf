#include "main.h"

/**
 * g_size - size
 * @frmt: print formst
 * @i: arg
 * Return: result
 */
int g_size(const char *frmt, int *i)
{
	int cue = *i + 1;
	int sz = 0;

	if (frmt[cue] == 'l')
		sz = SWEET_LNG;
	else if (frmt[cue] == 'h')
		sz = SWEET_SHRT;

	if (sz == 0)
		*i = cue - 1;
	else
		*i = cue;

	return (sz);
}
