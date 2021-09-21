/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:16:21 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/21 10:10:18 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

void	ft_create_index(t_stack *stack)
{
	int		idx;
	int		size_stack;
	t_node	*tmp;
	t_node	*min;

	size_stack = ft_stack_size(stack);
	idx = 0;
	while (idx < size_stack)
	{
		min = ft_get_min(stack);
		tmp = stack->first;
		while (tmp->data != min->data)
			tmp = tmp->next;
		tmp->index = idx;
		idx++;
	}
}
