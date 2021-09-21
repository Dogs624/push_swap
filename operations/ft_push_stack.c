/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:16:19 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/21 11:20:59 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

int	ft_push_stack(t_stack *stack_out, t_stack *stack_in)
{
	t_node	*node;

	node = ft_pop(stack_out);
	if (!ft_push(stack_in, node->data))
		return (0);
	free(node);
	if (stack_out->name == 'b')
		ft_putstr("pa\n");
	else
		ft_putstr("pb\n");
	return (1);
}
