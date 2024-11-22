#include "ft_printf.h"

char *ft_null(t_flag *params)
{
	params->zero_flag = false;
	if (params->specifier == 2 && params->precision_flag < 6 && params->precision_flag)
	 return (ft_strdup(""));
	if (params->specifier == 2)
		return (ft_strdup("(null)"));
	if (params->specifier == 8)
		return (ft_strdup("(nil)"));
	// return (ft_strdup(" "));
	return NULL;
}