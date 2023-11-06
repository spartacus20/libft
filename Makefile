# NAME, all, clean, fclean, re

NAME = libft.a
OBJS = ft_*.c *.h
CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@cc -c $(OBJS)
	@ar rcs $(NAME) *.o

test:
	norminette ft_*.c
	cc $(CFLAGS) main.c libft.a

verify:
	./a.out | grep -C 4 "FAILED"


re: fclean all test

fclean: clean
	@rm -f libft.h.gch
	@rm -f $(NAME)

clean :
	@rm -f *.o

.PHONY: clean fclean re all test verify
