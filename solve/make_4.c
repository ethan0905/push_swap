/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:14:30 by esafar            #+#    #+#             */
/*   Updated: 2021/10/21 17:04:36 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	make_four(long int *stack_a, long int *stack_b, int ac)
{
	if (stack_a[0] > stack_a[1] && stack_a[0] > stack_a[2]
		&& stack_a[0] > stack_a[3])
		case_4xxx(stack_a);
	else if (stack_a[0] < stack_a[1] && stack_a[0] < stack_a[2]
		&& stack_a[0] < stack_a[3])
		case_1xxx(stack_a, stack_b, ac);
	else if (stack_a[0] > stack_a[1] && stack_a[0] < stack_a[2]
		&& stack_a[0] < stack_a[3])
		case_21xx(stack_a, stack_b, ac);
	else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]
		&& stack_a[1] > stack_a[3] && (stack_a[0] < stack_a[2]
			|| stack_a[0] < stack_a[3]))
		case_24xx(stack_a, stack_b, ac);
	else if (stack_a[0] < stack_a[1] && (stack_a[1] < stack_a[2]
			|| stack_a[1] < stack_a[3]))
		case_23xx(stack_a, stack_b, ac);
	else if (stack_a[0] < stack_a[1] && stack_a[0] > stack_a[2]
		&& stack_a[0] > stack_a[3])
		case_34xx(stack_a);
	else if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2]
		&& stack_a[1] < stack_a[3])
		case_31xx(stack_a);
	else if (stack_a[0] > stack_a[1] && (stack_a[1] < stack_a[2]
			|| stack_a[1] < stack_a[3]))
		case_32xx(stack_a);
}
