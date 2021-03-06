/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:11:17 by esafar            #+#    #+#             */
/*   Updated: 2021/11/03 14:16:41 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

int	main(int ac, char **av)
{
	int			i;
	long int	*stack_a;
	long int	*stack_b;

	if (check_if_only_numbers(ac, av) < 0)
		return (-1);
	stack_a = (long int *)malloc(sizeof(long int) * (ac + 1));
	if (!stack_a)
		return (-1);
	b_pas_zero(stack_a, ac);
	i = -1;
	while (++i < ac - 1)
		stack_a[i] = ft_atoi(av[i + 1]);
	if (check_tab(stack_a, (ac - 1)) == -1)
		return (ft_error(stack_a, 1));
	else if (ac == 1 || ac == 2 || already_sorted(stack_a, (ac - 1)) == -1)
		return (ft_error(stack_a, 0));
	stack_b = (long int *)malloc(sizeof(long int) * (ac + 1));
	if (!stack_b)
		return (free_(stack_a));
	b_pas_zero(stack_b, ac);
	solve(stack_a, stack_b, ac);
	return (double_free(stack_a, stack_b));
}
