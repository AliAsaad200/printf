#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"
/**
 * print_correct_string - Print a string.
 * @sttring_task: The string to print.
 */
void print_correct_string(const char *sttring_task)
{
	while (*sttring_task)
	{
		_putchar(*sttring_task);
		sttring_task++;
	}
}
/**
 * format_arguments_output0 - Handle formatted output.
 * @format: The format string.
 * @argument_format_output: The variable arguments list.
 *
 * Return: The number of characters printed.
 */
  int format_arguments_output(const char *format, va_list argument_format_output)
{
	int counting_down = 0;
	const char *c;
	for (c = format; *c; ++c)
	{
	if (*c != '%')
	{
	_putchar(*c);
	counting_down++;
	}
	else
	{
	c++;
	switch (*c)
	{
	case 's':
	{
	char *sttring_task = va_arg(argument_format_output, char *);

	print_correct_string(sttring_task);
	counting_down += strlen(sttring_task);
	break;
	}
	case 'c':
	{
	char c = va_arg(argument_format_output, int);

	_putchar(c);
	counting_down++;
	break;
	}
	case 'i': case 'd':
	{
	int argument_numbs = va_arg(argument_format_output, int);

	counting_down += print_correct_int(argument_numbs);
	break;
	}
	default:
	_putchar('%');
	_putchar(*c);
	counting_down += 2;
	break;
	}
	}
	}
	return (counting_down);
}
/**
 * _printf - Custom printf function.
 * @format: The format string.
 * @...: Variable arguments.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int result;
	va_list args;

	va_start(args, format);
	result = format_arguments_output(format, args);

	va_end(args);
	return (result);
}
