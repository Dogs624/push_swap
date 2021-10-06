/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:38:55 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/06 14:20:51 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

void	ft_rotate(t_stack *stack, char *op)
{
	t_node	*last;
	t_node	*first;

	if (!stack->first)
		return ;
	if (!stack->first->next)
		return ;
	if (ft_stack_size(stack) == 2)
	{
		ft_swap(stack, op);
		return ;
	}
	first = stack->first;
	stack->first = stack->first->next;
	last = stack->first;
	first->next = NULL;
	while (last->next)
		last = last->next;
	last->next = first;
	if (op)
	{
		ft_putstr_fd(op, 1);
		ft_putchar_fd('\n', 1);
	}
}
