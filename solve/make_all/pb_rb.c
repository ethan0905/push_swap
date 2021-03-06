/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:19:47 by esafar            #+#    #+#             */
/*   Updated: 2021/10/25 17:27:22 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pb_rb(long int *stack_a, long int *stack_b, int ac)
{
	push_b(stack_a, stack_b, ac, 1);
	rotate_b(stack_b, 1);
}
