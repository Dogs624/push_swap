/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:20:08 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/12 13:53:55 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int		i;
	t_node	*tmp;

	i = 0;
	if (!stack)
		return (0);
	tmp = stack->first;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	return (++i);
}
