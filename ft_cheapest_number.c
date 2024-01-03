/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheapest_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:53:34 by gdetourn          #+#    #+#             */
/*   Updated: 2023/11/30 17:24:22 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Cheapest number to move from	 a to b (ab) 	or 		b to a (ba)
	Calculates possible movements for each nb in stack (a or b)
		with cases_possibilities.c*/
int	ft_cheapest_ab(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = 0;
	i = ft_if_rrarrb_ab(a, b, a->nb);
	while (tmp)
	{
		if (i > ft_if_rarb_ab(a, b, tmp->nb))
			i = ft_if_rarb_ab(a, b, tmp->nb);
		if (i > ft_if_rrarrb_ab(a, b, tmp->nb))
			i = ft_if_rrarrb_ab(a, b, tmp->nb);
		if (i > ft_if_rarrb_ab(a, b, tmp->nb))
			i = ft_if_rarrb_ab(a, b, tmp->nb);
		if (i > ft_if_rrarb_ab(a, b, tmp->nb))
			i = ft_if_rrarb_ab(a, b, tmp->nb);
		tmp = tmp->next;
	}
	return (i);
}

int	ft_cheapest_ba(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		i;

	tmp = b;
	i = 0;
	i = ft_if_rrarrb_ba(a, b, b->nb);
	while (tmp)
	{
		if (i > ft_if_rarb_ba(a, b, tmp->nb))
			i = ft_if_rarb_ba(a, b, tmp->nb);
		if (i > ft_if_rrarrb_ba(a, b, tmp->nb))
			i = ft_if_rrarrb_ba(a, b, tmp->nb);
		if (i > ft_if_rarrb_ba(a, b, tmp->nb))
			i = ft_if_rarrb_ba(a, b, tmp->nb);
		if (i > ft_if_rrarb_ba(a, b, tmp->nb))
			i = ft_if_rrarb_ba(a, b, tmp->nb);
		tmp = tmp->next;
	}
	return (i);
}
