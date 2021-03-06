/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_best_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:03:13 by esafar            #+#    #+#             */
/*   Updated: 2021/10/29 14:30:45 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	exec_moves_b(long int *stack_a, long int *stack_b, t_data *data)
{
	if (data->rb == 1 && data->rrb == 0
		&& data->count_rb > 0 && data->count_ra == 0)
		rotate_b(stack_b, 1);
	else if (data->rrb == 1 && data->rb == 0 && data->count_rrb > 0
		&& data->count_rra == 0)
		reverse_b(stack_b, 1);
	else if ((data->count_rb > 0 && data->count_ra > 0) || (data->count_rrb > 0
			&& data->count_rra > 0))
	{
		if (data->count_rb > 0 && data->count_ra > 0)
		{
			rotate_ab(stack_a, stack_b, 1);
			data->count_rb--;
			data->count_ra--;
		}
		else if (data->count_rrb > 0 && data->count_rra > 0)
		{
			reverse_ab(stack_a, stack_b, 1);
			data->count_rrb--;
			data->count_rra--;
		}
	}
	data->count_tmp--;
}

void	exec_moves_a(long int *stack_a, t_data *data)
{
	if (data->ra == 1 && data->rra == 0 && data->count_ra > 0
		&& data->count_rb == 0)
	{
		rotate_a(stack_a, 1);
		data->count_ra--;
	}
	else if (data->ra == 0 && data->rra == 1 && data->count_rra > 0
		&& data->count_rrb == 0)
	{
		reverse_a(stack_a, 1);
		data->count_rra--;
	}
	data->count_tmp--;
}

void	check_moves(long int *fant_a, long int
		*fant_b, t_data *data, int to_push)
{
	while (fant_b[0] != to_push && data->tmp_tmp > 1)
		fant_b[0] = *rfb_or_rrfb(fant_b, data);
	while (data->tmp_tmp > 1)
		fant_a[0] = *rfa_or_rrfa(fant_a, data);
	push_a(fant_a, fant_b, data->ac, 0);
}

void	exec_moves(long int *stack_a, long int
		*stack_b, t_data *data, int to_push)
{
	while (stack_b[0] != to_push && data->count_tmp > 1)
		exec_moves_b(stack_a, stack_b, data);
	while (data->count_tmp > 1)
		exec_moves_a(stack_a, data);
	push_a(stack_a, stack_b, data->ac, 1);
}

int	push_best_nb(long int *stack_a, long int *stack_b,
		t_data *data, int to_push)
{
	long int	*fant_a;
	long int	*fant_b;

	fant_a = (long int *)malloc(sizeof(long int) * (data->ac + 1));
	if (!fant_a)
		return (-1);
	fant_b = (long int *)malloc(sizeof(long int) * (data->ac + 1));
	if (!fant_b)
	{
		free(fant_a);
		return (-1);
	}
	b_pas_zero(fant_a, data->ac);
	b_pas_zero(fant_b, data->ac);
	copy_stack(fant_a, stack_a, data->ac);
	copy_stack(fant_b, stack_b, data->ac);
	data->tmp_tmp = initialize_count_for_rr_rrr(data);
	check_moves(fant_a, fant_b, data, to_push);
	exec_moves(stack_a, stack_b, data, to_push);
	double_free(fant_a, fant_b);
	return (1);
}
