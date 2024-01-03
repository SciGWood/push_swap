/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:48:51 by gdetourn          #+#    #+#             */
/*   Updated: 2023/11/16 11:25:02 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack *a)
{
	write(2, "Error\n", 6);
	if (a)
		ft_lstclear_ps(&a);
	exit(1);
}

void	ft_lstclear_ps(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nb = 0;
		free(*lst);
		*lst = tmp;
	}
}

void	ft_free_str(char **tab)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		tmp = tab[i];
		free(tmp);
		i++;
	}
	tab[i] = NULL;
}
