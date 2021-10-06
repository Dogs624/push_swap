/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:28:36 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:13 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

static t_node	*create_node(int data)
{
	t_node	*ret;

	ret = malloc(sizeof(t_node));
	if (!ret)
		return (NULL);
	ret->data = data;
	ret->index = -1;
	return (ret);
}

t_stack	*ft_create_stack(int argc, char **argv)
{
	t_stack	*ret;

	argc -= 1;
	ret = ft_init_stack();
	if (!ret)
		return (NULL);
	while (argc >= 0)
	{
		if (!ft_push(ret, create_node(ft_atoi(argv[argc--]))))
		{
			ft_free_stack(ret);
			return (NULL);
		}
	}
	ft_create_index(ret);
	ft_create_pos(ret);
	ret->initial_size = ft_stack_size(ret);
	return (ret);
}
