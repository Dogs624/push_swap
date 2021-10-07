/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:17:20 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/06 12:47:34 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_chunk	*ft_set_chunk(t_stack *stack_a)
{
	t_chunk	*ret;

	ret = malloc(sizeof(t_chunk));
	if (!ret)
		return (NULL);
	if (stack_a->initial_size < 100)
		ret->max_size = 1;
	else if (stack_a->initial_size >= 100 && stack_a->initial_size < 500)
		ret->max_size = 5;
	else
		ret->max_size = 11;
	ret->min = 0;
	ret->max = stack_a->initial_size / ret->max_size - 1;
	return (ret);
}

static void	ft_set_new_chunk(t_stack *stack, t_chunk **chunk)
{
	(*chunk)->min = (*chunk)->max + 1;
	(*chunk)->max = (*chunk)->max + (stack->initial_size / (*chunk)->max_size);
}

static void	main_algo(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk)
{
	t_node	*first;
	t_node	*second;

	first = ft_get_min_up(stack_a, chunk->min, chunk->max);
	second = ft_get_min_down(stack_a, chunk->min, chunk->max);
	while (first->index != second->index)
	{
		if (nbr_move(stack_a, first) < nbr_move(stack_a, second))
			move_push(stack_a, stack_b, nbr_move(stack_a, first), 1);
		else if (nbr_move(stack_a, first) > nbr_move(stack_a, second))
			move_push(stack_a, stack_b, nbr_move(stack_a, second), -1);
		else
		{
			if (first->index < second->index)
				move_push(stack_a, stack_b, nbr_move(stack_a, first), 1);
			else
				move_push(stack_a, stack_b, nbr_move(stack_a, first), -1);
		}
		first = ft_get_min_up(stack_a, chunk->min, chunk->max);
		second = ft_get_min_down(stack_a, chunk->min, chunk->max);
	}
	if (first->pos <= ft_stack_size(stack_a) / 2)
		move_push(stack_a, stack_b, nbr_move(stack_a, first), 1);
	else
		move_push(stack_a, stack_b, nbr_move(stack_a, second), -1);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_chunk	*chunk;

	chunk = ft_set_chunk(stack_a);
	if (!chunk)
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return ;
	}
	while (stack_a->first && chunk->min < stack_a->initial_size)
	{
		main_algo(stack_a, stack_b, chunk);
		ft_set_new_chunk(stack_a, &chunk);
	}
	push_to_a(stack_a, stack_b);
	free(chunk);
}
