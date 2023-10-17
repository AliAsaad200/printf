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
	int digit_count = 0;
	int power_of_ten = 1;
	int char_count = 0;
	int value = no;
	int temp;
	int i;

	if (value < 0)
	{
	_putchar('-');
	char_count++;
	value = -value;
	}
	if (value == 0)
	{
	putchar('0');
	return (1);
	}
	temp = value;

	while (temp != 0)
	{
	temp /= 10;
	digit_count++;
	}
	for (i = 1; i <= digit_count - 1; i++)
	{
	power_of_ten *= 10;
	}
	for (i = 1; i <= digit_count; i++)
	{
	int digit = value / power_of_ten;

	putchar(digit + '0');
	char_count++;
	value -= digit * power_of_ten;
	power_of_ten /= 10;
	}
	return (char_count);
}
