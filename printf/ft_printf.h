#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

//  csuxXdip
// 012345678
typedef struct flags {
    bool zero_flag;
    bool minus_flag;
    bool plus_flag;
    int precision_flag;
    int width;
    bool space_flag;
	bool hashtag;
	int specifier;
	bool precision_exist;
} t_flag;






char	*ft_format(const char *format, va_list args, t_flag *params);
char	*ft_hexa(unsigned int n, char *base, t_flag *params);
char	*ft_append(char *org, char c, int position);
char	*ft_precision(t_flag *flag, char *str);
char	*ft_flags(char *ptr, t_flag *params);
char	*ft_unsigned_itoa(unsigned int n);
char	*ft_unsigned_itoa(unsigned int n);
char	*ft_printmemory(void *addr);
char	*ft_strdup(const char *s);
char	*ft_null(t_flag *params);
char	*ft_itoa(int n);


void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_init_flags(t_flag *flag);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	*ft_calloc(size_t nmemb, size_t size);


int		ft_char(int c, int width, bool minus);
int		ft_width(char *ptr, t_flag *params);
int		ft_struct(char **str, t_flag *flag);
int 	ft_printf(const char *, ...);
int		ft_overflow(char *s);
int		ft_order(char *s);
int		ft_isdigit(int c);


long	ft_atoi(char **nptr);

size_t	ft_strlen(const char *s);

#endif