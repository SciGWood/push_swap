/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:02:23 by gdetourn          #+#    #+#             */
/*   Updated: 2023/12/05 16:18:27 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>

/* # include <stdio.h> */
typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}					t_stack;

/* int	print_list(t_stack *lst); */
/*checker.c*/
int		ft_apply_ps_bis(t_stack **a, t_stack **b, char *line);
char	*ft_apply_ps(t_stack **a, t_stack **b, char *line);
int		ft_prog_test(t_stack **a, t_stack **b, char *line);

/*get_next_line_utils.c*/
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, char *src, size_t size);

/*get_next_line.c*/
char	*ft_next_line(char *stash);
char	*ft_get_line(char *stash);
char	*ft_strjoin_and_free(char *s1, char *s2);
char	*ft_read_text(int fd, char *stash);
char	*get_next_line(int fd);

/*ft_cases_possibilities_ab.c*/
int		ft_if_rarb_ab(t_stack *a, t_stack *b, int nb);
int		ft_if_rrarrb_ab(t_stack *a, t_stack *b, int nb);
int		ft_if_rarrb_ab(t_stack *a, t_stack *b, int nb);
int		ft_if_rrarb_ab(t_stack *a, t_stack *b, int nb);

/*ft_cases_possibilities_ba.c*/
int		ft_if_rarb_ba(t_stack *a, t_stack *b, int nb);
int		ft_if_rrarrb_ba(t_stack *a, t_stack *b, int nb);
int		ft_if_rarrb_ba(t_stack *a, t_stack *b, int nb);
int		ft_if_rrarb_ba(t_stack *a, t_stack *b, int nb);

/*ft_cases_to_make.c*/
int		ft_make_rarb(t_stack **a, t_stack **b, int nb, char c);
int		ft_make_rrarrb(t_stack **a, t_stack **b, int nb, char c);
int		ft_make_rarrb(t_stack **a, t_stack **b, int nb, char c);
int		ft_make_rrarb(t_stack **a, t_stack **b, int nb, char c);

/*ft_cheapest_number*/
int		ft_cheapest_ab(t_stack *a, t_stack *b);
int		ft_cheapest_ba(t_stack *a, t_stack *b);

/*ft_error_and_free.c*/
void	ft_error(t_stack *a);
void	ft_lstclear_ps(t_stack **lst);
void	ft_free_str(char **tab);

/*ft_move_01.c*/
int		ft_sx(t_stack **a, int print);
int		ft_rx(t_stack **a, int print);
int		ft_rrx(t_stack **a, int print);
int		ft_pa(t_stack **a, t_stack **b, int print);
int		ft_pb(t_stack **a, t_stack **b, int print);

/*ft_move_02.c*/
int		ft_ss(t_stack **a, t_stack **b, int print);
int		ft_rr(t_stack **a, t_stack **b, int print);
int		ft_rrr(t_stack **a, t_stack **b, int print);

/*ft_parsing.c*/
t_stack	*ft_split_arg1(char *argv[]);
t_stack	*ft_parse_args(int argc, char *argv[]);
int		ft_sort_3elem(t_stack **a);

/*ft_sort_mult.c*/
int		ft_push_b_until3(t_stack **a, t_stack **b);
t_stack	**ft_sort_a(t_stack **a, t_stack **b);
t_stack	*ft_sort_b(t_stack **a);
int		ft_sort_mult(t_stack **a);

/*ft_split.c*/
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);

/*ft_utils_01.c*/
int		check_int(char	**tab, int flag);
int		ft_isdigit(int c);
int		ft_atoi_ps(const char *str, t_stack *a);
int		ft_ifdup(t_stack *a);
int		ft_stack_sorted(t_stack *a);

/*ft_utils_02.c*/
int		ft_int_min(t_stack *a);
int		ft_int_max(t_stack *a);
int		ft_index(t_stack *a, int nb);
int		ft_future_place_b(t_stack *b, int nb);
int		ft_future_place_a(t_stack *a, int nb);

/*ft_utils_lst.c*/
t_stack	*ft_lstnew(int nb);
void	ft_add_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);

#endif