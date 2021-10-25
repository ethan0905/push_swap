/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:15:25 by esafar            #+#    #+#             */
/*   Updated: 2021/10/25 10:54:48 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate_ou_reverse(long int *stack_a, int count_tmp, int i)
{
	if (count_tmp > 0)
		rotate_a(stack_a, 1);
	else if (count_tmp < 0)
		reverse_a(stack_a, 1);
	i++;
	return (i);
}

void	solve_my_five(long int *stack_a,
		long int *stack_b, t_data *data, int ac)
{
	int	i;

	i = 0;
	while (i < (ac - 1) && (stack_a[0] != data->min_du_stack))
		rotate_ou_reverse(stack_a, data->count_tmp, i);
	push_b(stack_a, stack_b, ac, 1);
	if (!(stack_a[0] < stack_a[1] && stack_a[1] < stack_a[2]
			&& stack_a[2] < stack_a[3]))
		make_four(stack_a, stack_b, ac);
	push_a(stack_a, stack_b, ac, 1);
}

void	high_five(long int *stack_a, long int *stack_b, int ac)
{
	int			i;
	t_data		data;
	long int	*s_med;

	i = 0;
	initialize(&data, ac);
	s_med = malloc_init(s_med, ac);
	b_pas_zero(s_med, ac);
	copy_stack(s_med, stack_a, ac);
	find_min_and_max_in_stack(stack_a, stack_b, &data);
	while (i < (ac - 1) && (s_med[0] != data.min_du_stack))
	{
		rotate_a(s_med, 0);
		data.count_tmp++;
		i++;
	}
	if (data.count_tmp > ((ac - 1) / 2))
		data.count_tmp = -1;
	solve_my_five(stack_a, stack_b, &data, ac);
	free(s_med);
}
