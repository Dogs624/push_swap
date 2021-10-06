/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:15:11 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/05 16:05:07 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nbr_move(t_stack *stack, t_node *node)
{
	if (node->pos < ft_stack_size(stack) / 2)
		return (node->pos);
	return (ft_stack_size(stack) - node->pos);
}
