/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:44:14 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/04 17:36:47 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_set_chunk(t_stack *stack, t_chunk **chunk, int nbr_turn)
{	
	if (!stack->first)
		return ;
	if (nbr_turn == 1)
		(*chunk)->min = 0;
	else
		(*chunk)->min = (*chunk)->max + 1;
	if (stack->initial_size < 100)
	{
		(*chunk)->max_size = 1;
		(*chunk)->max = ft_stack_size(stack);
	}
	else if (stack->initial_size >= 100 && stack->initial_size < 500)
	{
		(*chunk)->max_size = NBR_CHUNKS_100;
		(*chunk)->max = (stack->initial_size / NBR_CHUNKS_100 * nbr_turn) - 1;
	}
	else
	{
		(*chunk)->max_size = NBR_CHUNKS_500;
		(*chunk)->max = (stack->initial_size / NBR_CHUNKS_500 * nbr_turn) - 1;
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*hold_first;
	t_node	*hold_second;
	t_chunk	*chunk;
	int		nbr_turn;
	int		count;

	nbr_turn = 1;
	count = 0;
	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return ;
	}
	ft_set_chunk(stack_a, &chunk, nbr_turn);
	while (nbr_turn <= chunk->max_size)
	{
		hold_first = ft_get_min_up(stack_a, chunk->min, chunk->max);
		hold_second = ft_get_min_down(stack_a, chunk->min, chunk->max);
		while (hold_first->index != hold_second->index)
		{
			if (nbr_move(stack_a, hold_first) < nbr_move(stack_a, hold_second))
				move_push(stack_a, stack_b, nbr_move(stack_a, hold_first), 1);
			else if (nbr_move(stack_a, hold_first) > nbr_move(stack_a, hold_second))
				move_push(stack_a, stack_b, nbr_move(stack_a, hold_second), -1);
			else
				if (hold_first->index < hold_second->index)
					move_push(stack_a, stack_b, nbr_move(stack_a, hold_first), 1);
				else
					move_push(stack_a, stack_b, nbr_move(stack_a, hold_second), -1);
			hold_first = ft_get_min_up(stack_a, chunk->min, chunk->max);
			hold_second = ft_get_min_down(stack_a, chunk->min, chunk->max);
		}
		move_push(stack_a, stack_b, nbr_move(stack_a, hold_first), 1);
		nbr_turn++;
		ft_set_chunk(stack_a, &chunk, nbr_turn);
	}
	push_to_a(stack_a, stack_b);
	free(chunk);
}
