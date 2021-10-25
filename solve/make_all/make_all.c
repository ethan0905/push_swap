/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:24:51 by esafar            #+#    #+#             */
/*   Updated: 2021/10/25 17:50:35 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	count_actual_list_size(long int *stack_a, t_data *data, t_iter *iter)
{
	while (data->tmp < stack_a[iter->j + 1] && stack_a[iter->j + 1]
		< stack_a[iter->j])
		iter->j++;
	if (data->tmp < stack_a[iter->j])
	{
		data->tmp = stack_a[iter->j];
		iter->count++;
	}
	iter->j++;
}

void	save_actual_longest_list(long int *stack_a, long int *list,
		t_data *data, t_iter *iter)
{
	data->count_tmp = iter->count;
	list[0] = stack_a[0];
	iter->v = 1;
	data->tmp = stack_a[0];
	iter->j = iter->i + 1;
	while (iter->j < ((data->ac) - 1))
	{
		while (data->tmp < stack_a[iter->j + 1] && stack_a[iter->j + 1]
			< stack_a[iter->j])
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

void	search_already_sorted_list(long int *stack_a, long int *list,
		t_data *data, t_iter *iter)
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

void	do_insert_sort(long int *stack_a, long int *stack_b,
		t_data *data, int ac)
{
	data->remain_b = ac - 3;
	make_two(stack_a);
	insert_sort(stack_a, stack_b, data);
}

int	make_all(long int *stack_a, long int *stack_b, int ac)
{
	t_data		data;
	t_iter		iter;
	long int	*fant;

	fant = malloc_init(fant, ac);
	if (!fant)
		return (-1);
	initialize_s1_s2(&data, &iter, ac);
	b_pas_zero(fant, ac);
	copy_and_sort(fant, stack_a, &data, ac);
	while (iter.x < (data.ac - 3))
	{
		if (iter.x == 0)
			push_b(stack_a, stack_b, ac, 1);
		else if (stack_a[0] < fant[(ac - 1) / 2])
			pb_rb(stack_a, stack_b, ac);
		else if (stack_a[0] >= fant[(ac - 1) / 2])
			push_b(stack_a, stack_b, ac, 1);
		iter.x++;
	}
	do_insert_sort(stack_a, stack_b, &data, ac);
	free(fant);
	return (1);
}
