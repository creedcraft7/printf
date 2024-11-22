#include "ft_printf.h"

static int ft_parse_format(const char **s, va_list args, t_flag *params)
{
    char *temp;
	int	 res;
	
	res = 0;
    ft_init_flags(params);
    ft_struct((char **)s, params);
	if(**s =='c')
	{
		res = ft_char(va_arg(args, int), params->width, params->minus_flag);
		return (res);
	}
    temp = ft_format(*s, args, params);
    temp = ft_flags(temp, params);
    res += ft_width(temp, params);

    return res;
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_flag	params;
	int	result;

	if (!ft_overflow((char *)s))
		return -1;
	result = 0;
	va_start(args, s);
	while (*s)
	{
		if(*s == '%')
		{
			if (ft_order((char *)++s) && (*s && *s != '%'))
				result += ft_parse_format(&s, args, &params);
			else
				ft_putchar((result++, '%'));
		}
		else
			ft_putchar((result++, *s));
		s++;
	}
	va_end(args);
	return (result);
}

int main()
{
	// ft_printf("%++i\n", (int)-2147483648);
	 
	int result = ft_printf("%c %s - %p - %d - %i %u - %x - %X %%\n", '\0', NULL, (void *)0xdeadc0de, 0, (int)-2147483648, -1, -1, 200000000);
	printf("%d\n", result);

	result = printf("%c %s - %p - %d - %i %u - %x - %X %%\n", '\0', NULL, (void *)0xdeadc0de, 0, (int)-2147483648, -1, -1, 200000000);
	printf("%d\n", result);

	ft_printf("the password is %xhhh\n", 3735929054u);
	printf("%d\n", result);
	printf("the password is %xhhh\n", 3735929054u);
	result = printf("the password is %xhhh\n", 3735929054u);
	printf("%d\n", result);
	
}