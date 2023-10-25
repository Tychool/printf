#include "main.h"

/**
 * *param_check - check all param input
 * @specifier: string character
 * Return: int
 */

int (*para_check(char specifier))(char *, int, va_list)
{
	int j = 0;

	ptr_ch arg_ptr[] = {
		{"d", spc_d},
		{"i", spc_i},
		{"u", spc_u},
		{"o", spc_o},
		{"x", spc_x},
		{"X", spc_X},
		{"c", spc_c},
		{"s", spc_s},
		{"%", spc_ptg},
		{"b", spc_b},
		{"r", spc_r},
		{"R", spc_R},
		{NULL, NULL},
	};

	while (arg_ptr[j].c)
	{
		if (specifier == *arg_ptr[j].c)
			break;
		j++;
	}

	return (arg_ptr[j].f);
}

