/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 08:48:09 by esafar            #+#    #+#             */
/*   Updated: 2021/10/21 12:23:44 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_stack(long int *dest, long int *src, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		dest[i] = src[i];
		i++;
	}
}

long int *sort_stack(long int *fant, t_data *data)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < (data->ac - 1))
	{
		j = i + 1;
		while (j < (data->ac - 1))
		{
			if (fant[j] < fant[i])
			{
				tmp = fant[j];
				fant[j] = fant[i];
				fant[i] = tmp;
			}
			j++;
		}
		i++;
	}
	data->min = fant[0];
	data->max = fant[data->ac - 2];
	return (fant);
}

int	ra_or_rra(long int *stack, int elem, t_data *data)
{
	int	i;
	long int fant[502];

	i = 0;
	b_pas_zero(fant);
	copy_stack(fant, stack, data->ac);
	while (fant[0] != elem)
	{
		rotate_a(fant, 0);
		i++;
		if (i == ((data->ac - 1) / 2))
		{
			i = -1;
			break ;
		}
	}
	if (i == -1)
		return (2);
	if (i >= 0)
		return (1);
	return (0);
}

void	push_b_only_bads(long int *stack_a, long int *stack_b, long int *list, t_data *data)
{
	int j;

	j = 0;
	if (ra_or_rra(stack_a, list[0], data) == 1)
	{
		while (stack_a[0] != list[0])
			rotate_a(stack_a, 1);
	}
	else if (ra_or_rra(stack_a, list[0], data) == 2)
	{
		while (stack_a[0] != list[0])
			reverse_a(stack_a, 1);
	}
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
	while (j + data->remain_b < (data->ac - 1))
	{
		push_b(stack_a, stack_b, data->ac, 1);
		data->remain_b++;
	}
}

int	min_is_in(long int *stack, int min)
{
	int i;

	i = 0;
	while (stack[i] != 3000000000)
	{
		if (stack[i] == min)
			return (1);
		i++;
	}
	return (0);
}

int	max_is_in(long int *stack, int max)
{
	int i;

	i = 0;
	while (stack[i] != 3000000000)
	{
		if (stack[i] == max)
			return (1);
		i++;
	}
	return (0);
}

int	save_best_value_and_count(long int *stack_b, t_data *data, int to_push, int i)
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

void	insert_sort(long int *stack_a, long int *stack_b, t_data *data)
{
	int i;
	int to_push;
	int count;

	data->count_tmp = 0;
	while (data->remain_b > 0)
	{
		i = 0;
		data->tmp = 999999999;
		to_push = 0;
		while (i < data->remain_b)
		{
			data->count_tmp = check_count(stack_a, stack_b, stack_b[i], data);
			if (data->count_tmp < data->tmp)
				to_push = save_best_value_and_count(stack_b, data, to_push, i);
			i++;
		}
		data->count_tmp = data->tmp;
		push_best_nb(stack_a, stack_b, data, to_push);
		data->remain_b--;
	}
	reorder_the_stack(stack_a, data);
}

void	make_all(long int *stack_a, long int *stack_b, int ac)
{
	int count;
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
				count = 1;
				iter.j = iter.i + 1;
				data.tmp = stack_a[0];
				while (iter.j < ((data.ac) - 1))
				{
					while (data.tmp < stack_a[iter.j + 1] && stack_a[iter.j + 1] < stack_a[iter.j])
						iter.j++;
					if (data.tmp < stack_a[iter.j])
					{
						data.tmp = stack_a[iter.j];
						count++;
					}
					iter.j++;
				}
				if (data.count_tmp < count)
				{
					data.count_tmp = count;
					list[0] = stack_a[0];
					iter.v = 1;
					data.tmp = stack_a[0];
					iter.j = iter.i + 1;
					while (iter.j < ((data.ac) - 1))
					{
						while (data.tmp < stack_a[iter.j + 1] && stack_a[iter.j + 1] < stack_a[iter.j])
							iter.j++;
						if (data.tmp < stack_a[iter.j])
						{
							data.tmp = stack_a[iter.j];
							list[iter.v] = data.tmp;
							iter.v++;
						}
						iter.j++;
					}
				}	
				iter.i++;
			}
			rotate_a(stack_a, 0);
			iter.x++;
	}
	push_b_only_bads(stack_a, stack_b, list, &data);
	insert_sort(stack_a, stack_b, &data);
}

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
