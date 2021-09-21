/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:56:14 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/21 09:26:32 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (!str[i])
		return (1);
	return (0);
}

static int	all_number(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_check_long(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) >= INT_MAX
			|| ft_atoi(argv[i]) <= INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	error_handling(int argc, char **argv)
{
	if (argc <= 1)
		return (1);
	if (!all_number(argc, argv))
		return (1);
	if (ft_duplicate(argc, argv))
		return (1);
	if (!ft_check_long(argc, argv))
		return (1);
	return (0);
}
