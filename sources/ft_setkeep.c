/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setkeep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:47:13 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/21 14:24:09 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_head(t_stack *stack)
{
	t_node	*tmp;
	t_node	*ret;

	tmp = stack->first->next;
	ret = stack->first;
	while (tmp)
	{
		if (ret->markup_greater < tmp->markup_greater)
			ret = tmp;
		else if (ret->markup_greater == tmp->markup_greater)
		{
			if (ret->index > tmp->index)
				ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

void	ft_setkeep(t_stack *stack)
{
	t_node	*head;
	int		i;
	t_node	*higher;
	t_node	*start;

	markup_greater(stack);
	head = get_head(stack);
	start = head;
	higher = head;
	i = 0;
	while (head)
	{
		if (head->data > higher->data || head->data == higher->data)
		{
			head->keep = 1;
			higher = head;
		}
		else
			head->keep = 0;
		i++;
		head = head->next;
	}
	if (i < ft_stack_size(stack))
	{
		head = stack->first;
		while (head->data != start->data)
		{
			if (head->data > higher->data)
			{
				head->keep = 1;
				higher = head;
			}
			else
				head->keep = 0;
			head = head->next;
		}
	}
}
