/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:56:22 by mtaleb            #+#    #+#             */
/*   Updated: 2024/11/22 14:19:45 by mtaleb           ###   ########.fr       */
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
	 if ((ptr[0] == '0' && ptr[1] == 'x') && c == '0')
    {
        ft_putstr("0x");
        params->width -= 2;
        ptr += 2;
        count += 2;
    }
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
	int len;
	char c;
	
    if (!ptr)
	{
        ptr = ft_null(params);
	}
	len = ft_strlen(ptr);
    c = ' ';
    if(params->zero && !params->minus && params->specifier > 1)
    c = '0';
   	if(params->width > len)
	{ 
			if (params->minus == false)
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
