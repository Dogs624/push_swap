/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:01:33 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/15 11:24:38 by jvander-         ###   ########.fr       */
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
int		error_handling(int argc, char **argv);
t_stack	*ft_init_stack(void);
t_node	*ft_pop(t_stack *stack);
int		ft_push_stack(t_stack *stack_in, t_stack *stack_out);

#endif
