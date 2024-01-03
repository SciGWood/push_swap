/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:53:25 by gdetourn          #+#    #+#             */
/*   Updated: 2023/11/30 12:10:29 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_int_min(t_stack *a)
{
	int	i;

	i = 0;
	i = a->nb;
	while (a)
	{
		if (a->nb < i)
			i = a->nb;
		a = a->next;
	}
	return (i);
}

int	ft_int_max(t_stack *a)
{
	int	i;

	i = 0;
	i = a->nb;
	while (a)
	{
		if (a->nb > i)
			i = a->nb;
		a = a->next;
	}
	return (i);
}

int	ft_index(t_stack *a, int nb)
{
	int	index;

	index = 0;
	while (a->nb != nb)
	{
		index++;
		a = a->next;
	}
	return (index);
}

int	ft_future_place_b(t_stack *b, int nb)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	if (b->nb < nb && nb < ft_lstlast(b)->nb)
		i = 0;
	else if (nb < ft_int_min(b) || ft_int_max(b) < nb)
		i = ft_index(b, ft_int_max(b));
	else
	{
		tmp = b->next;
		while (b->nb < nb || nb < tmp->nb)
		{
			b = b->next;
			tmp = b->next;
			i++;
		}
	}
	return (i);
}

int	ft_future_place_a(t_stack *a, int nb)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	if (nb < a->nb && ft_lstlast(a)->nb < nb)
		i = 0;
	else if (nb < ft_int_min(a) || ft_int_max(a) < nb)
		i = ft_index(a, ft_int_min(a));
	else
	{
		tmp = a->next;
		while (nb < a->nb || tmp->nb < nb)
		{
			a = a->next;
			tmp = a->next;
			i++;
		}
	}
	return (i);
}
