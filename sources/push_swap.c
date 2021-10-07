/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:00:59 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/07 10:34:00 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialise(t_stack **s_a, t_stack **s_b, char **args, int size)
{
	(*s_a) = ft_create_stack(size, args);
	if (!(*s_a))
		exit(1);
	(*s_b) = ft_init_stack();
	if (!(*s_b))
	{
		ft_free_stack((*s_a));
		exit(1);
	}
}

static void	sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_stack_size(stack_a) <= 5)
		sort_simple(stack_a, stack_b);
	else
		sort(stack_a, stack_b);
}

static int	set_tab_use(int argc, char **argv, char ***to_use, int *size_use)
{
	if (argc == 2)
	{
		*to_use = ft_split(argv[1], ' ');
		*size_use = ft_tabsize((*to_use));
		if (error_handling((*size_use), (*to_use)))
		{
			ft_putstr_fd("Error\n", 2);
			ft_free((*to_use), (*size_use));
			return (0);
		}
	}
	else
	{
		(*to_use) = argv + 1;
		(*size_use) = argc - 1;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**to_use;
	int		size_use;

	if (!set_tab_use(argc, argv, &to_use, &size_use) || !size_use)
		exit(0);
	if (error_handling(size_use, to_use))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	initialise(&stack_a, &stack_b, to_use, size_use);
	if (ft_issort(stack_a))
		return (0);
	sorting(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	if (argc == 2)
		ft_free(to_use, size_use);
	return (0);
}
