#include "libft.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s != 0)
	{	
		while (s[i])
		{	
			write(1, &s[i], 1);
			i++;
		}
	}
}