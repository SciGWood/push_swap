/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:59:28 by gdetourn          #+#    #+#             */
/*   Updated: 2023/12/04 17:39:24 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* #include <stdio.h>

int	print_list(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("[%d]\n", tmp->nb);
		tmp = tmp->next;
	}
	return (0);
} */

int	main(int argc, char *argv[])
{
	t_stack	*a;

	a = ft_parse_args(argc, argv);
	if (!a || ft_ifdup(a))
		ft_error(a);
	if (!ft_stack_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			ft_sx(&a, 1);
		if (ft_lstsize(a) == 3)
			ft_sort_3elem(&a);
		if (ft_lstsize(a) > 3)
			ft_sort_mult(&a);
	}
	ft_lstclear_ps(&a);
	return (0);
}
