/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:13:53 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/23 15:35:28 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

void	ft_reverse(t_stack *stack, char *op)
{
	t_node	*last;
	t_node	*first;
	
	if (ft_stack_size(stack) == 2)
	{
		ft_swap(stack, op);
		return ;
	}
	if (!stack->first)
		return ;
	if (!stack->first->next)
		return ;
	first = stack->first;
	last = first->next;
	while (last->next->next)
		last = last->next;
	stack->first = last->next;
	stack->first->next = first;
	last->next = NULL;
	if (op)
	{
		ft_putstr(op);
		ft_putchar('\n');
	}
}
