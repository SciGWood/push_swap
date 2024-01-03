/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_to_make.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:23:43 by gdetourn          #+#    #+#             */
/*   Updated: 2023/11/30 17:10:19 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* When cheapest number found, movements required applied.
	ft_make_rarb:
	Apply	rr (both ra and rb)	or ra	or rb	or NOTHING
	Then pb or pa.*/
int	ft_make_rarb(t_stack **a, t_stack **b, int nb, char c)
{
	if (c == 'a')
	{
		while ((*a)->nb != nb && ft_future_place_b(*b, nb) > 0)
			ft_rr(a, b, 0);
		while ((*a)->nb != nb)
			ft_rx(a, 1);
		while (ft_future_place_b(*b, nb) > 0)
			ft_rx(b, 2);
		ft_pb(a, b, 2);
	}
	else if (c == 'b')
	{
		while ((*b)->nb != nb && ft_future_place_a(*a, nb) > 0)
			ft_rr(a, b, 0);
		while ((*b)->nb != nb)
			ft_rx(b, 2);
		while (ft_future_place_a(*a, nb) > 0)
			ft_rx(a, 1);
		ft_pa(a, b, 1);
	}
	return (-1);
}

/* ft_make_rrarrb:
	Apply	rrr (both rra and rrb)	or rra	or rrb	or NOTHING
	Then pb or pa.*/
int	ft_make_rrarrb(t_stack **a, t_stack **b, int nb, char c)
{
	if (c == 'a')
	{
		while ((*a)->nb != nb && ft_future_place_b(*b, nb) > 0)
			ft_rrr(a, b, 0);
		while ((*a)->nb != nb)
			ft_rrx(a, 1);
		while (ft_future_place_b(*b, nb) > 0)
			ft_rrx(b, 2);
		ft_pb(a, b, 2);
	}
	else if (c == 'b')
	{
		while ((*b)->nb != nb && ft_future_place_a(*a, nb) > 0)
			ft_rrr(a, b, 0);
		while ((*b)->nb != nb)
			ft_rrx(b, 2);
		while (ft_future_place_a(*a, nb) > 0)
			ft_rrx(a, 1);
		ft_pa(a, b, 1);
	}
	return (-1);
}

/* ft_make_rarrb:
	Apply	ra	or rrb	or NOTHING
	Then pb or pa.*/
int	ft_make_rarrb(t_stack **a, t_stack **b, int nb, char c)
{
	if (c == 'a')
	{
		while ((*a)->nb != nb)
			ft_rx(a, 1);
		while (ft_future_place_b(*b, nb) > 0)
			ft_rrx(b, 2);
		ft_pb(a, b, 2);
	}
	else if (c == 'b')
	{
		while (ft_future_place_a(*a, nb) > 0)
			ft_rx(a, 1);
		while ((*b)->nb != nb)
			ft_rrx(b, 2);
		ft_pa(a, b, 1);
	}
	return (-1);
}

/* ft_make_rrarb:
	Apply	rra	or rb	or NOTHING
	Then pb or pa.*/
int	ft_make_rrarb(t_stack **a, t_stack **b, int nb, char c)
{
	if (c == 'a')
	{
		while ((*a)->nb != nb)
			ft_rrx(a, 1);
		while (ft_future_place_b(*b, nb) > 0)
			ft_rx(b, 2);
		ft_pb(a, b, 2);
	}
	else if (c == 'b')
	{
		while (ft_future_place_a(*a, nb) > 0)
			ft_rrx(a, 1);
		while ((*b)->nb != nb)
			ft_rx(b, 2);
		ft_pa(a, b, 1);
	}
	return (-1);
}
