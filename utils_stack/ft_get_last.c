/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:15:08 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/04 11:16:29 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

t_node	*ft_get_last(t_stack *stack)
{
	t_node	*ret;

	ret = stack->first;
	while (ret->next)
		ret = ret->next;
	return (ret);
}
