/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:06:57 by esafar            #+#    #+#             */
/*   Updated: 2021/11/03 14:15:04 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_intlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
		if (i > 11)
			return (-1);
	}
	return (1);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	i = 0;
	while (str[i])
		i++;
	if (i == 0)
		return (-1);
	return (1);
}

int	check_if_only_numbers(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_number(av[i]) < 0 || ft_atoi(av[i]) > 2147483647
			|| ft_atoi(av[i]) < -2147483648 || ft_intlen(av[i]) < 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] == 0 && s2[i] == 0)
		return (1);
	return (0);
}
