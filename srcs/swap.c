/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:02:31 by esafar            #+#    #+#             */
/*   Updated: 2021/10/20 16:04:04 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(long int *stack_a, int print)
{
	int	tmp;

	if (stack_a[0] && stack_a[1])
	{
		tmp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = tmp;
	}
	if (print == 1)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(long int *stack_b, int print)
{
	int	tmp;

	if (stack_b[0] && stack_b[1])
	{
		tmp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = tmp;
	}
	if (print == 1)
		ft_putstr_fd("sb\n", 1);
}

void	swap_ab(long int *stack_a, long int *stack_b, int print)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	if (print == 1)
		ft_putstr_fd("ss\n", 1);
}
