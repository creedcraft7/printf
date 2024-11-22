#include "ft_printf.h"

int ft_struct(char **str, t_flag *params)
{
    while (**str && (**str == '-' || **str == '+' || **str == ' ' || **str == '#' || **str == '0'))
    {
        if (**str == '+')
            params->plus = true;
        else if (**str == '-')
            params->minus = true;
        else if (**str == ' ' )
            params->space = true;
        else if (**str == '#')
            params->hashtag = true; 
        else if (**str == '0')
            params->zero = true;
        (*str)++; 
    }
	params->width = ft_atoi(str);
	if(**str == '.')
	{
		params->precision_exist = true;
		(*str)++;
		params->precision = ft_atoi(str);
	}
    return 0;
}