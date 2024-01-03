/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:08:25 by gdetourn          #+#    #+#             */
/*   Updated: 2023/12/05 10:43:22 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ss(t_stack **a, t_stack **b, int print)
{
	ft_sx(a, print);
	ft_sx(b, print);
	if (print == 0)
		write(1, "ss\n", 3);
	return (0);
}

int	ft_rr(t_stack **a, t_stack **b, int print)
{
	ft_rx(a, print);
	ft_rx(b, print);
	if (print == 0)
		write(1, "rr\n", 3);
	return (0);
}

int	ft_rrr(t_stack **a, t_stack **b, int print)
{
	ft_rrx(a, print);
	ft_rrx(b, print);
	if (print == 0)
		write(1, "rrr\n", 4);
	return (0);
}
