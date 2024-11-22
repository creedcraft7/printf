#include "ft_printf.h"


static int ft_parse_format(const char **s, va_list args, t_flag *params)
{
    char *temp;
	int	 res;
	
	res = 0;
    ft_init_flags(params);
    ft_struct((char **)s, params);

	if (**s == 'c')
	{
		res = ft_char(va_arg(args, int), params->width, params->minus_flag);
		return res;
	}
    temp = ft_format(*s, args, params);
	//printf("\nthe return of format is: %s\n", temp);
	
    temp = ft_flags(temp, params);
	
    res = ft_width(temp, params);

	// // free(temp);
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
			if (ft_order((char *)++s) && (*s && *s != '%'))  // to solve %q and %%
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

#include <stdio.h>

// int main()
// {
// 	char *ptr;
// 	ft_printf("ftprintf: %.0dhh\n", 0);

// 	printf("printf: %.0dhh\n", 0);



// }

// int main()
// {
//     char ft_output[1024];  // Buffer to hold ft_printf output
//     char printf_output[1024];  // Buffer to hold printf output

//     // Capture ft_printf output
//     int result = ft_printf("hh %%   %%   %% hh\n");
//     snprintf(ft_output, sizeof(ft_output), "%s", "hh %%   %%   %% hh\n"); // you should redirect the output in actual code

//     // Capture printf output
//     result = printf("hh %%   %%   %% hh\n");
//     snprintf(printf_output, sizeof(printf_output), "%s", "hh %%   %%   %% hh\n"); // similar, you'd redirect output in actual code

//     // Print the results
//     printf("ft_printf result: %s\n", ft_output);
//     printf("printf result: %s\n", printf_output);

//     // Compare the outputs
//     if (strcmp(ft_output, printf_output) == 0) {
//         printf("The outputs are equal.\n");
//     } else {
//         printf("The outputs are different.\n");
//     }

//     // Optionally compare character by character
//     for (int i = 0; i < sizeof(ft_output); i++) {
//         if (ft_output[i] != printf_output[i]) {
//             printf("Difference at position %d: ft_printf: '%c', printf: '%c'\n", i, ft_output[i], printf_output[i]);
//         }
//     }

//     return 0;
// }
