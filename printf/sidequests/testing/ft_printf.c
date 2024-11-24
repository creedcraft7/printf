#include "ft_printf.h"

// int	ft_printf(const char *s, ...)
// {
// 	va_list	args;
// 	t_flag	params;
// 	int	result;

// 	if (!ft_overflow((char *)s))
// 		return -1;
// 	result = 0;
// 	va_start(args, s);
// 	while (*s)
// 	{
// 		if(*s == '%')
// 		{
// 			if (ft_order((char *)++s) && (*s && *s != '%'))
// 				result += ft_parse_format(&s, args, &params);
// 			else
// 				ft_putchar((result++, '%'));
// 		}
// 		else
// 			ft_putchar((result++, *s));
// 		s++;
// 	}
// 	va_end(args);
// 	return (result);
// }

// Define a clone function for printf
// Define the ft_printf function that returns the number of characters printed
int 	ft_printf(const char *format, ...) {
    va_list args;

    // Initialize the va_list
    va_start(args, format);

    // Use vprintf to handle the format and arguments
    int result = vprintf(format, args);

    // Clean up the va_list
    va_end(args);

    // Return the number of characters printed (or negative value on error)
    return result;
}

//int main()
//{
//	// ft_printf("%++i\n", (int)-2147483648);
//	 
//	int result = ft_printf("%c %s - %p - %d - %i %u - %x - %X %%\n", '\0', NULL, (void *)0xdeadc0de, 0, (int)-2147483648, -1, -1, 200000000);
//	printf("%d\n", result);
//
//	result = printf("%c %s - %p - %d - %i %u - %x - %X %%\n", '\0', NULL, (void *)0xdeadc0de, 0, (int)-2147483648, -1, -1, 200000000);
//	printf("%d\n", result);
//
//	ft_printf("the password is %xhhh\n", 3735929054u);
//	printf("%d\n", result);
//	printf("the password is %xhhh\n", 3735929054u);
//	result = printf("the password is %xhhh\n", 3735929054u);
//	printf("%d\n", result);
//	
//}
// int main()
// {
// 	ft_printf("%++d\n", (int)-2147483648);
// }
