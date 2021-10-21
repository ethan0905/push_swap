/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:01:53 by esafar            #+#    #+#             */
/*   Updated: 2021/10/21 16:44:37 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reverse_a(long int *stack_a, int print)
{
	int	i;
	int	tmp;

	i = 0;
	while (stack_a[i] != 3000000000)
		i++;
	i--;
	tmp = stack_a[i];
	while (--i >= 0)
		stack_a[i + 1] = stack_a[i];
	stack_a[0] = tmp;
	if (print == 1)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_b(long int *stack_b, int print)
{
	int	i;
	int	tmp;

	i = 0;
	while (stack_b[i] != 3000000000)
		i++;
	i--;
	tmp = stack_b[i];
	while (--i >= 0)
		stack_b[i + 1] = stack_b[i];
	stack_b[0] = tmp;
	if (print == 1)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_ab(long int *stack_a, long int *stack_b, int print)
{
	reverse_a(stack_a, 0);
	reverse_b(stack_b, 0);
	if (print == 1)
		ft_putstr_fd("rrr\n", 1);
}
