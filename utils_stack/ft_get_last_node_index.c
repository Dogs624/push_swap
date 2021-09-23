/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_node_index.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:34:48 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/23 13:35:56 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

int	ft_get_last_node_index(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->first;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->index);
}
