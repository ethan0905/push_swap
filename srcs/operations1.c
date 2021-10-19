/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:38:18 by esafar            #+#    #+#             */
/*   Updated: 2021/10/13 12:43:24 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(long int *stackA, int print)
{
	int tmp;
	
	if (stackA[0] && stackA[1])
	{
		tmp = stackA[0];
		stackA[0] = stackA[1];
		stackA[1]= tmp;
	}
	if (print == 1)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(long int *stackB, int print)
{
	int tmp;

	if (stackB[0] && stackB[1])
	{
		tmp = stackB[0];
		stackB[0] = stackB[1];
		stackB[1]= tmp;
	}
	if (print == 1)
		ft_putstr_fd("sb\n", 1);
}

void	swap_ab(long int *stackA, long int *stackB, int print)
{
	swap_a(stackA, 0);
	swap_b(stackB, 0);
	if (print == 1)
		ft_putstr_fd("ss\n", 1);
}

void	push_b(long int *stackA, long int *stackB, int ac, int print)
{
	int i;

	i = ac - 1;
	while (i >= 0)
	{
		stackB[i + 1] = stackB[i];
		if (i == 0)
			stackB[0] = stackA[0];
		i--;
	}
	i = 0;
	while (i < ac - 1)
	{
		stackA[i] = stackA[i + 1];
		i++;
	}
	if (print == 1)
		ft_putstr_fd("pb\n", 1);
}

void	push_a(long int *stackA, long int *stackB, int ac, int print)
{
	int i;

	i = ac - 1;
	while (i >= 0)
	{
		stackA[i + 1] = stackA[i];
		if (i == 0)
			stackA[0] = stackB[0];
		i--;
	}
	i = 0;
	while (i < ac - 1)
	{
		stackB[i] = stackB[i + 1];
		i++;
	}
	if (print == 1)
		ft_putstr_fd("pa\n", 1);
}

void	reverse_a(long int *stackA, int print)
{
	int i;
	int tmp;

	i = 0;
	while (stackA[i] != 3000000000)
		i++;
	i--;
	tmp = stackA[i];
	while (--i >= 0)
		stackA[i + 1] = stackA[i];
	stackA[0] = tmp;
	if (print == 1)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_b(long int *stackB, int print)
{
	int i;
	int tmp;

	i = 0;
	while (stackB[i] != 3000000000)
		i++;
	i--;
	tmp = stackB[i];
	while (--i >= 0)
		stackB[i + 1] = stackB[i];
	stackB[0] = tmp;
	if (print == 1)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_ab(long int *stackA, long int *stackB, int print)
{
	reverse_a(stackA, 0);
	reverse_b(stackB, 0);
	if (print == 1)
		ft_putstr_fd("rrr\n", 1);
}

void	rotate_a(long int *stackA, int print)
{
	int i;
	int tmp;

	i = 0;
	tmp = stackA[0];
	while (stackA[i] != 3000000000)
	{
		stackA[i] = stackA[i + 1];
		if (stackA[i + 1] == 3000000000)
			stackA[i] = tmp;
		i++;
	}
	if (print == 1)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(long int *stackB, int print)
{
	int i;
	int tmp;

	i = 0;
	tmp = stackB[0];
	while (stackB[i] != 3000000000)
	{
		stackB[i] = stackB[i + 1];
		if (stackB[i + 1] == 3000000000)
			stackB[i] = tmp;
		i++;
	}
	if (print == 1)
		ft_putstr_fd("rb\n", 1);
}

void	 rotate_ab(long int *stackA, long int *stackB, int print)
{
	rotate_a(stackA, 0);
	rotate_b(stackB, 0);
	if (print == 1)
		ft_putstr_fd("rr\n", 1);
}
