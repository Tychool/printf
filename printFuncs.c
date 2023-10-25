#include "main.h"

/**
 * spc_d - decimal to buffer
 * @buffer: array input
 * @count: index
 * @value: list element value
 * Return: result
 */
int spc_d(char *buffer, int count, va_list value)
{
	int var = 10;
	char *str = _int(va_arg(value, int), var);

	return (_assignFunc(buffer, count, str));
}

/**
 * spc_i - integer to buffer
 * @buffer: array  input
 * @count: index
 * @value: list element value
 * Return: result
 */
int spc_i(char *buffer, int count, va_list value)
{
	int var = 10;
	char *str = _int(va_arg(value, int), var);

	return (_assignFunc(buffer, count, str));
}

/**
 * spc_u - unsigned int to buffer
 * @buffer: array input
 * @count: index
 * @value: index value
 * Return: integer (Success)
 */
int spc_u(char *buffer, int count, va_list value)
{
	int var = 10;
	unsigned int numIn;
	char *str;

	numIn = va_arg(value, unsigned int);
	str = _uint(numIn, var);

	return (_assignFunc(buffer, count, str));
}

/**
 * spc_o - octadecimal to buffer
 * @buff: array input
 * @count: index
 * @value: list element value
 * Return: result
 */
int spc_o(char *buffer, int count, va_list value)
{
	int var = 8;
	unsigned int numIn;
	char *str;

	numIn = va_arg(value, unsigned int);
	str = _uint(numIn, var);

	return (_assignFunc(buffer, count, str));
}

/**
 * spc_x - hexadcimal(lowercase) to buffer
 * @buffer: array input 
 * @count: index
 * @value: list element value
 * Return: result
 */
int spc_x(char *buffer, int count, va_list value)
{
	int var = 16;
	unsigned int numIn;
	char *str;

	numIn = va_arg(value, unsigned int);
	str = _hex(numIn, var);

	return (_assignFunc(buffer, count, str));
}

/**
 * spc_X - HEXADECIMAL to buffer
 * @buffer: array input
 * @count: index
 * @value: list elementvalue
 * Return: result
 */
int spc_X(char *buffer, int count, va_list value)
{
        int var = 16;
        unsigned int numIn;
        char *str;

        numIn = va_arg(value, unsigned int);
        str = _uint(numIn, var);
        
        return (_assignFunc(buffer, count, str));
}

/**
 * spc_c - char to buffer
 * @buffer: array input
 * @count: index
 * @value: list element value
 * Return: result
 */
int spc_c(char *buffer, int count, va_list value)
{
	int ch = va_arg(value, int);

	if (!ch)
	{
		write(1, "\0\0", 2);
		free(buffer);
		exit(0);
	
	}
	buffer[0] = ch;
	return (count + 1);
}

/**
 * spc_s - string to buffer
 * @buffer: array input
 * @count: index
 * @value: list element value
 * Return: result
 */
int spc_s(char *buffer, int count, va_list value)
{
	char *str = va_arg(value, char *);

	if(!str)
		str = "(null)";
	return (_assignFunc(buffer, count, str));
}

/**
 * spc_ptg - percentage sign, '%' to buffer
 * @buffer: array input
 * @count: index
 * @value: list element value
 * Return: result
 */
int spc_ptg(char *buffer, int count, va_list value)
{
	(void)value;
	buffer[0] = '%';
	return (count + 1);
}

/**
 * spc_b - bin to buffer
 * @buff: string variable input
 * @count: counts index
 * @value: index value
 * Return: result
 */
int spc_b(char *buffer, int count, va_list value)
{
	int var = 2;
	unsigned int numIn;
	char *str;

	numIn = va_arg(value, unsigned int);
	str = _uint(numIn, var);

	return (_assignFunc(buffer, count, str));
}

/**
 * spc_r - reversed stringto buff
 * @buffer: arrayinput
 * @count: index
 * @value: list element index value
 * Return: result
 */
int spc_r(char *buffer, int count, va_list value)
{
	char *str = va_arg(value, char *);
	char *_strRev = malloc(_slen(str) + 1);

	_scpy(_strRev, str);
	_ptrRev(_strRev);

	count = _assignFunc(buffer, count, _strRev);
	free(_strRev);

	return (count);
}

/**
 * spc_R - rot13 encrypt str to buff
 * @buffer: array input
 * @count: index
 * @value: list elementindex value
 * Return: result
 */
int spc_R(char *buffer, int count, va_list value)
{
        char *str = va_arg(value, char *);
        char *Rot_str = malloc(_slen(str) + 1);

        _scpy(Rot_str, str);
        _ptrRev(Rot_str);

        count = _assgnFunc(buffer, count, Rot_str);
        free(Rot_str);

        return (count);
}
