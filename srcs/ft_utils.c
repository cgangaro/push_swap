/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:00:13 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/26 17:04:39 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_putchar_1(char s)
{
	write(1, &s, 1);
}

void	ft_putstr_1(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar_1(s[i]);
		i++;
	}
}

int				ft_annexe2(const char *str, int i)
{
	while (str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == ' ')
		i++;
	return (i);
}

long long int	ft_atoi(const char *str)
{
	long long int	val;
	int				i;
	int				neg;

	i = 0;
	val = 0;
	neg = 1;
	i = ft_annexe2(str, i);
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		val = val * 10 + (str[i] - 48);
		if (val > 9223372036854775807 && neg > 0)
			return (-1);
		else if (val < -9223372036854775807)
			return (0);
		i++;
	}
	return (val * neg);
}