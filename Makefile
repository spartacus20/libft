# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 12:43:35 by jotomas-          #+#    #+#              #
#    Updated: 2023/11/14 19:01:23 by jotomas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
    ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
    ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
    ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS_SRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c\
        ft_lstnew.c ft_lstsize.c
CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@mkdir obj
	@cc -c $(OBJS) $(BONUS_SRCS)
	@mv  *.o obj
	@ar rcs $(NAME) ./obj/*.o

bonus:
	mkdir obj
	cc -c $(BONUS_SRCS)
	mv  *.o obj
	@ar rcs $(NAME) ./obj/*.o

re: fclean all

fclean: clean
	@rm -f libft.h.gch
	@rm -f $(NAME)

clean :
	@rm -r obj

.PHONY: clean fclean re all bonus
