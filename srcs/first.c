/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 09:39:34 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/28 16:23:09 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_ps	first(t_ps *ps)
{
	int	taille;

	taille = ft_lstsize(ps->a);
	if (ft_lstsize(ps->a) == 1)
		exit(0);
	ps->b = NULL;
	if (ft_lstsize(ps->a) <= 5)
	 	tri_5(ps);
	ps = to_100(ps);
	//  printf("A\n");
	//  aff_list(ps->a, 1);
	// printf("B\n");
	// aff_list(ps->b, 2);
	return (*ps);
}

t_ps	*tri_5(t_ps *ps)
{
	if (ft_lstsize(ps->a) == 2)
		tri_5_2(ps);
	if (ft_lstsize(ps->a) == 3)
		tri_5_3(ps);
	if (ft_lstsize(ps->a) == 4)
	{
		pb(ps);
		tri_5_4(ps);
	}
	if (ft_lstsize(ps->a) == 5)
	{
		pb(ps);
		pb(ps);
		tri_5_5(ps);
	}
	return (ps);
}

t_ps	*tri_5_2(t_ps *ps)
{
	if (ps->a->content > ps->a->next->content)
		ra(ps);
	return (ps);
}

t_ps	*tri_5_3(t_ps *ps)
{
	int		n1;
	int		n2;
	int		n3;
	t_list	*tmp;

	n1 = ps->a->content;
	tmp = ps->a->next;
	n2 = tmp->content;
	tmp = tmp->next;
	n3 = tmp->content;
	if (n1 > n2 && n2 > n3)
	{
		sa(ps);
		rra(ps);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(ps);
	else if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(ps);
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(ps);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		rra(ps);
		sa(ps);
	}
	return (ps);
}

t_ps	*tri_5_4(t_ps *ps)
{
	tri_5_3(ps);
	if (ps->b->content < ps->a->content)
		pa(ps);
	else if (ps->b->content > ps->a->content && ps->b->content < ft_lstval(ps->a, 2))
	{
		pa(ps);
		sa(ps);
	}
	else if (ps->b->content > ft_lstval(ps->a, 2) && ps->b->content < ft_lstval(ps->a, 3))
	{
		rra(ps);
		pa(ps);
		ra(ps);
		ra(ps);
	}
	else
	{
		pa(ps);
		ra(ps);
	}
	return (ps);
}

t_ps	*tri_5_5(t_ps *ps)
{
	tri_5_4(ps);
	if (ps->b->content < ps->a->content)
		pa(ps);
	else if (ps->b->content > ps->a->content && ps->b->content < ft_lstval(ps->a, 2))
	{
		pa(ps);
		sa(ps);
	}
	else if (ps->b->content > ft_lstval(ps->a, 2) && ps->b->content < ft_lstval(ps->a, 3))
	{
		ra(ps);
		pa(ps);
		sa(ps);
		rra(ps);
	}
	else if (ps->b->content > ft_lstval(ps->a, 3) && ps->b->content < ft_lstval(ps->a, 4))
	{
		rra(ps);
		pa(ps);
		ra(ps);
		ra(ps);
	}
	else
	{
		pa(ps);
		ra(ps);
	}
	return (ps);
}