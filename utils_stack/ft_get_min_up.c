/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:00:12 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/30 13:49:09 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

t_node	*ft_get_min_up(t_stack *stack, int min, int max)
{
	t_node	*tmp;

	tmp = stack->first;
	while (tmp)
	{
		if (tmp->index >= min && tmp->index <= max)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
