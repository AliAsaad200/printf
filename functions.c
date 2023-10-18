#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * print_correct_int - Print a num.
 * @no: The character to print.
 *
 * Return: The number of characters printed.
 */
int print_correct_int(va_list args)
{
	int length = 0, power_of_ten = 1, i, digit, result, char_count = 0, n;

	result = va_arg(args, int);
	if (result < 0)
	{
	_putchar('-');
	char_count++;
	}
	if (result == 0)
	{
	_putchar('0');
	return (1);
	}
	n = result;
	length = 0;
	while (n != 0)
	{
	n /= 10;
	length++;
	}
	for (i = 1; i <= length - 1; i++)
	{
	power_of_ten *= 10;
	}
	for (i = 1; i <= length; i++)
	{
	digit = result / power_of_ten;
	if (result < 0)
	{
	_putchar((-1 * digit) + 48);
	}
	else
	{
	_putchar(digit + '0');
	}
	char_count++;
	result -= digit * power_of_ten;
	power_of_ten /= 10;
	}
	return (char_count);
}
