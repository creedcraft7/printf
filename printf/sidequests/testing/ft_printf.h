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
    bool zero;
    bool minus;
    bool plus;
    int precision;
    int width;
    bool space;
	bool hashtag;
	int specifier;
	bool precision_exist;
	bool negative;
} t_flag;

int 	ft_printf(const char *, ...);

#endif