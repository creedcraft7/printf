#include "ft_printf.h"

char *ft_null(t_flag *params)
{
	params->zero = false;
	if (params->specifier == 2 && params->precision< 6 && params->precision)
	 return (ft_strdup(""));
	if (params->specifier == 2)
		return (ft_strdup("(null)"));
	if (params->specifier == 8)
		return (ft_strdup("(nil)"));
	return (NULL);
}