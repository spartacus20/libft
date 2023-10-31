# NAME, all, clean, fclean, re

NAME = libft
OBJS = *.c *.h
CFLAGS= -Wall -Wextra -Werror


all: $(NAME)

$(NAME):
	@gcc  $(CFLAGS) $(OBJS) -o $(NAME)

re: fclean all

fclean:
	@rm -f $(NAME)

clean :
	@rm -f *.o

.PHONY: clean fclean re all
