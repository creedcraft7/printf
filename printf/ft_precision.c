#include "ft_printf.h"

static char *precision_2(int digits, char *str)
{
	size_t	len;
	char *result;
	len = strlen(str);
    result = ft_calloc((digits + 1), sizeof(char));
    ft_memset(result, '0', digits);
    if (str[0] == '-')
    {
		len--;
        ft_memmove(result + (digits - len), str + 1, len);
        result = ft_append(result, '-', 0);
    }
    else{
        ft_memmove(result + (digits - len), str, len + 1);
	}
	free(str);
    return (result);
}

char *ft_precision(t_flag *params, char *str)
{
    char *result;
    size_t len;
    size_t digits;

	if (!str)
		return NULL;
    len = strlen(str); 
    result = str;
    digits = params->precision_flag;

    if (digits || params->precision_exist)
    {
        params->zero_flag = false;
        if ((digits > len || (str[0] == '-' && digits > len - 1)) && params->specifier > 2){
			return (precision_2(digits, str));
		}
		else if(!digits && params->specifier > 2 && params->specifier < 8 && str[0] == '0' && str[1] =='\0')
		{
			free(str);
			return ft_strdup("");
		}
        if (digits < len && params->specifier == 2)
        {
            result = ft_calloc((digits + 1) , sizeof(char));
            ft_memmove(result, str, digits);
            result[digits] = 0;
            free(str);
        }
    }
    return (result);
}