/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:45:35 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/23 12:59:51 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	need_sa(t_stack *stack_a)
{
	t_node	*head;

	head = get_head(stack_a);
	ft_swap(stack_a, NULL);
	ft_setkeep(stack_a);
	if (get_head(stack_a)->markup_greater > head->markup_greater
		|| ft_issort(stack_a))
	{
		ft_swap(stack_a, NULL);
		ft_setkeep(stack_a);
		return (1);
	}
	ft_swap(stack_a, NULL);
	ft_setkeep(stack_a);
	return (0);
}

static int	ft_nbr_false(t_stack *stack)
{
	t_node	*tmp;
	int		ret;

	ret = 0;
	tmp = stack->first;
	while (tmp)
	{
		if (!tmp->keep)
			ret++;
		tmp = tmp->next;
	}
	return (ret);
}

static void	ft_put_higher_up(t_stack *stack)
{
	int		max_index;
	t_node	*tmp;

	tmp = stack->first;
	max_index = ft_get_higher_index(stack);
	while (tmp->index != max_index)
	{
		ft_rotate(stack, "rb");
		tmp = stack->first;
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{	
	if (ft_issort(stack_a))
		return ;
	ft_setkeep(stack_a);
	while (ft_nbr_false(stack_a) && !ft_issort(stack_a))
	{
		if (need_sa(stack_a))
			ft_swap(stack_a, "sa");
		else if (!stack_a->first->keep)
			ft_push_stack(stack_a, stack_b, "pb");
		else
			ft_rotate(stack_a, "ra");
	}
	while (stack_b->first)
	{
		ft_put_higher_up(stack_b);
		while ((stack_a->first->index) - 1 != stack_b->first->index)
			ft_rotate(stack_a, "ra");
		ft_push_stack(stack_b, stack_a, "pa");
	}
}
