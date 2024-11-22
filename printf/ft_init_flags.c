#include "ft_printf.h"

void ft_init_flags(t_flag *params)
{
	if (params != NULL) 
	{
		params->zero_flag = false;
		params->minus_flag = false;
		params->plus_flag = false;
		params->precision_flag = 0;
    	params->width = 0;
    	params->space_flag = false;
    	params->hashtag = false;
		params->specifier = 1;
		params->precision_exist = false;
	}
}
