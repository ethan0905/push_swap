/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:47:40 by esafar            #+#    #+#             */
/*   Updated: 2021/10/26 11:50:03 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_error(long int *stack_a, int print)
{
	if (print > 0)
		ft_putstr_fd("Error\n", 2);
	free(stack_a);
	return (-1);
}

int	check_tab(long int *stack_a, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack_a[i] == stack_a[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	already_sorted(long int *stack_a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack_a[i] < stack_a[i + 1])
			i++;
		else if (!stack_a[i + 1])
			return (-1);
		else
			return (1);
	}
	return (-1);
}
