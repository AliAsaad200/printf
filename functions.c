#include <stdio.h>
#include <stdarg.h>
#include <string.h>
/**
 * print_correct_string - Print a string.
 * @sttring_task: The string to print.
 */
void print_correct_string(const char *sttring_task)
{
	while (*sttring_task)
	{
	print_correct_char(*sttring_task);
	sttring_task++;
	}
}
/**
 * print_correct_char - Print a single character.
 * @c: The character to print.
 */
void print_correct_char(char c)
{
	_putchar(c);
}
/**
 * print_correct_int - Print a num.
 * @no: The character to print.
 *
 * Return: The number of characters printed.
 */
int print_correct_int(int no)
{
	int char_count = 0;
	char sign = (num < 0) ? '-' : '+';

	_putchar(sign);
	char_count++;

	num = (num < 0) ? -num : num;

	char buffer[21];
	int index = 0;
	int i;

	if (num == 0)
	{
	buffer[index++] = '0';
	}
	else
	{
	while (num > 0)
	{
	buffer[index++] = '0' + num % 10;
	num /= 10;
	}
	}
	buffer[index] = '\0';
	for (i = index - 1; i >= 0; i--)
	{
	_putchar(buffer[i]);
	char_count++;
	}
	return (char_count);
}
/**
 * format_arguments_output - Handle formatted output.
 * @format: The format string.
 * @argument_format_output: The variable arguments list.
 *
 * Return: The number of characters printed.
 */
int format_arguments_output(const char *format, va_list argument_format_output)
{
	int counting_down = 0;

	for (const char *c = format; *c; ++c)
	{
	if (*c != '%')
	{
	print_correct_char(*c);
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

	print_correct_char(c);
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
	print_correct_char('%');
	print_correct_char(*c);
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
	va_list args;

	va_start(args, format);
	int result = format_arguments_output(format, args);

	va_end(args);
	return (result);
}
