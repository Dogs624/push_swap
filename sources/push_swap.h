/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:01:33 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/23 14:23:11 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "limits.h"
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	int				index;
	int				keep;
	int				markup_greater;
}	t_node;

typedef struct s_stack
{
	t_node	*first;
	int		max_keep;
}	t_stack;

int		ft_push(t_stack *stack, t_node *data);
void	check_leaks(void);
t_stack	*ft_create_stack(int argc, char **argv);
t_stack	*ft_free_stack(t_stack *stack);
void	ft_display_stack(t_stack *stack);
int		error_handling(int argc, char **argv);
t_stack	*ft_init_stack(void);
t_node	*ft_pop(t_stack *stack);
int		ft_push_stack(t_stack *stack_in, t_stack *stack_out, char *op);
void	ft_swap(t_stack *stack, char *op);
void	ft_rotate(t_stack *stack, char *op);
void	ft_reverse(t_stack *stack, char *op);
int		ft_issort(t_stack *stack);
int		ft_stack_size(t_stack *stack);
void	ft_create_index(t_stack *stack);
t_node	*ft_get_min(t_stack *stack);
void	markup_greater(t_stack *stack);
void	ft_setkeep(t_stack *stack);
void	sort(t_stack *stack_a, t_stack *stack_b);
t_node	*get_head(t_stack *stack);
int		ft_get_higher_index(t_stack *stack);
int	ft_get_last_node_index(t_stack *stack);

#endif
