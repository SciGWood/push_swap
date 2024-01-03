/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:16:27 by gdetourn          #+#    #+#             */
/*   Updated: 2023/12/05 14:33:31 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_apply_ps_bis(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_ss(a, b, 3);
	else if (line[0] == 'r' && line[1] == 'r')
	{
		if (line[2] == '\n')
			ft_rr(a, b, 3);
		else if (line[2] == 'a' && line[3] == '\n')
			ft_rrx(a, 0);
		else if (line[2] == 'b' && line[3] == '\n')
			ft_rrx(b, 0);
		else if (line[2] == 'r' && line[3] == '\n')
			ft_rrr(a, b, 3);
	}
	else
	{
		ft_error(*a);
		ft_lstclear_ps(b);
	}
	return (0);
}

/* ft_apply_ps:
	line is obtained with GNL by reading stdin '0'.
	if read line is valid, corresponding movement is applied.*/
char	*ft_apply_ps(t_stack **a, t_stack **b, char *line)
{
	if (line[1] == 'a' && line[2] == '\n')
	{
		if (line[0] == 's')
			ft_sx(a, 0);
		if (line[0] == 'p')
			ft_pa(a, b, 0);
		if (line[0] == 'r')
			ft_rx(a, 0);
	}
	else if (line[1] == 'b' && line[2] == '\n')
	{
		if (line[0] == 's')
			ft_sx(b, 0);
		if (line[0] == 'p')
			ft_pb(a, b, 0);
		if (line[0] == 'r')
			ft_rx(b, 0);
	}
	else if ((line[0] == 'r' && line[1] == 'r')
		|| (line[0] == 's' && line[1] == 's'))
		ft_apply_ps_bis(a, b, line);
	else
		ft_apply_ps_bis(a, b, line);
	return (get_next_line(0));
}

/* ft_prog_test:
	Test of the push_swap program.
	line is obtained with GNL by reading stdin ('0').
	each line results in application of the indicated movement,
	through ft_apply_ps function.
	At the end, stack a should be sorted an stack b empty,
	if not --> 'KO';*/
int	ft_prog_test(t_stack **a, t_stack **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_apply_ps(a, b, line);
		free(tmp);
	}
	if (*b || !ft_stack_sorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = ft_parse_args(argc, argv);
	b = NULL;
	if (!a || ft_ifdup(a))
		ft_error(a);
	line = get_next_line(0);
	if (!line && ft_stack_sorted(a))
		write(1, "OK\n", 3);
	else if (!line && !ft_stack_sorted(a))
		write(1, "KO\n", 3);
	else
		ft_prog_test(&a, &b, line);
	ft_lstclear_ps(&a);
	ft_lstclear_ps(&b);
	return (0);
}
