#include "main.h"

/**
 * _absolute - compute absolute  value
 * @n: inpute
 * Return: ABS
 */
int _absolute(int n)
{
	if (n < 0)
	{
		n = n * -1;
		return (n);
	}
	return (n);
}

/**
 * *_int - format data type
 * @value: value
 * @var: base input
 * Return: result
 */
char *_int(int value, int var)
{
	char buf[1024];
	int n, i;

	if (var < 2 || var > 32)
		exit(1);

	n = _absolute(value);

	i = 0;

	while (n)
	{
		int r = n % var;

		r = _absolute(r);
		if (r >= 10)
			buf[i] = 65 + (r - 10);
		else
			buf[i] = 48 + r;
		i++;
		n = n / var;
	}

	if (i == 0)
	{
		buf[i] = '0';
		i++;
	}

	if (value < 0 && var == 10)
	{
		buf[i] = '-';
		i++;
	}

	buf[i] = '\0';

	return (_funcRev(buf, i));
}

/**
 * *_uint - format data type
 * @value: value
 * @var: base input
 * Return: result
 */

char *_uint(unsigned int value, unsigned int var)
{
	char buf[1024];
	unsigned int i, r;

	if (var < 2 || var > 32)
		exit(1);

	i = 0;
	while (value)
	{
		r = value % var;

		if (r >= 10)
			buf[i] = 65 + (r - 10);
		else
			buf[i] = 48 + r;

		i++;
		value = value / var;
	}

	if (i == 0)
	{
		buf[i] = '0';
		i++;
	}

	buf[i] = '\0';

	return (_funcRev(buf, i));
}

/**
 * *_hex - format data
 * @value: value
 * @var: base input
 * Return: result
 */

char *_hex(unsigned int value, unsigned int var)
{
	char buf[1024];
	unsigned int i, r;

	if (var < 2 || var > 32)
		exit(1);

	i = 0;
	while (value)
	{
		r = value % var;

		if (r >= 10)
		{
			buf[i] = 65 + (r - 10);
			if (buf[i] >= 65 && buf[i] <= 90)
				buf[i] += 32;
		}
		else
			buf[i] = 48 + r;

		i++;
		value = value / var;
	}

	if (i == 0)
	{
		buf[i] = '0';
		i++;
	}

	buf[i] = '\0';

	return (_funcRev(buf, i));
}
