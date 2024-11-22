/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:56:22 by mtaleb            #+#    #+#             */
/*   Updated: 2024/11/20 19:08:11 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int print_ShiftRight(char *ptr, t_flag *params, char c)
{
    int i;
    int count;
    int len;
  
    len = ft_strlen(ptr);
    i = 0;
    count = 0;
    if ((ptr[0] == '+' || ptr[0] == '-' || ptr[0] == ' ') && c == '0')
    {
        ft_putchar(ptr[0]);
        count++;
        ptr++;
    }
    while (params->width-- > len)
    {
        ft_putchar(c);
        count++;
    }
    while (ptr[i])
    {
        ft_putchar(ptr[i++]);
        count++;
    }
    return count;
}

static int print_ShiftLeft(char *ptr, t_flag *params, char c)
{
    int i;
    int count;
	
	i = 0;
	count = 0;
    while (ptr[i])
    {
        ft_putchar(ptr[i]);
        count++;
        i++;
        params->width--;
    }
    while (params->width > 0)
    {
        ft_putchar(c);
        params->width--;
        count++;
    }
    return count;
}
int ft_width(char *ptr, t_flag *params)
{
    int count = 0;
	char c;
	int len;
	
    if (!ptr)
	{
        ptr = ft_null(params);
	}
	// if (ptr)

	len = ft_strlen(ptr); /// remmmm
    	c = ' ';
    if(params->zero_flag && !params->minus_flag && params->specifier > 1)
        c = '0';
  
    if ((ptr[0] == '0' && ptr[1] == 'x') && c == '0')
    {
        ft_putstr("0x");
        params->width -= 2;
        ptr += 2;
        count += 2;
    }
   	if(params->width > len)
	{ 
			if (params->minus_flag == false)
        		count = print_ShiftRight(ptr, params, c);
    		else
        		count = print_ShiftLeft(ptr, params, c);
	}
	else
	{
		ft_putstr(ptr);
		free(ptr);
        return len;
	}
	free(ptr);
    return count;
}
#include "printf.h"
#include <stdio.h>
#include <stdlib.h>

// int main() {
//     t_flag flags;
//     char *str;
//     int result;

    // Test case 1: No flags, width larger than string length
    // flags.width = 10;
    // flags.zero_flag = 0;   // Don't use zero padding
    // flags.minus_flag = 0;  // Don't use left alignment
    // flags.specifier = 2;   // Example specifier (could be for integer, string, etc.)
    // str = "Test";

    // result = ft_width(str, &flags);
    // printf("\nResult: %d\n", result); // To see the length returned and check behavior

    // // Test case 2: Zero padding flag
    // flags.width = 10;
    // flags.zero_flag = 1;   // Enable zero padding
    // flags.minus_flag = 0;  // Don't use left alignment
    // str = "Test";

    // result = ft_width(str, &flags);
    // printf("\nResult: %d\n", result); // Check if padding is correct

    // // Test case 3: Minus flag (left alignment)
    // flags.width = 10;
    // flags.zero_flag = 0;   // Disable zero padding
    // flags.minus_flag = 1;  // Enable left alignment
    // str = "Test";

    // result = ft_width(str, &flags);
    // printf("\nResult: %d\n", result); // Check if alignment is left

    // // Test case 4: Width smaller than string length
    // flags.width = 3;   // Set width smaller than string length
    // flags.zero_flag = 0;
    // flags.minus_flag = 0;
    // str = "Test";

    // result = ft_width(str, &flags);
    // printf("\nResult: %d\n", result); // Check if width adjustment is skipped

    // // Test case 5: Special case with hexadecimal
    // flags.width = 10;
    // flags.zero_flag = 1;
    // flags.minus_flag = 0;
    // flags.specifier = 4;  // Example for hex specifier
    // str = "0xabc";

    // result = ft_width(str, &flags);
    // printf("\nResult: %d\n", result); // Check if "0x" is printed first with padding
	    // Null case: ptr is NULL
//     flags.width = 10;
//     flags.zero_flag = 0;   // Don't use zero padding
//     flags.minus_flag = 0;  // Don't use left alignment
//     flags.specifier = 2;   // Example specifier (could be for integer, string, etc.)
//     str = NULL;  // Simulating the null case

//     result = ft_width(str, &flags);
//     printf("\nNull case result: %d\n", result); // Check how it handles NULL input


//     return 0;
// }
