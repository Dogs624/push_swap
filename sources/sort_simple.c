/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:35:37 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/06 16:58:15 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_simple_3(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack_a->first;
	second = first->next;
	third = second->next;
	if (ft_issort(stack_a))
		return ;
	if (first->index > second->index && first->index < third->index)
		return (ft_swap(stack_a, "sa"));
	if (first->index > second->index && second->index > third->index)
	{
		ft_swap(stack_a, "sa");
		return (ft_reverse(stack_a, "rra"));
	}
	if (first->index > second->index && second->index < third->index)
		return (ft_rotate(stack_a, "ra"));
	if (first->index < second->index && second->index > third->index
		&& first->index < third->index)
	{
		ft_swap(stack_a, "sa");
		return (ft_rotate(stack_a, "ra"));
	}
	ft_reverse(stack_a, "rra");
}

static void	prepare_to_push(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->first)
	{
		if (stack_a->first->index + 1 == stack_b->first->index)
		{
			ft_rotate(stack_a, "ra");
			ft_push_stack(stack_b, stack_a, "pa");
		}
		else if (ft_get_last(stack_a)->index - 1 == stack_b->first->index)
		{
			ft_reverse(stack_a, "rra");
			ft_push_stack(stack_b, stack_a, "pa");
		}
		else
		{
			if (ft_stack_size(stack_b) == 2)
			{
				if (stack_b->first->index == 0
					|| stack_b->first->index == stack_a->initial_size - 1)
					ft_push_stack(stack_b, stack_a, "pa");
			}
			ft_rotate(stack_a, "ra");
		}
	}
}

void	sort_simple(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_stack_size(stack_a) == 2)
		return (ft_swap(stack_a, "sa"));
	if (ft_stack_size(stack_a) == 3)
		return (sort_simple_3(stack_a));
	if (ft_stack_size(stack_a) == 4)
	{
		ft_push_stack(stack_a, stack_b, "pb");
		sort_simple_3(stack_a);
		prepare_to_push(stack_a, stack_b);
	}
	if (ft_stack_size(stack_a) == 5)
	{
		ft_push_stack(stack_a, stack_b, "pb");
		ft_push_stack(stack_a, stack_b, "pb");
		sort_simple_3(stack_a);
		prepare_to_push(stack_a, stack_b);
	}
	if (ft_get_last(stack_a)->index == 0)
		ft_reverse(stack_a, "rra");
	else
	{
		while (stack_a->first->index != 0)
			ft_rotate(stack_a, "ra");
	}
}
