#include "ft_printf.h"

static int	in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return ((1));
		i++;
	}
	return ((0));
}

int ft_order(char *s) //#+10.5d
{
	size_t i; 
	
	i = 0;
	while (s[i] == '-' || s[i] == '+' || s[i] == ' ' || s[i] == '#' || s[i] == '0')
		i++;
	while (isdigit(s[i]))
		i++;
	if (s[i] == '.')
		i++;
	while (isdigit(s[i]))
		i++;
	if(in_set(s[i], "%cspdiuxX"))
		return 1;
	return 0;
}

// int main()
// {
// 	printf("the modifiers are %s\n", order("#+++    -  ++++ 0000075.8976d") ? "true" : "false");
// }