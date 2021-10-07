/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:35:37 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/07 10:34:09 by jvander-         ###   ########.fr       */
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

static t_node	*ft_get_min_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*min;

	tmp = stack->first;
	min = stack->first;
	while (tmp)
	{
		if (tmp->index < min->index)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

static void	put_min_up(t_stack *stack_a)
{
	t_node	*min;

	min = ft_get_min_stack(stack_a);
	if (min->pos <= ft_stack_size(stack_a) / 2)
	{
		while (stack_a->first->index != min->index)
			ft_rotate(stack_a, "ra");
	}
	else
	{
		while (stack_a->first->index != min->index)
			ft_reverse(stack_a, "rra");
	}
}

void	sort_simple(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_stack_size(stack_a) == 2)
		ft_swap(stack_a, "sa");
	else if (ft_stack_size(stack_a) == 3)
		sort_simple_3(stack_a);
	else if (ft_stack_size(stack_a) == 4)
	{
		put_min_up(stack_a);
		ft_push_stack(stack_a, stack_b, "pb");
		sort_simple_3(stack_a);
		ft_push_stack(stack_b, stack_a, "pa");
	}
	else
	{
		put_min_up(stack_a);
		ft_push_stack(stack_a, stack_b, "pb");
		put_min_up(stack_a);
		ft_push_stack(stack_a, stack_b, "pb");
		if (stack_b->first->index < stack_b->first->next->index)
			ft_swap(stack_b, "sb");
		sort_simple_3(stack_a);
		ft_push_stack(stack_b, stack_a, "pa");
		ft_push_stack(stack_b, stack_a, "pa");
	}
}
