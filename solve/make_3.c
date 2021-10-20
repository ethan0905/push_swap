/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:13:05 by esafar            #+#    #+#             */
/*   Updated: 2021/10/20 19:14:22 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	make_three(long int *stack_a)
{
	if (stack_a[0] < stack_a[1])
	{
		if (stack_a[0] < stack_a[2])
		{
			swap_a(stack_a, 1);
			rotate_a(stack_a, 1);
		}
		else
			reverse_a(stack_a, 1);
	}
	else if (stack_a[0] > stack_a[1])
	{
		if (stack_a[1] > stack_a[2])
		{
			swap_a(stack_a, 1);
			reverse_a(stack_a, 1);
		}
		else if (stack_a[0] < stack_a[2])
			swap_a(stack_a, 1);
		else
			rotate_a(stack_a, 1);
	}
}
