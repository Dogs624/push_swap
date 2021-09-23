/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:16:19 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/23 12:17:06 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

int	ft_push_stack(t_stack *stack_out, t_stack *stack_in, char *op)
{
	t_node	*node;

	node = ft_pop(stack_out);
	if (!ft_push(stack_in, node))
		return (0);
	if (op)
	{
		ft_putstr(op);
		ft_putchar('\n');
	}
	return (1);
}
