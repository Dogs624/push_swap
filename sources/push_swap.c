/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:00:59 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/12 15:14:22 by jvander-         ###   ########.fr       */
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

static char	**parsing_argv(char **argv, int *size_use)
{
	char	**tmp;
	int		i;
	int		size_ret;
	char	**to_ret;

	size_ret = 0;
	i = 0;
	while (argv[i])
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (NULL);
		size_ret += ft_tabsize(tmp);
		if (!ft_tabsize(tmp))
			return (ft_free(tmp, ft_tabsize(tmp)));
		i++;
		ft_free(tmp, ft_tabsize(tmp));
	}
	(*size_use) = size_ret;
	to_ret = malloc(sizeof(char *) * (size_ret) + 1);
	if (!to_ret)
		return (NULL);
	return (split_arg(argv, size_ret, (*size_use), to_ret));
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
			ft_free((*to_use), (*size_use));
			ft_putstr_fd("Error\n", 2);
		}
	}
	else
	{
		(*to_use) = argv + 1;
		(*size_use) = argc - 1;
		(*to_use) = parsing_argv((*to_use), size_use);
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
	if (argc <= 1)
		return (0);
	malloc_argv = set_tab_use(argc, argv, &to_use, &size_use);
	if (!to_use || !malloc_argv || !size_use
		|| error_handling(size_use, to_use))
	{
		ft_putstr_fd("Error\n", 2);
		return (ft_free_all(stack_a, stack_b, to_use));
	}
	if (!initialise(&stack_a, &stack_b, to_use, size_use))
		return (ft_free_all(stack_a, stack_b, to_use));
	if (ft_issort(stack_a))
		return (ft_free_all(stack_a, stack_b, to_use));
	sorting(stack_a, stack_b);
	return (ft_free_all(stack_a, stack_b, to_use));
}
