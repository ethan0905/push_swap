/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:24:51 by esafar            #+#    #+#             */
/*   Updated: 2021/10/21 16:25:24 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	count_actual_list_size(long int *stack_a, t_data *data, t_iter *iter)
{
	while (data->tmp < stack_a[iter->j + 1] && stack_a[iter->j + 1] < stack_a[iter->j])
		iter->j++;
	if (data->tmp < stack_a[iter->j])
	{
		data->tmp = stack_a[iter->j];
		iter->count++;
	}
	iter->j++;
}

void	save_actual_longest_list(long int *stack_a, long int *list, t_data *data, t_iter *iter)
{
	data->count_tmp = iter->count;
	list[0] = stack_a[0];
	iter->v = 1;
	data->tmp = stack_a[0];
	iter->j = iter->i + 1;
	while (iter->j < ((data->ac) - 1))
	{
		while (data->tmp < stack_a[iter->j + 1] && stack_a[iter->j + 1] < stack_a[iter->j])
			iter->j++;
		if (data->tmp < stack_a[iter->j])
		{
			data->tmp = stack_a[iter->j];
			list[iter->v] = data->tmp;
			iter->v++;
		}
		iter->j++;
	}
}

void	search_already_sorted_list(long int *stack_a, long int *list, t_data *data, t_iter *iter)
{
	iter->count = 1;
	iter->j = iter->i + 1;
	data->tmp = stack_a[0];
	while (iter->j < ((data->ac) - 1))
	{
		count_actual_list_size(stack_a, data, iter);
	}
	if (data->count_tmp < iter->count)
	{
		save_actual_longest_list(stack_a, list, data, iter);
	}
	iter->i++;
}

void	make_all(long int *stack_a, long int *stack_b, int ac)
{
	t_data data;
	t_iter iter;
	long int list[502];
	long int fant[502];

	initialize(&data, ac);
	initialize_s2(&iter);
	b_pas_zero(list);
	b_pas_zero(fant);
	copy_stack(fant, stack_a, ac);
	sort_stack(fant, &data);
	while (iter.x < ((data.ac) - 1))
	{
			iter.i = 0;
			while (iter.i < ((data.ac) - 1))
			{
				search_already_sorted_list(stack_a, list, &data, &iter);
			}
			rotate_a(stack_a, 0);
			iter.x++;
	}
	push_b_only_bads(stack_a, stack_b, list, &data);
	insert_sort(stack_a, stack_b, &data);
}
