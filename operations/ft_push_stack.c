/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:16:19 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/15 11:50:15 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

int	ft_push_stack(t_stack *stack_in, t_stack *stack_out)
{
	t_node	*node;

	node = ft_pop(stack_in);
	if (!ft_push(stack_out, node->data))
		return (0);
	free(node);
	return (1);
}
