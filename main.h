#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define PRINT_BUFFER_SIZE 1024
#define IDs flags

/* FLAGS */
#define FUN_SUB 1
#define FUN_ADD 2
#define FUN_NULL 4
#define FUN_HASH 8
#define FUN_EMPTY 16

/* SIZES */
#define SWEET_LNG 2
#define SWEET_SHRT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *indx,
va_list list, char buf_array[], int IDs, int width, int precision, int size);

/*PRINT FUNCTIONS*/
/*chars and strings*/
int printf_c(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size);
int printf_str(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size);
int printf_percentage(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size);
/*numbers*/
int printf_int(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size);
int printf_bin(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size);
int printf_unsign(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size);
int printf_oct(va_list types, char buf_array[],
	int IDs, int width, int precision, int size);
int printf_hex(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size);
int printf_HEX(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size);
int printf_hexa_help(va_list typs, char maping[],
char buf_array[], int IDs, char flaging, int width, int precision, int size);
/*non-printables*/
int printf_np(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size);
/*mem addresses*/
int printf_address(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size);
/*more specifiers*/
int g_IDs(const char *frmt, int *indx);
int g_width(const char *frmt, int *indx, va_list list);
int g_precision(const char *frmt, int *indx, va_list list);
int g_size(const char *frmt, int *indx);
/*reverse*/
int printf_rev(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size);

/*rot 13 emcryption*/
int printf_rot13encrypt(va_list typs, char buf_array[],
	int IDs, int width, int precision, int size);
/*Handling*/
int _write_char(char c, char buf_array[],
	int IDs, int width, int precision, int size);
int _write_int(int is_pos, int indx, char buf_array[],
	int IDs, int width, int precision, int size);
int _write_enum(int indx, char bffer[], int IDs, int width, int precision,
	int length, char paddings, char xtra);
int _write_address(char buf_array[], int indx, int length,
	int width, int IDs, char paddings, char xtra, int paddings_start);

int _write_uint(int is_neg, int indx, char buf_array[],
	int IDs, int width, int precision, int size);

/*helpers*/
int check_printable(char);
int ap_hex(char, char[], int);
int check_digit(char);

long int size_converter_int(long int num, int size);
long int size_converter_uint(unsigned long int num, int size);

#endif
