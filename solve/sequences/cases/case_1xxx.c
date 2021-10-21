/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_1xxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:26:42 by esafar            #+#    #+#             */
/*   Updated: 2021/10/21 17:08:00 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	case_1xxx(long int *stack_a, long int *stack_b, int ac)
{
	if (stack_a[1] < stack_a[3] && stack_a[3] < stack_a[2])
		rra_rra_sa_rra_rra(stack_a);
	else if (stack_a[1] < stack_a[3] && stack_a[3] > stack_a[2])
		ra_sa_rra(stack_a);
	else if (stack_a[1] > stack_a[3] && stack_a[3] < stack_a[2]
		&& stack_a[1] < stack_a[2])
		rra_sa(stack_a);
	else if (stack_a[1] > stack_a[2] && stack_a[1] > stack_a[3])
	{
		if (stack_a[2] < stack_a[3])
			rra_sa_rra_sa(stack_a);
		else
			pb_sa_rra_pa(stack_a, stack_b, ac);
	}
}
