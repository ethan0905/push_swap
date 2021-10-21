/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:01:15 by esafar            #+#    #+#             */
/*   Updated: 2021/10/20 16:04:24 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(long int *stack_a, int print)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack_a[0];
	while (stack_a[i] != 3000000000)
	{
		stack_a[i] = stack_a[i + 1];
		if (stack_a[i + 1] == 3000000000)
			stack_a[i] = tmp;
		i++;
	}
	if (print == 1)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(long int *stack_b, int print)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack_b[0];
	while (stack_b[i] != 3000000000)
	{
		stack_b[i] = stack_b[i + 1];
		if (stack_b[i + 1] == 3000000000)
			stack_b[i] = tmp;
		i++;
	}
	if (print == 1)
		ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(long int *stack_a, long int *stack_b, int print)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	if (print == 1)
		ft_putstr_fd("rr\n", 1);
}
