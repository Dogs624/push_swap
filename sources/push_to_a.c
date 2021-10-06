/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:28:19 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/05 16:37:22 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*max;
	int		nbr_it;

	ft_create_pos(stack_b);
	while (stack_b->first)
	{
		max = ft_get_max(stack_b);
		nbr_it = nbr_move(stack_b, max);
		if (max->pos < ft_stack_size(stack_b) / 2)
		{
			while (nbr_it--)
				ft_rotate(stack_b, "rb");
		}
		else
		{
			while (nbr_it--)
				ft_reverse(stack_b, "rrb");
		}
		ft_push_stack(stack_b, stack_a, "pa");
	}
}
