/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:52:29 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/23 12:56:03 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

void	ft_swap(t_stack *stack, char *op)
{
	t_node	*first;
	t_node	*second;
	t_node	*tmp;

	if (!stack->first)
		return ;
	if (!stack->first->next)
		return ;
	first = stack->first;
	second = stack->first->next;
	tmp = second->next;
	stack->first = second;
	second->next = first;
	first->next = tmp;
	if (op)
	{
		ft_putstr(op);
		ft_putchar('\n');
	}
}
