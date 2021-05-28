/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 09:07:21 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/27 13:26:26 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_ps	*sa(t_ps *ps)
{
	int	tmp;

	tmp = ps->a->content;
	ps->a->content = ps->a->next->content;
	ps->a->next->content = tmp;
	ft_putstr_1("sa\n");
	return (ps);
}

t_ps	*sb(t_ps *ps)
{
	int	tmp;

	tmp = ps->b->content;
	ps->b->content = ps->b->next->content;
	ps->b->next->content = tmp;
	ft_putstr_1("sb\n");
	return (ps);
}

t_ps	*ss(t_ps *ps)
{
	t_list	*tmp;

	tmp = ps->a->next;
	ps->a->next = tmp->next;
	tmp->next = ps->a;
	tmp = ps->b->next;
	ps->b->next = tmp->next;
	tmp->next = ps->b;
	ft_putstr_1("ss\n");
	return (ps);
}

t_ps	*pa(t_ps *ps)
{
	if (ps->b != NULL)
	{
		ft_lstadd_front(&ps->a, ps->b->content);
		ft_dellst_front(&ps->b);
	}
	ft_putstr_1("pa\n");
	return (ps);
}

t_ps	*pb(t_ps *ps)
{
	if (ps->a != NULL)
	{
		ft_lstadd_front(&ps->b, ps->a->content);
		ft_dellst_front(&ps->a);
	}
	ft_putstr_1("pb\n");
	return (ps);
}

t_ps	*ra(t_ps *ps)
{
	ft_lstadd_back(&ps->a, ps->a->content);
	ft_dellst_front(&ps->a);
	ft_putstr_1("ra\n");
	return (ps);
}

t_ps	*rb(t_ps *ps)
{
	ft_lstadd_back(&ps->b, ps->b->content);
	ft_dellst_front(&ps->b);
	ft_putstr_1("rb\n");
	return (ps);
}

t_ps	*rr(t_ps *ps)
{
	ft_lstadd_back(&ps->a, ps->a->content);
	ft_dellst_front(&ps->a);
	ft_lstadd_back(&ps->b, ps->b->content);
	ft_dellst_front(&ps->b);
	ft_putstr_1("rr\n");
	return (ps);
}

t_ps	*rra(t_ps *ps)
{
	t_list	*tmp;
	tmp = ps->a;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	ft_lstadd_front(&ps->a, tmp->content);
	ft_dellst_back(&ps->a);
	ft_putstr_1("rra\n");
	return (ps);
}

t_ps	*rrb(t_ps *ps)
{
	t_list	*tmp;
	tmp = ps->b;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	ft_lstadd_front(&ps->b, tmp->content);
	ft_dellst_back(&ps->b);
	ft_putstr_1("rrb\n");
	return (ps);
}

t_ps	*rrr(t_ps *ps)
{
	ps = rra(ps);
	ps = rra(ps);
	ft_putstr_1("rrr\n");
	return (ps);
}
