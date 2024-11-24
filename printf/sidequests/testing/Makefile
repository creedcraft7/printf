
NAME = libftprintf.a

RESOURCE = 	ft_printf.c

OBJECTS = $(RESOURCE:.c=.o)

FLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus: all

n:
	rm -f ft_printf.h.gch
	gcc ft_*
	rm -f ft_printf.h.gch

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all 

%.o: %.c
	cc $(FLAGS) -c $< -o $@