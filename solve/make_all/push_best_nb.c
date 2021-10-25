/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_best_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:03:13 by esafar            #+#    #+#             */
/*   Updated: 2021/10/25 11:24:54 by esafar           ###   ########.fr       */
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

long int	*rfb_or_rrfb(long int *fant_b, t_data *data)
{
	if (data->rb == 1 && data->rrb == 0)
	{
		rotate_b(fant_b, 0);
		data->count_rb++;
	}
	else if (data->rrb == 1 && data->rb == 0)
	{
		reverse_b(fant_b, 0);
		data->count_rrb++;
	}
	data->tmp_tmp--;
	return (fant_b);
}

long int	*rfa_or_rrfa(long int *fant_a, t_data *data)
{
	if (data->ra == 1 && data->rra == 0)
	{
		rotate_a(fant_a, 0);
		data->count_ra++;
	}
	else if (data->ra == 0 && data->rra == 1)
	{
		reverse_a(fant_a, 0);
		data->count_rra++;
	}
	data->tmp_tmp--;
	return (fant_a);
}

void	push_best_nb(long int *stack_a, long int *stack_b,
		t_data *data, int to_push)
{
	long int	*fant_a;
	long int	*fant_b;

	//partie 1:test pour savoir si double RR ou RRR
	fant_a = malloc_init(fant_a, data->ac);
	fant_b = malloc_init(fant_a, data->ac);
	b_pas_zero(fant_a, data->ac);
	b_pas_zero(fant_b, data->ac);
	copy_stack(fant_a, stack_a, data->ac);
	copy_stack(fant_b, stack_b, data->ac);
	data->tmp_tmp = initialize_count_for_rr_rrr(data);
	while (fant_b[0] != to_push && data->tmp_tmp > 1)
		fant_b[0] = *rfb_or_rrfb(fant_b, data);
	while (data->tmp_tmp > 1)
		fant_a[0] = *rfa_or_rrfa(fant_a, data);
	push_a(fant_a, fant_b, data->ac, 0);
	//partie 2: execution
	while (stack_b[0] != to_push && data->count_tmp > 1)
		exec_moves_b(stack_a, stack_b, data);
	while (data->count_tmp > 1)
		exec_moves_a(stack_a, data);
	push_a(stack_a, stack_b, data->ac, 1);
	free(fant_a);
	free(fant_b);
}
