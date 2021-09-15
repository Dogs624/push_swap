# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 10:07:20 by jvander-          #+#    #+#              #
#    Updated: 2021/09/15 11:24:56 by jvander-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
LIBFT	=	./libft
UTILS	=	utils_stack/
SOURCES =	sources/
CC		=	gcc
INCLUDES = -I./includes/
FLAGS	=	-Wall -Werror -Wextra $(INCLUDES)

SRCS_UTILS_STACK	=	$(UTILS)ft_push.c \
						$(UTILS)ft_create_stack.c \
						$(UTILS)ft_free_stack.c \
						$(UTILS)ft_display_stack.c \
						$(UTILS)ft_init_stack.c \
						$(UTILS)ft_pop.c \

SRCS	=	$(SOURCES)leacks_cheker_ex.c \
			$(SOURCES)push_swap.c \
			$(SOURCES)error_handling.c \
			$(SOURCES)ft_push_stack.c \

%.o: %.c
		$(CC) $(FLAGS) -o $@ -c $<

OBJS		=	$(SRCS:.c=.o)

OBJS_UTILS_STACK = $(SRCS_UTILS_STACK:.c=.o)

$(NAME):	$(OBJS) $(OBJS_UTILS_STACK)
			$(MAKE) -C $(LIBFT)
			$(CC) $(FLAGS) $(OBJS) $(OBJS_UTILS_STACK) -L$(LIBFT) -lft -o  $(NAME)

all:	$(NAME)

clean:
		$(MAKE) clean -C $(LIBFT)
		rm -f $(OBJS) $(OBJS_UTILS_STACK)

fclean:	clean
		$(MAKE) fclean -C $(LIBFT)
		rm -f $(NAME) $(OBJS_UTILS_STACK)

re: fclean all

.PHONY: all clean fclean re
