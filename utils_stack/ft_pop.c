/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:45:24 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/01 10:41:47 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

t_node	*ft_pop(t_stack *stack)
{
	t_node	*node;

	if (!stack->first || !stack)
		return (NULL);
	node = stack->first;
	stack->first = stack->first->next;
	ft_create_pos(stack);
	return (node);
}
