# NAME, all, clean, fclean, re

NAME = libft.a
OBJS = ft_*.c *.h
CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@cc -c $(OBJS)
	@mkdir obj
	@mv  *.o obj
	@ar rcs $(NAME) ./obj/*.o


re: fclean all test

fclean: clean
	@rm -f libft.h.gch
	@rm -f $(NAME)

clean :
	@rm -r obj

.PHONY: clean fclean re all
