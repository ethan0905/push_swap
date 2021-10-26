/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:41:54 by esafar            #+#    #+#             */
/*   Updated: 2021/10/26 10:44:41 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_stack(long int *fant, long int *stack, int ac)
{
	b_pas_zero(fant, ac);
	copy_stack(fant, stack, ac);
}

void	initialize(t_data *data, int ac)
{
	data->ac = ac;
	data->count_tmp = 0;
	data->remain_b = 0;
	data->tmp = 0;
	data->tmp_tmp = 0;
	data->min = 0;
	data->med_a = 0;
	data->med_b = 0;
	data->max = 0;
	data->min_du_stack = 0;
	data->max_du_stack = 0;
	data->ra_tmp = 0;
	data->rb_tmp = 0;
	data->rrb_tmp = 0;
	data->rra_tmp = 0;
	data->ra = 0;
	data->rb = 0;
	data->rrb = 0;
	data->rra = 0;
	data->count_ra = 0;
	data->count_rb = 0;
	data->count_rra = 0;
	data->count_rrb = 0;
}

void	initialize_s2(t_iter *iter)
{
	iter->i = 0;
	iter->j = 0;
	iter->x = 0;
	iter->v = 0;
	iter->count = 0;
}

void	initialize_s3(t_need_space *need_space)
{
	need_space->ca = 0;
	need_space->cb = 0;
}

void	initialize_s1_s2(t_data *data, t_iter *iter, int ac)
{
	initialize(data, ac);
	initialize_s2(iter);
}
