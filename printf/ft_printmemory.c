/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 05:12:32 by mtaleb            #+#    #+#             */
/*   Updated: 2024/11/20 17:58:41 by mtaleb           ###   ########.fr       */
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
    // char hex[19];
    // unsigned char base[] = "0123456789abcdef";
    // unsigned char *ptr = (unsigned char *)&addr;
	if(!addr)
		return (NULL);
    // int i = 9; 
    // int j = 0; 
	
    // while (i >= 0) 
	// {
	// 	if(ptr[i] == 0)
	// 	{
	// 		i--;
	// 		continue;
	// 	}
    //     hex[j++] = base[ptr[i] / 16];
    //     hex[j++] = base[ptr[i] % 16]; 
    //     i--;
    // }
	// hex[0] = '0';
	// hex[1] = 'x';
    // hex[j] = '\0'; 
    // return ft_strdup(hex);
	char *ptr = ft_memhexa((unsigned long) addr, "0123456789abcdef");
	ptr = ft_append(ptr, 'x', 0);
	ptr = ft_append(ptr, '0', 0);
	return ptr;
}

// int main()
// {
// 	char *ptr = (char *) 0x6020000004f0;
// 	//                     
// 	ptr = ft_printmemory(ptr);
// 	printf("the return is: %s\n", ptr);
// }