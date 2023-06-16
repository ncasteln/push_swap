# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 15:23:28 by ncasteln          #+#    #+#              #
#    Updated: 2023/06/16 15:52:11 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c \
	clst.c \
	./utils/validation.c \
	./utils/ft_strchr.c \
	./utils/ft_atol.c \
	./utils/ft_split.c \
	./utils/error.c
OBJS = $(SRC:.c=.o)

CLST = clst.c \
	clst_test.c \
	ft_atol.c \
	ft_split.c
CLSTOBJS = $(CLST:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	cc -c $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# CLISTS TESTING
clst: $(CLSTOBJS)
	cc $(CFLAGS) $(CLSTOBJS) -o $@

clst_clean:
	rm -f $(CLSTOBJS) clst

# VALGRIND
valgrind: $(NAME)
	valgrind --leak-check=full ./$(NAME) 5 9 12 17 23

valgrind_string: $(NAME)
	valgrind --leak-check=full ./$(NAME) "5 9 12 17 23"

valgrind_mix: $(NAME)
	valgrind --leak-check=full ./$(NAME) 5 9 12 "17 23"


.PHONY: all clean fclean re
