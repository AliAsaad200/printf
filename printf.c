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
 * format_arguments_output - Handle formatted output.
 * @format: The format string.
 * @argument_format: The variable arguments list.
 *
 * Return: The number of characters printed.
 */
int format_arguments_output(const char *format, va_list argument_format)
{
	int counting_down = 0;
	const char *c;
	int argument_numbs;
	char cc;

	for (c = format; *c != '\0'; ++c)
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
				process_string_argument(argument_format, &counting_down);
				break;
			case 'c':
				cc = va_arg(argument_format, int);
				_putchar(cc);
				counting_down++;
				break;
			case 'i':
			case 'd':
				argument_numbs = va_arg(argument_format, int);
				counting_down += print_correct_int(argument_numbs);
				break;
			default:
				process_unknown_specifier(format, &counting_down);
				break;
		}
	}
	}
	return (counting_down);
}
/**
 * process_string_argument - Handle formatted output.
 * @counting_down: The format string.
 * @argument_format: The variable arguments list.
 *
 * Return: The number of characters printed.
 */
void process_string_argument(va_list argument_format, int *counting_down)
{
	char *string_arg = va_arg(argument_format, char *);

	print_correct_string(string_arg);
	(*counting_down) += strlen(string_arg);
}
/**
 * process_unknown_specifier - Handle formatted output.
 * @format: The format string.
 * @counting_down: The variable arguments list.
 *
 * Return: The number of characters printed.
 */
void process_unknown_specifier(const char *format, int *counting_down)
{
	_putchar(*format);
	(*counting_down) += 1;
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
	va_list args;
	int result = 0;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	result = format_arguments_output(format, args);

	va_end(args);
	return (result);
}
