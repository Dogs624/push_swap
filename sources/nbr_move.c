/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:15:11 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/01 11:56:23 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nbr_move(t_stack *stack, t_node *node)
{
	if (node->pos <= ft_stack_size(stack) / 2)
		return (node->pos - 1);
	return (ft_stack_size(stack) - node->pos + 1);
}
