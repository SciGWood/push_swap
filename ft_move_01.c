/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:59:12 by gdetourn          #+#    #+#             */
/*   Updated: 2023/11/30 14:38:21 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sx(t_stack **a, int print)
{
	t_stack	*swap;

	if (!*a || !(*a)->next)
		return (1);
	swap = *a;
	*a = (*a)->next;
	swap->next = (*a)->next;
	(*a)->next = swap;
	if (print == 1)
		write(1, "sa\n", 3);
	if (print == 2)
		write(1, "sb\n", 3);
	return (0);
}

int	ft_rx(t_stack **a, int print)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return (1);
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (print == 1)
		write(1, "ra\n", 3);
	if (print == 2)
		write(1, "rb\n", 3);
	return (0);
}

int	ft_rrx(t_stack **a, int print)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (!*a || !(*a)->next)
		return (1);
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (print == 1)
		write(1, "rra\n", 4);
	if (print == 2)
		write(1, "rrb\n", 4);
	return (0);
}

int	ft_pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (print == 1)
		write(1, "pa\n", 3);
	return (0);
}

int	ft_pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	if (print == 2)
		write(1, "pb\n", 3);
	return (0);
}
