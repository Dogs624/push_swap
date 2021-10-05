/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:16:15 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/04 17:37:08 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_push(t_stack *stack_a, t_stack *stack_b, int nbr_it, int op)
{
	if (op == 1)
	{
		while (nbr_it > 0)
		{
			ft_rotate(stack_a, "ra");
			nbr_it--;
		}
	}
	else
	{
		while (nbr_it > 0)
		{
			ft_reverse(stack_a, "rra");
			nbr_it--;
		}
	}
	ft_push_stack(stack_a, stack_b, "pb");
}
