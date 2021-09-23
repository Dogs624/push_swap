/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:07:18 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/23 12:13:35 by jvander-         ###   ########.fr       */
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
		printf("m - %d ", use->markup_greater);
		printf("k - %d ", use->keep);
		printf("i - %d\n", use->index);
		use = use->next;
	}
	printf("=======\n");
}
