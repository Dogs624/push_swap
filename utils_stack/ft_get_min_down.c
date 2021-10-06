/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:41:42 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/05 14:33:37 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

t_node	*ft_get_min_down(t_stack *stack, int min, int max)
{
	t_node	*ret;
	t_node	*tmp;

	tmp = stack->first;
	ret = NULL;
	while (tmp)
	{
		if (tmp->index >= min && tmp->index <= max)
			ret = tmp;
		tmp = tmp->next;
	}
	return (ret);
}
