#include "ft_printf.h"

void ft_init_flags(t_flag *params)
{
	if (params != NULL) 
	{
		params->zero = false;
		params->minus = false;
		params->plus = false;
		params->precision = 0;
    	params->width = 0;
    	params->space = false;
    	params->hashtag = false;
		params->specifier = 1;
		params->precision_exist = false;
		params->negative = false;
	}
}
