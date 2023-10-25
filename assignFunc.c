#include "main.h"

/**
 * _assignFunc - assign functuon and count them
 * @buffer: buffer array
 * @count: index
 * @value: value of current element in the index
 * Return: result (int)
 */
int _assignFunc(char *buffer, int count, char *value)
{
	int i = 0;

	while (value[i])
	{
		buffer[i] = value[i];
		count++;
		i++;
	}
	return (count);

}

/**
 * _reverse_assignFunc - reverse function assigned
 * @buffer: buffer array
 * @count: index counter
 * @value: value in the index
 * return: int
 */
int _reverse_assignFunc(char *buffer, int count, char *value)
{
	int len = _slen(value);
	int i;

	for (i = 0; i <= len; i++)
	{
		buffer[i] = value[len - i];
		count++;
	}
	return (count);
}
