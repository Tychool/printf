#include "main.h"

/**
 * _abs - gets abs value
 * @n: value
 * Return: integer (Success)
 */
int _abs(int n)
{
	if (n < 0)
	{
		n = n * -1;
		return (n);
	}
	return (n);
}

/**
 * *_itoa - modify data type
 * @value: value
 * @base: convert base input
 * Return: reverse buffer char *
 */
char *_itoa(int value, int base)
{
	char buffer[1024];
	int n, i;

	if (base < 2 || base > 32)
		exit(1);

	n = _abs(value);

	i = 0;

	while (n)
	{
		int r = n % base;

		r = _abs(r);
		if (r >= 10)
			buffer[i] = 65 + (r - 10);
		else
			buffer[i] = 48 + r;
		i++;
		n = n / base;
	}

	if (i == 0)
	{
		buffer[i] = '0';
		i++;
	}

	if (value < 0 && base == 10)
	{
		buffer[i] = '-';
		i++;
	}

	buffer[i] = '\0';

	return (_reverse(buffer, i));
}

/**
 * *_utoa - modify data type
 * @value: value
 * @base: convert base input
 * Return: reverse buffer char *
 */

char *_utoa(unsigned int value, unsigned int base)
{
	char buffer[1024];
	unsigned int i, r;

	if (base < 2 || base > 32)
		exit(1);

	i = 0;
	while (value)
	{
		r = value % base;

		if (r >= 10)
			buffer[i] = 65 + (r - 10);
		else
			buffer[i] = 48 + r;

		i++;
		value = value / base;
	}

	if (i == 0)
	{
		buffer[i] = '0';
		i++;
	}

	buffer[i] = '\0';

	return (_reverse(buffer, i));
}

/**
 * *_lcutoa - modifies data
 * @value: value
 * @base: convert base input
 * Return: reverse buffer char *
 */

char *_lcutoa(unsigned int value, unsigned int base)
{
	char buffer[1024];
	unsigned int i, r;

	if (base < 2 || base > 32)
		exit(1);

	i = 0;
	while (value)
	{
		r = value % base;

		if (r >= 10)
		{
			buffer[i] = 65 + (r - 10);
			if (buffer[i] >= 65 && buffer[i] <= 90)
				buffer[i] += 32;
		}
		else
			buffer[i] = 48 + r;

		i++;
		value = value / base;
	}

	if (i == 0)
	{
		buffer[i] = '0';
		i++;
	}

	buffer[i] = '\0';

	return (_reverse(buffer, i));
}
