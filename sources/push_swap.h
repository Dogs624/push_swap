/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:01:33 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/12 12:17:34 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	int				index;
	int				pos;
}	t_node;

typedef struct s_stack
{
	t_node	*first;
	int		initial_size;
}	t_stack;

typedef struct s_chunk
{
	int	min;
	int	max;
	int	max_size;
}	t_chunk;

int		ft_push(t_stack *stack, t_node *data);
int		error_handling(int argc, char **argv);
int		ft_push_stack(t_stack *stack_in, t_stack *stack_out, char *op);
int		ft_issort(t_stack *stack);
int		ft_stack_size(t_stack *stack);
int		nbr_move(t_stack *stack, t_node *node);
int		ft_tabsize(char **tab);
int		ft_free_all(t_stack *stack_a, t_stack *stack_b, char **args);
void	ft_swap(t_stack *stack, char *op);
void	ft_rotate(t_stack *stack, char *op);
void	ft_reverse(t_stack *stack, char *op);
void	ft_create_index(t_stack *stack);
void	ft_create_pos(t_stack *stack);
void	move_push(t_stack *stack_a, t_stack *stack_b, int nbr_it, int op);
void	push_to_a(t_stack *stack_a, t_stack *stack_b);
void	sort(t_stack *stack_a, t_stack *stack_b);
void	sort_simple(t_stack *stack_a, t_stack *stack_b);
t_stack	*ft_create_stack(int argc, char **argv);
t_stack	*ft_free_stack(t_stack *stack);
t_stack	*ft_init_stack(void);
t_node	*ft_get_min_up(t_stack *stack, int min, int max);
t_node	*ft_get_min(t_stack *stack);
t_node	*ft_get_min_down(t_stack *stack, int min, int max);
t_node	*ft_get_max(t_stack *stack);
t_node	*ft_pop(t_stack *stack);
t_node	*ft_get_last(t_stack *stack);
char	**split_arg(char **argv, int size_ret, int size_use, char **to_ret);

#endif
