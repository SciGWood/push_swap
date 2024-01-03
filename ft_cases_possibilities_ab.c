/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_possibilities_ab.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:03:26 by gdetourn          #+#    #+#             */
/*   Updated: 2023/11/30 17:31:10 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Push from stack A to stack B.
	ft_if_rarb_ab:
	calculates the number of rotations required for ra and/or rb.*/
int	ft_if_rarb_ab(t_stack *a, t_stack *b, int nb)
{
	int	i;

	i = 0;
	i = ft_future_place_b(b, nb);
	if (i < ft_index(a, nb))
		i = ft_index(a, nb);
	return (i);
}

/* ft_if_rrarrb_ab:
	calculates the number of rotations required for rra and/or rrb.*/
int	ft_if_rrarrb_ab(t_stack *a, t_stack *b, int nb)
{
	int	i;

	i = 0;
	if (ft_future_place_b(b, nb))
		i = ft_lstsize(b) - ft_future_place_b(b, nb);
	if ((i < (ft_lstsize(a) - ft_index(a, nb))) && ft_index(a, nb))
		i = ft_lstsize(a) - ft_index(a, nb);
	return (i);
}

/* ft_if_rarrb_ab:
	calculates the number of rotations required for ra and/or rrb.*/
int	ft_if_rrarb_ab(t_stack *a, t_stack *b, int nb)
{
	int	i;

	i = 0;
	if (ft_index(a, nb))
		i = ft_lstsize(a) - ft_index(a, nb);
	i = ft_future_place_b(b, nb) + i;
	return (i);
}

/* ft_if_rrarb_ab:
	calculates the number of rotations required for rra and/or rb.*/
int	ft_if_rarrb_ab(t_stack *a, t_stack *b, int nb)
{
	int	i;

	i = 0;
	if (ft_future_place_b(b, nb))
		i = ft_lstsize(b) - ft_future_place_b(b, nb);
	i = ft_index(a, nb) + i;
	return (i);
}
