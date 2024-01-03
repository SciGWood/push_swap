/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:03:55 by gdetourn          #+#    #+#             */
/*   Updated: 2023/11/30 14:34:00 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ft_push_b_until3:
	To find the cheapest number to push into b:
	Calculates possible movements for each nb in stack a:
		--> cases_possibilities.c "ft_if"
	Then apply movements for the cheapest number:
		--> cases_to_make.c "ft_make" + pb
	Until 3 numbers left in a.*/
int	ft_push_b_until3(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	while (ft_lstsize(*a) > 3 && !ft_stack_sorted(*a))
	{
		tmp = *a;
		i = ft_cheapest_ab(*a, *b);
		while (i >= 0)
		{
			if (i == ft_if_rarb_ab(*a, *b, tmp->nb))
				i = ft_make_rarb(a, b, tmp->nb, 'a');
			else if (i == ft_if_rrarrb_ab(*a, *b, tmp->nb))
				i = ft_make_rrarrb(a, b, tmp->nb, 'a');
			else if (i == ft_if_rarrb_ab(*a, *b, tmp->nb))
				i = ft_make_rarrb(a, b, tmp->nb, 'a');
			else if (i == ft_if_rrarb_ab(*a, *b, tmp->nb))
				i = ft_make_rrarb(a, b, tmp->nb, 'a');
			else
				tmp = tmp->next;
		}
	}
	return (0);
}

/* ft_sort_a:
	Only 3 nb sorted left in stack a.
	Push back from stack b to stack a in increasing order
	but still with the cheapest number to push back,
	until stack b is empty.*/
t_stack	**ft_sort_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	while (*b)
	{
		tmp = *b;
		i = ft_cheapest_ba(*a, *b);
		while (i >= 0)
		{
			if (i == ft_if_rarb_ba(*a, *b, tmp->nb))
				i = ft_make_rarb(a, b, tmp->nb, 'b');
			else if (i == ft_if_rrarrb_ba(*a, *b, tmp->nb))
				i = ft_make_rrarrb(a, b, tmp->nb, 'b');
			else if (i == ft_if_rarrb_ba(*a, *b, tmp->nb))
				i = ft_make_rarrb(a, b, tmp->nb, 'b');
			else if (i == ft_if_rrarb_ba(*a, *b, tmp->nb))
				i = ft_make_rrarb(a, b, tmp->nb, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (a);
}

/* ft_sort_b:
	Create stack b.
	Push into b in decreasing order until 3 numbers left in a.
	Then sort stack a.*/
t_stack	*ft_sort_b(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (ft_lstsize(*a) > 3 && !ft_stack_sorted(*a))
		ft_pb(a, &b, 2);
	if (ft_lstsize(*a) > 3 && !ft_stack_sorted(*a))
		ft_pb(a, &b, 2);
	if (ft_lstsize(*a) > 3 && !ft_stack_sorted(*a))
		ft_push_b_until3(a, &b);
	if (!ft_stack_sorted(*a))
		ft_sort_3elem(a);
	return (b);
}

int	ft_sort_mult(t_stack **a)
{
	t_stack	*b;
	int		i;

	b = NULL;
	b = ft_sort_b(a);
	a = ft_sort_a(a, &b);
	i = ft_index(*a, ft_int_min(*a));
	if (i < ft_lstsize(*a) - i)
	{
		while ((*a)->nb != ft_int_min(*a))
			ft_rx(a, 1);
	}
	else
		while ((*a)->nb != ft_int_min(*a))
			ft_rrx(a, 1);
	return (0);
}
