/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:53:02 by mtaleb            #+#    #+#             */
/*   Updated: 2024/11/21 21:38:04 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"


static int	num_len(unsigned long int nb)
{
	int	i;

	i = 0;
	if(nb == 0)
		i++;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char *ft_unsigned_itoa(unsigned int n)
{
	char		*res;
	int			len;
	long int	nb;

	nb = (unsigned long)n;
	len = num_len(nb);
	res = malloc(len * sizeof(char) + 1);
	if (!res)
		return (0);
	res[len] = 0;
	len--;
	if (!nb)
		res[0] = '0';
	while (nb)
	{
		res[len--] = (nb % 10 + '0');
		nb = nb / 10;
	}
	return (res);
}