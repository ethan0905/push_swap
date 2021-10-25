/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:00:46 by esafar            #+#    #+#             */
/*   Updated: 2021/10/25 12:40:20 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_b(long int *stack_a, long int *stack_b, int ac, int print)
{
	int	i;

	i = ac - 1;
	while (i >= 0)
	{
		stack_b[i + 1] = stack_b[i];
		if (i == 0)
			stack_b[0] = stack_a[0];
		i--;
	}
	i = 0;
	while (i < ac - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = 3000000000;
	if (print == 1)
		ft_putstr_fd("pb\n", 1);
}

void	push_a(long int *stack_a, long int *stack_b, int ac, int print)
{
	int	i;

	i = ac - 1;
	while (i >= 0)
	{
		stack_a[i + 1] = stack_a[i];
		if (i == 0)
			stack_a[0] = stack_b[0];
		i--;
	}
	i = 0;
	while (i < ac - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i] = 3000000000;
	if (print == 1)
		ft_putstr_fd("pa\n", 1);
}
