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

	while (str[i])
	{
		write_char(str[i]);
		i++;
	}

	return (i);
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
		}
		else
			printed_chars += write_char(*format);

		format++;
	}

	va_end(args);

	return (printed_chars);
}
