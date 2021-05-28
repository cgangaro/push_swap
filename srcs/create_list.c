/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:46:37 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/28 16:21:40 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*create_list_a(t_list *a, t_list *b, char **argv, int argc)
{
	int	i;

	i = 1;
	if (argc == 2)
		a = create_list_a_guillemet(a, b, argv);
	else
	{
			create_list_a_verif(a, b, argv, argc);
		while (argc > i)
		{
			ft_lstadd_back(&a, ft_atoi(argv[i]));
			i++;
		}
	}
	return (a);
}

void	create_list_a_verif(t_list *a, t_list *b, char **argv, int argc)
{
	int i;
	int	j;

	i = 1;
	while (argc > i)
	{
		j = 0;
		while (argv[i][j] >= '0' && argv[i][j] <= '9')
			j++;
		if (argv[i][j] != '\0')
			error(a, b);
		i++;
	}
}

t_list	*create_list_a_guillemet(t_list *a, t_list *b, char **argv)
{
	int		i;
	int		j;
	char	str[12];

	create_list_a_guillemet_verif(a, b, argv);
	i = 0;
	while (argv[1][i] != '\0')
	{
		j = 0;
		str[0] = '\0';
		while (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			str[j] = argv[1][i];
			str[j + 1] = '\0';
			i++;
			j++;
		}
		if (str[0] != '\0')
			ft_lstadd_back(&a, ft_atoi(str));
		while (argv[1][i] == ' ')
			i++;
	}
	return (a);
}

void	create_list_a_guillemet_verif(t_list *a, t_list *b, char **argv)
{
	int i;

	i = 1;
	while (argv[1][i] != '\0')
	{
		if (!((argv[1][i] >= '0' && argv[1][i] <= '9') || argv[1][i] == ' '))
		{
			error(a, b);
		}
		i++;
	}
}

void	verif_double(t_list *a, t_list *b)
{
	t_list	*tmp;
	t_list	*actu;

	actu = a;
	while (actu->next != NULL)
	{
		tmp = actu->next;
		while (tmp->next != NULL)
		{
			if (tmp->content == actu->content)
			{
				error(a, b);
			}
			tmp = tmp->next;
		}
		if (tmp->content == actu->content)
				error(a, b);
		actu = actu->next;
	}
}