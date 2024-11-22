/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:49:57 by mtaleb            #+#    #+#             */
/*   Updated: 2024/11/20 18:20:50 by mtaleb           ###   ########.fr       */
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
	str = calloc(len + 2, sizeof(char));
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
	int i = 0;
	int j = 0;
	size_t len;

	len = ft_strlen(ptr);
    char *str = calloc(len + 2, sizeof(char));
    if (!str)
        return NULL;
    if (ptr[0] != ' ' )
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
	str = calloc(len + 3, sizeof(char));
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
	char *str;
	
	if(!ptr)
		return NULL;
	str = ft_strdup(ptr);
    if (params->plus_flag && ptr[0] != '-' && params->specifier > 5)
	{
		free(str);
        return PlusFlag(ptr);
	}
    if (params->space_flag && ptr[0] != '-' && !params->plus_flag && (params->specifier == 3 || params->specifier == 6 || params->specifier == 7))
	{
		free (str);
        return SpaceFlag(ptr);
	}
    if (params->hashtag && (params->specifier == 4 || params->specifier == 5))
	{
		free (str);
        return HashtagFlag(ptr, params);
	}
	free(ptr);
    return str; // return ptr, remove strdup
}