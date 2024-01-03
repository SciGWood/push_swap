/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:37:55 by gdetourn          #+#    #+#             */
/*   Updated: 2023/12/05 16:18:10 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* check_int:
	1. Check if an element in the tab is not a digit.*/
int	check_int(char	**tab, int flag)
{
	int	i;
	int	j;

	i = 0;
	if (flag == 1)
		i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]) && tab[i][j] != '-' && tab[i][j] != '+')
				return (1);
			if (tab[i][j] == '-' || tab[i][j] == '+')
			{
				if (!ft_isdigit(tab[i][j + 1]) || tab[i][j - 1] != '\0')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

/* ft_atoi_ps:
	Normal atoi + Error check:
	1. Check if arg is not a digit.
	2. Check if arg is an int and in the limits.*/
int	ft_atoi_ps(const char *str, t_stack *a)
{
	int				i;
	int				sign;
	long long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] == ' ') || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		ft_error(a);
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
		if ((res * sign) < -2147483648 || 2147483647 < (res * sign))
			ft_error(a);
	}
	return (res * sign);
}

/* ft_ifdup:
	1. Check if a nb in the stack is already present through a tmp.*/
int	ft_ifdup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nb == tmp->nb)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

/* ft_stack_sorted:
	1. Check if int in stack a are already sorted.*/
int	ft_stack_sorted(t_stack *a)
{
	long long int	nb;

	nb = a->nb;
	while (a)
	{
		if (nb > a->nb)
			return (0);
		nb = a->nb;
		a = a->next;
	}
	return (1);
}
