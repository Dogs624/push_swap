/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:45:24 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/15 12:17:35 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

t_node	*ft_pop(t_stack *stack)
{
	t_node	*node;

	if (!stack->first)
		return (NULL);
	node = stack->first;
	stack->first = stack->first->next;
	return (node);
}
