#include "ft_printf.h"

int ft_char(int c, int width, bool minus)
{
	int count = 1;
	if(!minus)
	{
		while(width > 1)
		{
			ft_putchar(' ');
			width--;
			count++;
		}
		ft_putchar(c);
	}
	else
	{
		ft_putchar(c);
		while(width > 1)
		{
			ft_putchar(' ');
			width--;
			count++;
		}
	}
	return count;
}