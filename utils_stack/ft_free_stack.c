/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:55:18 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/14 16:28:20 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_node	*del;

	del = stack->first;
	stack->first = stack->first->next;
	while (del && stack->first)
	{
		free(del);
		del = stack->first;
		if (!stack->first->next)
			del = NULL;
		else
			stack->first = stack->first->next;
	}
	free(del);
	free(stack);
}
