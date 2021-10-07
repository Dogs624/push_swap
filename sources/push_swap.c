/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:00:59 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/07 10:59:51 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	initialise(t_stack **s_a, t_stack **s_b, char **args, int size)
{
	(*s_a) = ft_create_stack(size, args);
	if (!(*s_a))
		return (0);
	(*s_b) = ft_init_stack();
	if (!(*s_b))
	{
		ft_free_stack((*s_a));
		return (0);
	}
	return (1);
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
		if (!(*to_use))
			return (0);
		*size_use = ft_tabsize((*to_use));
		if (error_handling((*size_use), (*to_use)))
		{
			ft_putstr_fd("Error\n", 2);
			ft_free((*to_use), (*size_use));
			return (0);
		}
		return (2);
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
	int		malloc_argv;

	stack_a = NULL;
	stack_b = NULL;
	malloc_argv = set_tab_use(argc, argv, &to_use, &size_use);
	if (!malloc_argv || !size_use)
		return (0);
	if (error_handling(size_use, to_use))
	{
		ft_putstr_fd("Error\n", 2);
		return (ft_free_all(stack_a, stack_b, to_use, malloc_argv));
	}
	if (!initialise(&stack_a, &stack_b, to_use, size_use))
		ft_free_all(stack_a, stack_b, to_use, malloc_argv);
	if (ft_issort(stack_a))
		return (0);
	sorting(stack_a, stack_b);
	ft_free_all(stack_a, stack_b, to_use, malloc_argv);
	return (0);
}
