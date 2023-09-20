#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * write_char - Helper function to write a single character
 * @c: Character to write
 *
 * Return: Number of characters written
 */
int write_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * write_string - Helper function to write a string
 * @str: String to write
 *
 * Return: Number of characters written
 */
int write_string(char *str)
{
	int i = 0;
	int printed_chars = 0;

	while (str[i])
	{
		printed_chars += write_char(str[i]);
		i++;
	}

	return (printed_chars);
}

/**
 * write_binary - Converts unsigned integer to binary and writes it to stdout
 * @num: The unsigned integer to convert to binary
 *
 * Return: The number of characters written
 */
int write_binary(unsigned int num)
{
	int binary[32];
	int i = 0;
	int j;
	int printed_chars = 0;

	if (num == 0)
		return (write_char('0'));

	while (num > 0)
	{
		binary[i] = num % 2;
		num = num / 2;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		printed_chars += write_char(binary[j] + '0');
	}

	return (printed_chars);
}

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
				printed_chars += write_char(va_arg(args, int));
			else if (*format == 's')
				printed_chars += write_string(va_arg(args, char *));
			else if (*format == '%')
				printed_chars += write_char('%');
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				char num_str[12];

				sprintf(num_str, "%d", num);
				printed_chars += write_string(num_str);
			}
			else if (*format == 'b')
			{
				unsigned int num = va_arg(args, unsigned int);

				printed_chars += write_binary(num);
			}
		}
		else
			printed_chars += write_char(*format);

		format++;
	}

	va_end(args);
	return (printed_chars);
}
