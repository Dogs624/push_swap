/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:07:18 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/28 13:43:48 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

void	ft_display_stack(t_stack *stack)
{
	t_node	*use;

	use = stack->first;
	while (use)
	{
		printf("%d ---- ", use->data);
		printf("i - %d\n", use->index);
		use = use->next;
	}
	printf("=======\n");
}
