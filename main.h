#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/* Buffer Defs */
/*#define UNUSED(x) (void)(x)*/
#define BUFFER_SIZE 1024

/* Structs*/
/**
 * struct ptr - struct for parameters and functoons
 * @c: specifiers
 * @f: functions
*/
typedef struct ptr
{
	char *c;
	int (*f)(char *, int, va_list);
} ptr_ch;

/*PROTOTYOES*/
int _printf(const char *format, ...);
int (*param_check(char specifier))(char *, int, va_list);

/*numbers */
char *_lcutoa(unsigned int value, unsigned int var);
int _abs(int n);
char *_utoa(unsigned int value, unsigned int var);
char *_itoa(int value, int var);

/* Assign buffers and count */
int _reverse_assignFunc(char *buffer, int count, char *value);
int _assignFunc(char *buffer, int count, char *value);

/* Parameters */
int spc_d(char *buffer, int count, va_list value);
int spc_i(char *buffer, int count, va_list value);
int spc_u(char *buffer, int count, va_list value);
int spc_o(char *buffer, int count, va_list value);
int spc_x(char *buffer, int count, va_list value);
int spc_X(char *buffer, int count, va_list value);
int spc_c(char *buffer, int count, va_list value);
int spc_s(char *buffer, int count, va_list value);
int spc_ptg(char *buffer, int count, va_list value);
int spc_b(char *buffer, int count, va_list value);
int spc_r(char *buffer, int count, va_list value);
int spc_R(char *buffer, int count, va_list value);

/* String funcs*/
int _slen(char *s);
char *_rot13(char *str);
char *_rev(char *s, int n);
void _rev_ptr(char *str);
void _strcpy(char *dest, char *src);

#endif
