/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 05:12:32 by mtaleb            #+#    #+#             */
/*   Updated: 2024/11/21 21:37:06 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static char *ft_memhexa(unsigned long n, char *base)
{
	char *result;
	result = 0;
	while (1)
	{
		result = ft_append(result, base[n % 16], 0);
		n /= 16;
		if (!n)
			break;
	}
	return result;
}
char *ft_printmemory(void *addr) 
{
	if(!addr)
		return (NULL);
	char *ptr = ft_memhexa((unsigned long) addr, "0123456789abcdef");
	ptr = ft_append(ptr, 'x', 0);
	ptr = ft_append(ptr, '0', 0);
	return ptr;
}