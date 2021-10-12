/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:34:53 by jvander-          #+#    #+#             */
/*   Updated: 2021/07/05 12:03:00 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*to_ret;
	size_t	s1_len;

	if (s1 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	to_ret = malloc(sizeof(char) * (s1_len + 1));
	if (to_ret == NULL)
		return (NULL);
	ft_memcpy(to_ret, s1, s1_len + 1);
	return (to_ret);
}
