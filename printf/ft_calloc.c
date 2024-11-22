#include "ft_printf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb && size > __SIZE_MAX__ / nmemb)
		return (0);
	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (((0)));
	ft_memset(ptr, 0, nmemb * size);
	return (((ptr)));
}
