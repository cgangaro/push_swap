/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:28:43 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/28 16:05:48 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_ps	*to_100(t_ps *ps)
{
	int	portion;
	int	min;
	int	max;
	int	max_list;

	max_list = val_max_list(ps->a);
	portion =  max_list / 5;
	ps = block(ps, 0, portion);
	min = portion + 1;
	max = (min - 1) + portion;
	ps = block(ps, min, max);
	min = max + 1;
	max = (min - 1) + portion;
	ps = block(ps, min, max);
	min = max + 1;
	max = (min - 1) + portion;
	ps = block(ps, min, max);
	min = max + 1;
	max = (min - 1) + portion;
	ps = block(ps, min, max_list);
	ps = repush_to_a(ps);
	return (ps);
}

t_ps	*repush_to_a(t_ps *ps)
{
	int	val_max;
	int	mid;
	int	pos;
	
	while (ps->b != NULL)
	{
		val_max = val_max_list(ps->b);
		mid = ft_lstsize(ps->b) / 2;
		pos = pos_block(ps->b, val_max);
		while (ps->b->content != val_max)
		{
			if (pos <= mid)
				rb(ps);
			if (pos > mid)
				rrb(ps);
		}
		pa(ps);
	}
	return (ps);
}

int		val_max_list(t_list *lst)
{
	t_list	*tmp;
	int		val_max;

	if (lst == NULL)
		return (-1);
	tmp = lst;
	val_max = 0;
	while (tmp->next != NULL)
	{
		if (tmp->content > val_max)
			val_max = tmp->content;
		tmp = tmp->next;
	}
	if (tmp->content > val_max)
			val_max = tmp->content;
	return (val_max);
}

t_ps	*block(t_ps *ps, int min, int max)
{
	while (search_nbr_block(ps, min, max) > 0)
	{
		if (move_top_or_bot(ps, min, max) == 0)
		{
			while (ps->a->content < min || ps->a->content > max)
				ra(ps);
			pb(ps);
		}
		else
		{
			while (ps->a->content < min || ps->a->content > max)
				rra(ps);
			pb(ps);
		}
	}
	return (ps);
}

int		move_top_or_bot(t_ps *ps, int min, int max)
{
	int		top;
	int		bot;

	top = first_pos_block(ps, min, max, 0);
	bot = (ft_lstsize(ps->a) - first_pos_block(ps, min, max, 1)) + 1;
	if (top > bot || top == -1)
		return (1);
	return (0);
}

int		search_nbr_block(t_ps *ps, int min, int max)
{
	t_list	*tmp;
	int		n;

	if (ps->a == NULL)
		return (-1);
	tmp = ps->a;
	n = 0;
	while (tmp->next != NULL)
	{
		if (tmp->content >= min && tmp->content <= max)
			n++;
		tmp = tmp->next;
	}
	if (tmp->content >= min && tmp->content <= max)
			n++;
	return (n);
}

int		pos_block(t_list *lst, int n)
{
	int	pos;
	t_list	*tmp;

	pos = 0;
	tmp = lst;
	while (tmp->next != NULL)
	{
		if (tmp->content == n)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	if (tmp->content == n)
			return (pos);
	return (-1);
}

int		first_pos_block(t_ps *ps, int min, int max, int sens)
{
	t_list	*tmp;
	int		i;
	int		old;
	int		mid;

	mid = ft_lstsize(ps->a) / 2;
	tmp = ps->a;
	old = 0;
	i = 0;
	if (sens == 0)
	{
		while (tmp->next != NULL && i <= mid)
		{
			if (tmp->content >= min && tmp->content <= max)
				return (i);
			i++;
		}
		return (-1);
	}
	else if (sens == 1)
	{
		while (tmp->next != NULL)
		{
			if (tmp->content >= min && tmp->content <= max)
				old = i;
			i++;
			tmp = tmp->next;
		}
		if (old > mid)
			return (i);
		return (-1);
	}
	return (-1);
}