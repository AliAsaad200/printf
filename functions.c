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
	int i = 0;
	int num = no;
	int digit;

	if (num < 0)
	{
	putchar('-');
	num = -num;
	i++;
	}
	while (num > 0)
	{
	digit = num % 10;
	putchar(digit + '0');
	num = num / 10;
	i++;
	}
	return (i);
}
