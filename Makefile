# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 14:47:33 by rkowalsk          #+#    #+#              #
#    Updated: 2021/03/31 12:31:46 by rkowalsk         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CHECKER = checker

PS = push_swap

INCLUDES = includes/push_swap.h \
		   includes/libft.h

LIBFT = libft/libft.a

SRCS_SHARED = \
	srcs/useful.c \
	srcs/args_pars.c \
	srcs/mod_stacks.c \
	srcs/mod_stacks_bis.c \
	srcs/mod_stacks_bis_bis.c

SRCS_CHECKER = \
	srcs/checker.c \

SRCS_PS = \
	srcs/push_swap.c \
	srcs/sort.c \
	srcs/sort_small.c \
	srcs/sort_funcs.c \
	srcs/sort_funcs_2.c

OBJS_CHECKER = ${SRCS_CHECKER:.c=.o}

OBJS_PS = ${SRCS_PS:.c=.o}

OBJS_SHARED = ${SRCS_SHARED:.c=.o}

$(CHECKER): $(OBJS_CHECKER) $(OBJS_SHARED) $(LIBFT)
	clang -o $(CHECKER) $(OBJS_CHECKER) $(OBJS_SHARED) $(LIBFT)

$(PS): $(OBJS_PS) $(OBJS_SHARED) $(LIBFT)
	clang -o $(PS) $(OBJS_PS) $(OBJS_SHARED) $(LIBFT)

$(OBJS_CHECKER): %.o: %.c $(INCLUDES)
	clang -g3 -Wall -Wextra -Werror -Iincludes -c $< -o $@

$(OBJS_PS): %.o: %.c $(INCLUDES)
	clang -g3 -Wall -Wextra -Werror -Iincludes -c $< -o $@

$(OBJS_SHARED): %.o: %.c $(INCLUDES)
	clang -g3 -Wall -Wextra -Werror -Iincludes -c $< -o $@

$(LIBFT): 
	$(MAKE) -C libft all

.PHONY: all clean fclean re

all: $(LIBFT) $(CHECKER) $(PS)

clean:
	rm -f $(OBJS_PS) $(OBJS_SHARED) $(OBJS_CHECKER)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(CHECKER) $(PS)
	$(MAKE) -C libft fclean

re: fclean all
