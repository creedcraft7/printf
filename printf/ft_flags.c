/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:49:57 by mtaleb            #+#    #+#             */
/*   Updated: 2024/11/21 21:33:54 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *PlusFlag(char *ptr)
{
    int i;
	int j;
	char *str;
	size_t len;
	
	len = ft_strlen(ptr);
	str = ft_calloc(len + 2, sizeof(char));
		if(!str)
			return NULL; 
	j = 0;
	i = 0;
    if (ptr[0] != '+')
        str[j++] = '+';
    while (ptr[i])
	{ 
    	str[j++] = ptr[i++];
	}
	str[j] = 0;
	free (ptr);
    return str;
}

char *SpaceFlag(char *ptr)
{
    int i = 0, j = 0;
    size_t len = ft_strlen(ptr);
	if (len == 0)
		return ptr;
    char *str = ft_calloc(len + 2, sizeof(char));
    if (!str)
        return NULL;
    if (ptr[0] != ' ')
        str[j++] = ' ';
    while (ptr[i]) 
        str[j++] = ptr[i++];
    str[j] = '\0';
    free(ptr);
    return str;
}
char *HashtagFlag(char *ptr, t_flag *params) 
{
    int i;
	int j;
	char *str;
	size_t len;
	
	len = ft_strlen(ptr);
	str = ft_calloc(len + 3, sizeof(char));
		if(!str)
			return NULL; 
	i = 0;
	j = 0;
    str[j++] = '0';
	if (params->specifier == 5)
		str[j++] = 'X';
	else
    	str[j++] = 'x';
    while (ptr[i]) 
    	str[j++] = ptr[i++];
    str[j] = '\0';
	free (ptr);
    return str;
}

char *ft_flags(char *ptr, t_flag *params)
{
	if(!ptr)
		return NULL;
    if (params->plus_flag && ptr[0] != '-' && params->specifier > 5)
	{
        return PlusFlag(ptr);
	}
    if (params->space_flag && ptr[0] != '-' && !params->plus_flag && params->specifier > 5)
	{
        return SpaceFlag(ptr);
	}
    if (params->hashtag && (params->specifier == 4 || params->specifier == 5))
	{
        return HashtagFlag(ptr, params);
	}
    return ptr;
}
