#include "ft_printf.h"

int ft_overflow(char *s)
{
    while (*s)
    {
        if (*s == '%' && ft_order(++s))
        {
            while (*s && (!ft_isdigit(*s) || *s == '0'))
                s++; 
            if (*s && ft_isdigit(*s) && ft_atoi(&s) > 2147483647)
                return 0;
            if (*s && *s == '.' && ft_isdigit(*(++s + 1)) && ft_atoi(&s) > 2147483647)
				return 0;
        }
        s++; 
    }
    return 1;
}

// int main()
// {
// 	printf("the return is: %s\n", ft_check_overflow("hello %#+++- -000++++39085679503454.4512424165487d\n") ? "pass" : "block");
// }