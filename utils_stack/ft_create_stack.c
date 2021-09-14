/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:28:36 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/14 15:29:22 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/push_swap.h"

t_stack	*ft_create_stack(int argc, char **argv)
{
	t_stack	*ret;
	int		i;

	i = argc - 1;
	ret = malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	ret->first = NULL;
	while ((i) >= 1)
	{
		if(!ft_push(ret, ft_atoi(argv[i])))
		{
			ft_free_stack(ret);
			return (NULL);
		}
		i--;
	}
	return (ret);
}
