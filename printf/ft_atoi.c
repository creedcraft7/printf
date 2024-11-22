#include "ft_printf.h"

long ft_atoi(char **nptr)
{
	long result;
	
	result = 0;
	while (ft_isdigit(**nptr))
    {
		result = result * 10 + **nptr - '0';
		if (result > 2147483647)
			return result;
		(*nptr)++;
	}
	return result;
}
