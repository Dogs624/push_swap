# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 10:07:20 by jvander-          #+#    #+#              #
#    Updated: 2021/09/23 14:23:17 by jvander-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
LIBFT	=	./libft
UTILS	=	utils_stack/
SOURCES =	sources/
OPERATIONS	=	operations/
CC		=	gcc
INCLUDES = -I./includes/
FLAGS	=	-Wall -Werror -Wextra $(INCLUDES)

SRCS_OPERATIONS		=	$(OPERATIONS)ft_push_stack.c \
						$(OPERATIONS)ft_swap.c \
						$(OPERATIONS)ft_rotate.c \
						$(OPERATIONS)ft_reverse.c \

SRCS_UTILS_STACK	=	$(UTILS)ft_push.c \
						$(UTILS)ft_create_stack.c \
						$(UTILS)ft_free_stack.c \
						$(UTILS)ft_display_stack.c \
						$(UTILS)ft_init_stack.c \
						$(UTILS)ft_pop.c \
						$(UTILS)ft_stack_size.c \
						$(UTILS)ft_create_index.c \
						$(UTILS)ft_get_min.c \
						$(UTILS)ft_get_higher_index.c \
						$(UTILS)ft_get_last_node_index.c \

SRCS	=	$(SOURCES)leacks_cheker_ex.c \
			$(SOURCES)push_swap.c \
			$(SOURCES)error_handling.c \
			$(SOURCES)ft_issort.c \
			$(SOURCES)markup_greater.c \
			$(SOURCES)ft_setkeep.c \
			$(SOURCES)sort.c \

%.o: %.c
		$(CC) $(FLAGS) -o $@ -c $<

OBJS		=	$(SRCS:.c=.o)

OBJS_UTILS_STACK = $(SRCS_UTILS_STACK:.c=.o)

OBJS_OPERATIONS	=	$(SRCS_OPERATIONS:.c=.o)

$(NAME):	$(OBJS) $(OBJS_UTILS_STACK) $(OBJS_OPERATIONS)
			$(MAKE) -C $(LIBFT)
			$(CC) $(FLAGS) $(OBJS) $(OBJS_UTILS_STACK) $(OBJS_OPERATIONS) -L$(LIBFT) -lft -o  $(NAME)

all:	$(NAME)

clean:
		$(MAKE) clean -C $(LIBFT)
		rm -f $(OBJS) $(OBJS_UTILS_STACK) $(OBJS_OPERATIONS)

fclean:	clean
		$(MAKE) fclean -C $(LIBFT)
		rm -f $(NAME) $(OBJS_UTILS_STACK) $(OBJS_OPERATIONS)

re: fclean all

.PHONY: all clean fclean re
