/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_possibilities_ba.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:44:35 by gdetourn          #+#    #+#             */
/*   Updated: 2023/11/30 17:03:15 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Push back from stack B to stack A.
	ft_if_rarb_ba:
	calculates the number of rotations required for ra and/or rb.*/
int	ft_if_rarb_ba(t_stack *a, t_stack *b, int nb)
{
	int	i;

	i = 0;
	i = ft_future_place_a(a, nb);
	if (i < ft_index(b, nb))
		i = ft_index(b, nb);
	return (i);
}

/* ft_if_rrarrb_ba:
	calculates the number of rotations required for rra and/or rrb.*/
int	ft_if_rrarrb_ba(t_stack *a, t_stack *b, int nb)
{
	int	i;

	i = 0;
	if (ft_future_place_a(a, nb))
		i = ft_lstsize(a) - ft_future_place_a(a, nb);
	if ((i < (ft_lstsize(b) - ft_index(b, nb))) && ft_index(b, nb))
		i = ft_lstsize(b) - ft_index(b, nb);
	return (i);
}

/* ft_if_rarrb_ba:
	calculates the number of rotations required for ra and/or rrb.*/
int	ft_if_rarrb_ba(t_stack *a, t_stack *b, int nb)
{
	int	i;

	i = 0;
	if (ft_index(b, nb))
		i = ft_lstsize(b) - ft_index(b, nb);
	i = ft_future_place_a(a, nb) + i;
	return (i);
}

/* ft_if_rrarb_ba:
	calculates the number of rotations required for rra and/or rb.*/
int	ft_if_rrarb_ba(t_stack *a, t_stack *b, int nb)
{
	int	i;

	i = 0;
	if (ft_future_place_a(a, nb))
		i = ft_lstsize(a) - ft_future_place_a(a, nb);
	i = ft_index(b, nb) + i;
	return (i);
}
