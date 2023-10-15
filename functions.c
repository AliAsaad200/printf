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
	int char_count = 0;
	char sign = (no < 0) ? '-' : '+';
	char buffer[21]; 
	int index;
	int i;

	index = 0;
	_putchar(sign);
	char_count++;
	no = (no < 0) ? -no : no;
	if (no == 0)
	{
	buffer[index++] = '0';
	}
	else
	{
	while (no > 0)
	{
	buffer[index++] = '0' + no % 10;
	no /= 10;
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
