/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:25:21 by gdetourn          #+#    #+#             */
/*   Updated: 2023/12/05 16:27:05 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ft_split_arg1:
	1. If only 1 argument --> split then put in stack.*/
t_stack	*ft_split_arg1(char *argv[])
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	j = 0;
	tmp = ft_split(argv[1], ' ');
	if (check_int(tmp, 0) == 1)
	{
		ft_free_str(tmp);
		free(tmp);
		ft_error(a);
	}
	while (tmp[i])
	{
		j = ft_atoi_ps(tmp[i], a);
		ft_add_back(&a, ft_lstnew(j));
		i++;
	}
	ft_free_str(tmp);
	free(tmp);
	return (a);
}

/* ft_parse_args:
	1. Check number of arguments.*/
t_stack	*ft_parse_args(int argc, char *argv[])
{
	int		i;
	int		j;
	t_stack	*a;

	i = 1;
	j = 0;
	a = NULL;
	if (argc < 2)
		exit(1);
	if (argc == 2)
		a = ft_split_arg1(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi_ps(argv[i], a);
			ft_add_back(&a, ft_lstnew(j));
			i++;
		}
		if (check_int(argv, 1) == 1)
			ft_error(a);
	}
	return (a);
}

int	ft_sort_3elem(t_stack **a)
{
	if (ft_int_min(*a) == (*a)->nb)
	{
		ft_rrx(a, 1);
		ft_sx(a, 1);
		if (ft_stack_sorted(*a))
			return (0);
	}
	else if (ft_int_max(*a) == (*a)->nb)
	{
		ft_rx(a, 1);
		if (!ft_stack_sorted(*a))
			ft_sx(a, 1);
	}
	else
	{
		if (ft_index(*a, ft_int_max(*a)) == 1)
			ft_rrx(a, 1);
		else
			ft_sx(a, 1);
	}
	return (0);
}
