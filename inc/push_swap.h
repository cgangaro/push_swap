/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:26:39 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/28 16:05:16 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

typedef struct	s_ps
{
	t_list		*a;
	t_list		*b;
}				t_ps;

void	error(t_list *a, t_list *b);

t_list	*create_list_a(t_list *a, t_list *b, char **argv, int argc);
void	create_list_a_verif(t_list *a, t_list *b, char **argv, int argc);
t_list	*create_list_a_guillemet(t_list *a, t_list *b, char **argv);
void	create_list_a_guillemet_verif(t_list *a, t_list *b, char **argv);
void	verif_double(t_list *a, t_list *b);

void	aff_list(t_list *lst, int num);
int		order(t_list *a);

t_ps	first(t_ps *ps);

t_ps	*tri_5(t_ps *ps);
t_ps	*tri_5_2(t_ps *ps);
t_ps	*tri_5_3(t_ps *ps);
t_ps	*tri_5_4(t_ps *ps);
t_ps	*tri_5_5(t_ps *ps);

t_ps	*to_100(t_ps *ps);
t_ps	*block(t_ps *ps, int min, int max);
t_ps	*repush_to_a(t_ps *ps);
int		val_max_list(t_list *lst);
int		move_top_or_bot(t_ps *ps, int min, int max);
int		search_nbr_block(t_ps *ps, int min, int max);
int		pos_block(t_list *lst, int n);
int		first_pos_block(t_ps *ps, int min, int max, int sens);

void	ft_lstadd_front(t_list **list, int valeur);
void	ft_lstadd_back(t_list **list, int valeur);
void	ft_lstclear(t_list **list);
void	ft_dellst_front(t_list **list);
void	ft_dellst_back(t_list **list);
int		ft_lstsize(t_list *lst);
int		ft_lstval(t_list *lst, int n);

t_ps	*sa(t_ps *ps);
t_ps	*sb(t_ps *ps);
t_ps	*ss(t_ps *ps);
t_ps	*pa(t_ps *ps);
t_ps	*pb(t_ps *ps);
t_ps	*ra(t_ps *ps);
t_ps	*rb(t_ps *ps);
t_ps	*rr(t_ps *ps);
t_ps	*rra(t_ps *ps);
t_ps	*rrb(t_ps *ps);
t_ps	*rrr(t_ps *ps);

void	ft_putstr_1(char *s);
void	ft_putchar_1(char s);
long long int	ft_atoi(const char *str);

#endif