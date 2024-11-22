#include "ft_printf.h"

int ft_struct(char **str, t_flag *params)
{
    while (**str && (**str == '-' || **str == '+' || **str == ' ' || **str == '#' || **str == '0'))
    {
        if (**str == '+')
            params->plus_flag = true;
        else if (**str == '-')
            params->minus_flag = true;
        else if (**str == ' ' )
            params->space_flag = true;
        else if (**str == '#')
            params->hashtag = true; 
        else if (**str == '0')
            params->zero_flag = true;
        (*str)++; 
    }
	params->width = ft_atoi(str);
	if(**str == '.')
	{
		params->precision_exist = true;
		(*str)++;
		params->precision_flag = ft_atoi(str);
	}
    return 0;
}