#include "main.h"

/**
 * _putchar - write character to stdandard output
 * @c: char
 * Return: 1 (good), -1 (Error),
 * and error set
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
