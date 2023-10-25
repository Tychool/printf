#include "main.h"

/**
 * _slen - string lenght
 * @s: string
 * Return: result
 */
int _slen(char *s)
{
	int count = 0;

	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

/**
 * *_rev - reverse array content
 * @s: array
 * @n: number of elements
 * Return: result
 */
char *_rev(char *s, int n)
{
	int i, aux;

	n--;

	for (i = 0; i <= n; i++, n--)
	{
		aux = s[i];
		s[i] = s[n];
		s[n] = aux;
	}

	return (s);
}

/**
 * *_rot13 - rot 13 encrypt
 * @str: string
 * Return: rot 13 string
 */

char *_rot13(char *str)
{
	int i, j;
	char chs[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

		for (i = 0; str[i]; i++)
		{
			for (j = 0; chs[j]; j++)
			{
				if (str[i] == chs[j])
				{
					str[i] = rot[j];
					break;
				}
			}
		}

		return (str);
}

/**
 * *_scpy - copy string
 * @dest:  to
 * @src: from
 * Return: array result
 */

void _scpy(char *dest, char *src)
{
	int len = _slen(src);
	int i;

	for (i = 0; i <= len; i++)
	{
		dest[i] = src[i];
	}
}

/**
 * _ptrRev - reverse pointer
 * @str: strinf ptr
 */

void _ptrRev(char *str)
{
	int i, aux;
	int len = _slen(str) - 1;

	for (i = 0; i <= len; i++, len--)
	{
		aux = str[i];
		str[i] = str[len];
		str[len] = aux;
	}
}
