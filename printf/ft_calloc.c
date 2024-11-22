#include "ft_printf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	size_t		len;

	if (nmemb != 0 && size > __SIZE_MAX__ / nmemb)
		return (NULL);
	len = nmemb * size;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, len);
	return (ptr);
}