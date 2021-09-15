/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:00:59 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/15 12:13:01 by jvander-         ###   ########.fr       */
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
	ft_swap(stack_a);
	ft_swap(stack_b);
	printf("=====a=====\n");
	ft_display_stack(stack_a);
	printf("=====b=====\n");
	ft_display_stack(stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	check_leaks();
	return (0);
}
