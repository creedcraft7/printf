#include "ft_printf.h"

// char *ft_char(int c)
// {
//     char ptr[2];
//     if (c == 0)
//         return (NULL);
//     else
//     	ptr[0] = c;
//     ptr[1] = '\0';
//     return ft_strdup(ptr);
// }

int ft_char(int c, int width, bool minus)
{
	int result = 1; 

	// width--;  
	if(!minus)
	{
		while (width > 1)
		{
			ft_putchar(' ');
			width--;
			result++;
		}
		ft_putchar(c);
	}
    else
	{
		ft_putchar(c);
		while (width > 1)
		{
			ft_putchar(' ');
			width--;
			result++;
		}
	}
	return result;
}