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
int print_correct_int(int no)
{
	int num = no;
	int i = 0;

	if (no < 0)
	{
	_putchar('-');
	num = -num;
	i++;
	}

	if (num == 0)
	{
	_putchar('0');
	i++;
	}
	else
	{
	int exp = 1;
	int temp = num;

	while (temp > 9)
	{
	exp *= 10;
	temp /= 10;
	}
	while (exp > 0)
	{
	int digit = num / exp;

	_putchar(digit + '0');
	num -= digit * exp;
	exp /= 10;
	i++;
	}
	}
	return (i);
}
