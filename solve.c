/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 08:48:09 by esafar            #+#    #+#             */
/*   Updated: 2021/10/21 16:29:23 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	solve(long int *stack_a, long int *stack_b, int ac)
{
	if ((ac - 1) == 2)
		make_two(stack_a);
	if ((ac - 1) == 3)
		make_three(stack_a);
	if ((ac - 1) == 4)
		make_four(stack_a, stack_b, ac);
	if ((ac - 1) == 5)
		high_five(stack_a, stack_b, ac);
	if ((ac - 1) >= 6)
		make_all(stack_a, stack_b, ac);
	return (1);
}
