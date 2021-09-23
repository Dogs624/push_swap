/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setkeep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:47:13 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/22 15:34:00 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_head(t_stack *stack)
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

static	void	ft_keep(t_node **head, t_node **higher)
{
	if ((*head)->data > (*higher)->data)
	{
		(*head)->keep = 1;
		(*higher) = (*head);
	}
	else
		(*head)->keep = 0;
	(*head) = (*head)->next;
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
	stack->max_keep = higher->markup_greater;
	i = 0;
	head->keep = 1;
	while (head)
	{
		ft_keep(&head, &higher);
		i++;
	}
	if (i < ft_stack_size(stack))
	{
		head = stack->first;
		while (head->data != start->data)
			ft_keep(&head, &higher);
	}
}
