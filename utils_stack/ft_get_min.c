/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:10:29 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/21 14:26:17 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

t_node	*ft_get_min(t_stack *stack)
{
	t_node	*tmp;
	t_node	*min;

	tmp = stack->first;
	while (tmp->index != -1)
		tmp = tmp->next;
	min = tmp;
	while (tmp)
	{
		if (tmp->index == -1)
		{
			if (min->data > tmp->data)
				min = tmp;
		}
		tmp = tmp->next;
	}
	return (min);
}
