/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_push_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:03:55 by esafar            #+#    #+#             */
/*   Updated: 2021/11/03 14:45:59 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	special_push_a(long int *stack_a, long int *stack_b, int ac, int print)
{
	int	i;
	int	b;

	i = ac - 1;
	b = stack_b[0];
	if (stack_b[0] != 3000000000)
	{
		while (i >= 0)
		{
			stack_a[i + 1] = stack_a[i];
			if (i == 0)
				stack_a[0] = b;
			i--;
		}
		i = -1;
		while (++i < ac - 1)
		{
			stack_b[i] = stack_b[i + 1];
		}
		stack_b[i] = 3000000000;
		if (print == 1)
			ft_putstr_fd("pa\n", 1);
	}
}

void	special_push_b(long int *stack_a, long int *stack_b, int ac, int print)
{
	int	i;
	int	a;

	i = ac - 1;
	a = stack_a[0];
	if (stack_a[0] != 3000000000)
	{
		while (i >= 0)
		{
			stack_b[i + 1] = stack_b[i];
			if (i == 0)
				stack_b[0] = a;
			i--;
		}
		i = -1;
		while (++i < ac - 1)
		{
			stack_a[i] = stack_a[i + 1];
		}
		stack_a[i] = 3000000000;
		if (print == 1)
			ft_putstr_fd("pb\n", 1);
	}
}
