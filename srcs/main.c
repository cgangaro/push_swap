/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:08:43 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/28 16:24:35 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;
	
	ps.a = NULL;
	ps.b = NULL;
	if (argc < 2)
	 	error(ps.a, ps.b);
	ps.a = create_list_a(ps.a, ps.b, argv, argc);
	verif_double(ps.a, ps.b);
	//aff_list(ps.a, 1);
	if (order(ps.a) == 1)
		return (1);
	ps = first(&ps);
	//aff_list(ps.a, 2);
	return (0);
}

//ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG

void	error(t_list *a, t_list *b)
{
	ft_putstr_1("Error\n");
	ft_lstclear(&a);
	ft_lstclear(&b);
	exit(-1);
}

void	aff_list(t_list *lst, int num)
{
	t_list	*tmp;
	
	if (lst == NULL)
	{
		printf("liste %d vide\n", num);
		return ;
	}
	printf("|%d|\n", num);
	tmp = lst;
	while (tmp->next != NULL)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->content);
	printf("|FIN %d|\n", num);
}

int	order(t_list *a)
{
	int p;

	p = a->content;
	while (a->next != NULL)
	{
		a = a->next;
		if (p > a->content)
			return (0);
		p = a->content;
	}
	if (p > a->content)
		return (0);
	//printf("Deja dans l'ordre\n");
	return (1);
}

