#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string
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
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				printed_chars++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				int i = 0;

				while (str[i])
				{
					write(1, &str[i], 1);
					i++;
					printed_chars++;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				printed_chars++;
			}
		}
		else
		{
			write(1, format, 1);
			printed_chars++;
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}
