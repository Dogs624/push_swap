/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:09:16 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/12 12:17:48 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_arg(char **argv, int size_ret, int size_use, char **to_ret)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	size_ret = 0;
	to_ret[size_use] = NULL;
	while (argv[i])
	{
		j = -1;
		tmp = ft_split(argv[i++], ' ');
		if (!tmp)
			return (NULL);
		while (tmp[++j])
		{
			to_ret[size_ret] = ft_strjoin(NULL, tmp[j]);
			if (!to_ret[size_ret++])
				return (NULL);
		}
		ft_free(tmp, ft_tabsize(tmp));
	}
	return (to_ret);
}
