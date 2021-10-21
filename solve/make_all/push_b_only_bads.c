/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_only_bads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:44:20 by esafar            #+#    #+#             */
/*   Updated: 2021/10/21 15:45:04 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra_or_rra_until_elem_from_list(long int *stack_a, int nb_list, t_data *data)
{
	if (ra_or_rra(stack_a, nb_list, data) == 1)
	{
		while (stack_a[0] != nb_list)
			rotate_a(stack_a, 1);
	}
	else if (ra_or_rra(stack_a, nb_list, data) == 2)
	{
		while (stack_a[0] != nb_list)
			reverse_a(stack_a, 1);
	}
}

void	complete_pushing_all_bads_to_b(long int *stack_a, long int *stack_b, t_data *data, int j)
{
	while (j + data->remain_b < (data->ac - 1))
	{
		push_b(stack_a, stack_b, data->ac, 1);
		data->remain_b++;
	}
}
void	push_b_only_bads(long int *stack_a, long int *stack_b, long int *list, t_data *data)
{
	int j;

	j = 0;
	ra_or_rra_until_elem_from_list(stack_a, list[0], data);
	while (j < data->count_tmp)
	{
		while (stack_a[0] != list[j])
		{
			push_b(stack_a, stack_b, data->ac, 1);
			data->remain_b++;
		}
		if (stack_a[0] == list[j])
		{
			rotate_a(stack_a, 1);
			j++;
		}
	}
	complete_pushing_all_bads_to_b(stack_a, stack_b, data, j);
}
