/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:08:05 by esafar            #+#    #+#             */
/*   Updated: 2021/10/29 14:30:27 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	find_min_and_max_in_stack(long int *stack_a, t_data *data)
{
	int			i;
	long int	tmp;

	i = 0;
	tmp = 3000000000;
	while (stack_a[i] != 3000000000)
	{
		if (stack_a[i] < tmp)
			tmp = stack_a[i];
		i++;
	}
	data->min_du_stack = tmp;
	i = 0;
	tmp = -3000000000;
	while (stack_a[i] != 3000000000)
	{
		if (stack_a[i] > tmp)
			tmp = stack_a[i];
		i++;
	}
	data->max_du_stack = tmp;
}

int	get_cb(long int *fant_b, t_data *data, int value)
{
	int	cb;

	cb = 0;
	while (fant_b[cb] != value)
	{
		cb++;
		data->rb_tmp = 1;
		data->rrb_tmp = 0;
		if (cb > data->med_b)
		{
			data->rb_tmp = 0;
			data->rrb_tmp = 1;
			cb = -1;
			break ;
		}
	}
	if (cb < 0)
	{
		cb = 0;
		while (fant_b[data->remain_b - 1 - cb] != value)
			cb++;
		cb++;
	}
	return (cb);
}

int	get_ca(long int *fant_a, t_data *data, int value, int remain_a)
{
	int	ca;

	ca = 0;
	if (value < data->min_du_stack)
	{
		ca = under_min_of_stack(fant_a, data, ca, remain_a);
	}
	else if (value > data->max_du_stack)
	{
		ca = superior_to_max_of_stack(fant_a, data, ca, remain_a);
	}
	else if (value > fant_a[ca])
	{
		if (value < data->max_du_stack)
		{
			ca = under_max_of_stack(fant_a, data, value, remain_a);
		}
	}
	else if (value < fant_a[ca])
	{
		ca = under_top_of_stack(fant_a, data, value, remain_a);
	}
	return (ca);
}

int	check_count(long int *stack_a, long int *stack_b,
		long int value, t_data *data)
{
	int				remain_a;
	long int		*fant_a;
	long int		*fant_b;
	t_need_space	need_space;

	fant_a = (long int *)malloc(sizeof(long int) * (data->ac + 1));
	if (!fant_a)
		return (-1);
	fant_b = (long int *)malloc(sizeof(long int) * (data->ac + 1));
	if (!fant_b)
		return (free_(fant_a));
	initialize_stack(fant_a, stack_a, data->ac);
	initialize_stack(fant_b, stack_b, data->ac);
	initialize_s3(&need_space);
	remain_a = data->ac - 1 - data->remain_b;
	data->med_a = remain_a / 2;
	data->med_b = data->remain_b / 2;
	find_min_and_max_in_stack(fant_a, data);
	need_space.cb = get_cb(fant_b, data, value);
	need_space.ca = get_ca(fant_a, data, value, remain_a);
	double_free(fant_a, fant_b);
	return (need_space.ca + need_space.cb + 1);
}
