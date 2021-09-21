/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:38:55 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/15 15:32:57 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

void	ft_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*first;

	if (!stack->first)
		return ;
	if (!stack->first->next)
		return ;
	if (!stack->first->next->next)
	{
		ft_swap(stack);
		return ;
	}
	first = stack->first;
	stack->first = stack->first->next;
	last = stack->first;
	first->next = NULL;
	while (last->next)
		last = last->next;
	last->next = first;
	if (stack->name == 'a')
		ft_putstr("ra\n");
	else
		ft_putstr("rb\n");
}
