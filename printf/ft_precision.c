#include "ft_printf.h"

static char *precision_2(int digits, char *str, char **result)
{
	size_t	len;
	
	len = strlen(str);
    *result = ft_calloc((digits + 1), sizeof(char));
    ft_memset(*result, '0', digits);
    if (str[0] == '-')
    {
		len--;
        ft_memmove(*result + (digits - len), str + 1, len);
        *result = ft_append(*result, '-', 0);
    }
    else
	{
		ft_memmove(*result + (digits - len), str, len + 1);
	}
	return (free(str), *result);
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
        if ((digits > len || (str[0] == '-' && digits > len - 1)) && params->specifier > 2)
			return (precision_2(digits, str, &result));
		else if (!digits && params->specifier > 2 && params->specifier < 8 && str[0] == '0' && str[1] == '\0')
		{
			free(str);
			return ft_strdup("");
		}
        if (digits < len && params->specifier == 2)
        {
            result = malloc((digits + 1) * sizeof(char));
            ft_memmove(result, str, digits);
            result[digits] = 0;
            free(str);
        }
    }
    return (result);
}

// int main() {
//     t_flag flags = {0};
//     flags.precision_flag = 6;
//     flags.specifier = 2;

//     char *str = malloc(10 * sizeof(char));
//     if (!str) return 1;  // Check allocation
//     snprintf(str, 10, "1234");

//     char *result = ft_precision(&flags, str);
//     printf("Result: %s\n", result);  // Print the result to see it

//     // At this point, the memory allocated for 'str' and 'result' will be freed
//     free(result);  // Free the final result

//     return 0;
// }