/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:00:59 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/23 14:48:12 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (error_handling(argc, argv))
	{
		ft_putstr("Error\n");
		exit(1);
	}
	stack_a = ft_create_stack(argc, argv);
	if (!stack_a)
		exit(1);
	stack_b = ft_init_stack();
	if (!stack_b)
	{
		ft_free_stack(stack_a);
		exit(1);
	}
	if (ft_issort(stack_a))
		return (0);
	sort(stack_a, stack_b);
	// if (ft_issort(stack_a))
	// 	printf("SORTED\n");
	// else
	// 	printf("NOT GOOD MA DUDE\n");
	// ft_display_stack(stack_a);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	check_leaks();
	return (0);
}
