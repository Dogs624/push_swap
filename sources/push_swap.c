/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:00:59 by jvander-          #+#    #+#             */
/*   Updated: 2021/09/14 15:40:19 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*head;
	// (void)argv;
	// (void)head;
	// (void)argc;
	// printf("ARGC ==== %d\n", argc);

	head = ft_create_stack(argc, argv);
	ft_display_stack(head);
	ft_free_stack(head);
	check_leaks();
	return (0);
}
