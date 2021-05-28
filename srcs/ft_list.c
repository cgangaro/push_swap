/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:57:15 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/27 13:00:26 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_lstadd_front(t_list **list, int valeur)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		exit(-1);
	new->content = valeur;
	new->next = *list;
	*list = new;
}

void	ft_lstadd_back(t_list **list, int valeur)
{
	t_list *new;
	t_list *tmp;

	new = malloc(sizeof(*new));
	if (new == NULL)
		exit(-1);
	if (*list == NULL)
	{
		new->content = valeur;
		new->next = NULL;
		*list = new;
		return ;
	}
	else
	{
		new->content = valeur;
		new->next = NULL;
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_lstclear(t_list **list)
{
	t_list	*tmp;

	if (list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}

void	ft_dellst_front(t_list **list)
{
	t_list	*tmp;

	if (list == NULL)
		return ;
	tmp = (*list)->next;
	free(*list);
	*list = tmp;
}

void	ft_dellst_back(t_list **list)
{
	t_list	*tmp;
	t_list	*ptmp;

	if (*list == NULL)
		return ;
	if ((*list)->next == NULL)
	{
		free(*list);
		*list = NULL;
		return ;
	}
	tmp = *list;
	ptmp = *list;
	while (tmp->next != NULL)
	{
		ptmp = tmp;
		tmp = tmp->next;
	}
	ptmp->next = NULL;
	free(tmp);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	ft_lstval(t_list *lst, int n)
{
	int		i;

	i = 1;
	if (!lst)
		return (-1);
	while (n > i && lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	if (i == n)
		return (lst->content);
	return (-1);
}
