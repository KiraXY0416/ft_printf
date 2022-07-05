#include <stdarg.h>
#include <unistd.h>

int	putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int putlength;

	putlength = 0;
	if (format == 'c')
		putlength += putchar(va_arg(args, int));
	else if (format == 's')
		putlength += putstr(va_arg(args, const char*));
	else if (format == 'p')
		putlength += putptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		putlength += putnbr(va_arg(args, int));
	else if (format == 'u')
		putlength += putunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		putlength += puthex(va_arg(args, unsigned int), format);
	else if (format == '%')
		putlength += putpercent();
	return(putlength);
}

int	ft_printf(const char *str, ...)
{
	int	i
	va_list	args;
	int	putlength;

	i = 0;
	putlength = 0;
	va_start(args, str);
	while(str[i])
	{
		if(str[i] == %)
		{
			putlength += ft_formats(args, str[i + 1]);
			i++
		}
		else
			putlength += putchar(str[i]);
		i++;
	}
	va_end(args);
	return(putlength);
}