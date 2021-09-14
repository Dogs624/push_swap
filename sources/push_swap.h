/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:01:33 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/14 15:31:01 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*first;
}	t_stack;

int		ft_push(t_stack *stack, int data);
void	check_leaks(void);
t_stack	*ft_create_stack(int argc, char **argv);
void	ft_free_stack(t_stack *stack);
void	ft_display_stack(t_stack *stack);

#endif
