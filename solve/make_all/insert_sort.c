/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:34:17 by esafar            #+#    #+#             */
/*   Updated: 2021/10/26 14:16:12 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	save_best_value_and_count(long int *stack_b, t_data *data,
		int to_push, int i)
{
	data->ra = data->ra_tmp;
	data->rb = data->rb_tmp;
	data->rra = data->rra_tmp;
	data->rrb = data->rrb_tmp;
	data->tmp = data->count_tmp;
	to_push = stack_b[i]; // avant : tmp = stack_b[0], une erreur a 35 000 operations
	return (to_push);
}

void	reorder_the_stack(long int *stack_a, t_data *data)
{
	while (stack_a[0] != data->min)
	{
		if (ra_or_rra(stack_a, data->min, data) == 1)
			rotate_a(stack_a, 1);
		else if (ra_or_rra(stack_a, data->min, data) == 2)
			reverse_a(stack_a, 1);
	}
}

t_iter	init_iter(t_iter iter)
{
	iter.i = 0;
	iter.x = 0;
	return (iter);
}

int	insert_sort(long int *stack_a, long int *stack_b, t_data *data, t_iter iter)
{
	int	count;

	data->count_tmp = 0;
	while (data->remain_b > 0)
	{
		iter = init_iter(iter);
		data->tmp = 999999999;
		while (iter.i < data->remain_b)
		{
			data->count_tmp = check_count(stack_a, stack_b, stack_b[iter.i], data);
			if (data->count_tmp < 0)
				return (-1);
			if (data->count_tmp < data->tmp)
				iter.x = save_best_value_and_count(stack_b, data, iter.x, iter.i);
			iter.i++;
		}
		data->count_tmp = data->tmp;
		if (push_best_nb(stack_a, stack_b, data, iter.x) < 0)
			return (-1);
		data->remain_b--;
	}
	reorder_the_stack(stack_a, data);
	return (1);
}
