#include "ft_printf.h"

char *ft_hexa(unsigned int n, char *base, t_flag *params)
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
	if (result[0] == '0')
		params->hashtag = false;
	return result;
}
// int main()
// {
// 	unsigned char *ptr;
// 	t_flag params;
// 	printf("%s\n",ft_hexa(912314, "0123456789abcdef", &params));
// 	printf("%x\n", 912314);
// }

