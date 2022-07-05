#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

void	pstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	putstr(char *str)
{
	int	i;

	i = 0;
	if( str == NULL)
	{
		pstr("(null)");
		return(6);
	}
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return(i);
}

int	putnbr(int n)
{
	int len;
	char* num;

	len = 0;
	num = ft_itoa(n);
	len = putstr(num);
	return(len);
}

int	putpercent(void)
{
	write(1, "%", 1);
	return(1);
}