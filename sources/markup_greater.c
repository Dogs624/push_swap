/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_greater.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:38:43 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/21 14:25:42 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_higher(t_node **node, int *higher)
{
	if ((*higher) < (*node)->data)
	{
		(*higher) = (*node)->data;
		(*node) = (*node)->next;
		return (1);
	}
	(*node) = (*node)->next;
	return (0);
}

static int	markup(t_stack *stack, int try)
{
	int		ret;
	t_node	*tmp;
	int		higher;
	int		i;

	i = 0;
	higher = try;
	tmp = stack->first;
	while (tmp->data != try)
		tmp = tmp->next;
	ret = 1;
	while (tmp)
	{
		ret += is_higher(&tmp, &higher);
		i++;
	}
	if (i < ft_stack_size(stack))
	{
		tmp = stack->first;
		while (tmp->data != try)
			ret += is_higher(&tmp, &higher);
	}
	return (ret);
}

void	markup_greater(t_stack *stack)
{
	int		i;
	t_node	*tmp;

	tmp = stack->first;
	i = 0;
	while (i < ft_stack_size(stack))
	{
		tmp->markup_greater = markup(stack, tmp->data);
		i++;
		tmp = tmp->next;
	}
}
