/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:28:19 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/04 10:49:15 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*max;

	ft_create_pos(stack_b);
	while (stack_b->first)
	{
		max = ft_get_max(stack_b);
		while (stack_b->first->index != max->index)
			ft_rotate(stack_b, "rb");
		ft_push_stack(stack_b, stack_a, "pa");
	}
}
