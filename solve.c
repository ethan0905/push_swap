/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 08:48:09 by esafar            #+#    #+#             */
/*   Updated: 2021/10/20 20:32:00 by esafar           ###   ########.fr       */
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

void	find_min_and_max_in_stack(long int *stack_a, long int *stack_b, t_data *data)
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
	int cb;

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

int under_min_of_stack(long int *fant_a, t_data *data, int ca, int remain_a)
{
	data->ra_tmp = 1;
	data->rra_tmp = 0;
	while (fant_a[ca] != data->min_du_stack)
		ca++;
	if (ca > data->med_a)
		ca = -1;
	if (ca < 0)
	{
		ca = 0;
		data->ra_tmp = 0;
		data->rra_tmp = 1;
		while (fant_a[remain_a-1-ca] != data->max_du_stack)
			ca++;
	}
	return (ca);
}

int superior_to_max_of_stack(long int *fant_a, t_data *data, int ca, int remain_a)
{
	data->ra_tmp = 1;
	data->rra_tmp = 0;
	while (fant_a[ca] != data->min_du_stack)
		ca++;
	if (ca > data->med_a)
		ca = -1;
	if (ca < 0)
	{
		ca = 0;
		data->ra_tmp = 0;
		data->rra_tmp = 1;
		while (fant_a[remain_a - 1 - ca] != data->min_du_stack)
			ca++;
		ca++;
	}
	return (ca);
}

int under_max_of_stack(long int *fant_a, t_data *data, int value, int remain_a)
{
	int ca;

	ca = 0;
	data->ra_tmp = 1;
	data->rra_tmp = 0;
	while (value > fant_a[ca])
		ca++;
	if (ca > data->med_a)
		ca = -1;
	if (ca < 0)
	{
		ca = 0;
		data->ra_tmp = 0;
		data->rra_tmp = 1;
		if (value > fant_a[remain_a - 1 - ca])
		{
			while (value > fant_a[remain_a - 1 - ca])
				ca++;
			while (value < fant_a[remain_a - 1 - ca])
				ca++;
		}
		else
		{
			while (value < fant_a[remain_a - 1 - ca])
				ca++;
		}
	}
	return (ca);
}

int	get_ca(long int *fant_a, t_data *data, int value, int remain_a)
{
	int ca;

	ca = 0;
	if (value < data->min_du_stack)
	{
//		under_min_of_stack(fant_a, data, ca, remain_a);
		data->ra_tmp = 1;
		data->rra_tmp = 0;
		while (fant_a[ca] != data->min_du_stack)
			ca++;
		if (ca > data->med_a)
			ca = -1;
		if (ca < 0)
		{
			ca = 0;
			data->ra_tmp = 0;
			data->rra_tmp = 1;
			while (fant_a[remain_a-1-ca] != data->max_du_stack)
				ca++;
		}
	}
	else if (value > data->max_du_stack)
	{
//		superior_to_max_of_stack(fant_a, data, ca, remain_a);
		data->ra_tmp = 1;
		data->rra_tmp = 0;
		while (fant_a[ca] != data->min_du_stack)
			ca++;
		if (ca > data->med_a)
			ca = -1;
		if (ca < 0)
		{
			ca = 0;
			data->ra_tmp = 0;
			data->rra_tmp = 1;
			while (fant_a[remain_a - 1 - ca] != data->min_du_stack)
				ca++;
			ca++;
		}
	}
	else if (value > fant_a[ca])
	{
		if (value < data->max_du_stack)
		{
//			under_max_of_stack(fant_a, data, value, remain_a);
			data->ra_tmp = 1;
			data->rra_tmp = 0;
			while (value > fant_a[ca])
				ca++;
			if (ca > data->med_a)
				ca = -1;
			if (ca < 0)
			{
				ca = 0;
				data->ra_tmp = 0;
				data->rra_tmp = 1;
				if (value > fant_a[remain_a - 1 - ca])
				{
					while (value > fant_a[remain_a - 1 - ca])
						ca++;
					while (value < fant_a[remain_a - 1 - ca])
						ca++;
				}
				else
				{
					while (value < fant_a[remain_a - 1 - ca])
						ca++;
				}
			}
		}
	}
	else if (value < fant_a[ca])
	{
		data->ra_tmp = 1;
		data->rra_tmp = 0;
		while (value < fant_a[ca])
			ca++;
		while (value > fant_a[ca])
			ca++;
		if (ca > data->med_a)
			ca = -1;
		if (ca < 0)
		{
			ca = 0;
			data->ra_tmp = 0;
			data->rra_tmp = 1;
			while (value < fant_a[remain_a - 1 - ca])
				ca++;
		}
	}
	return (ca);
}

int check_count(long int *stack_a, long int *stack_b, long int value, t_data *data)
{
	int			ca;
	int			cb;
	int			i;
	int			remain_a;
	long int	fant_a[502];
	long int	fant_b[502];

	b_pas_zero(fant_a);
	copy_stack(fant_a, stack_a, data->ac);
	b_pas_zero(fant_b);
	copy_stack(fant_b, stack_b, data->ac);
	//part 1 : recuperer ma median ainsi que la taille de mon stack_a
	remain_a = data->ac-1-data->remain_b;
	data->med_a = remain_a/2;
	data->med_b = data->remain_b/2;
	//part 2 : trouver mon min et max de A actuel
	find_min_and_max_in_stack(fant_a, fant_b, data);
	//part 3 : compter
	cb = get_cb(fant_b, data, value);
	//deuxieme partie de l'algo:chercher le chemin le plus court pour placer stack_b[0]
	ca = get_ca(fant_a, data, value, remain_a);
	return (ca+cb+1);
}

void	push_best_nb(long int *stack_a, long int *stack_b, t_data *data, int to_push)
{
	int tmp_tmp;
	long int fant_a[502];
	long int fant_b[502];

	//partie 1:test pour savoir si double RR ou RRR
	b_pas_zero(fant_a);
	b_pas_zero(fant_b);
	copy_stack(fant_a, stack_a, data->ac);
	copy_stack(fant_b, stack_b, data->ac);

	tmp_tmp = data->count_tmp;
	data->count_ra = 0;
	data->count_rb = 0;
	data->count_rra = 0;
	data->count_rrb = 0;
	while (fant_b[0] != to_push && tmp_tmp > 1)
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
		tmp_tmp--;
	}
	while (tmp_tmp > 1)
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
		tmp_tmp--;
	}
	push_a(fant_a, fant_b, data->ac, 0);
	//partie 2: execution
	while (stack_b[0] != to_push && data->count_tmp > 1)
	{
		if (data->rb == 1 && data->rrb == 0 && data->count_rb > 0 && data->count_ra == 0)
			rotate_b(stack_b, 1);
		else if (data->rrb == 1 && data->rb == 0 && data->count_rrb > 0 && data->count_rra == 0)
			reverse_b(stack_b, 1);
		else if ((data->count_rb > 0 && data->count_ra > 0) || (data->count_rrb > 0 && data->count_rra > 0))
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
	while (data->count_tmp > 1)
	{
		if (data->ra == 1 && data->rra == 0 && data->count_ra > 0 && data->count_rb == 0)
		{
			rotate_a(stack_a, 1);
			data->count_ra--;
		}
		else if (data->ra == 0 && data->rra == 1 && data->count_rra > 0 && data->count_rrb == 0)
		{
			reverse_a(stack_a, 1);
			data->count_rra--;
		}
		data->count_tmp--;
	}
	push_a(stack_a, stack_b, data->ac, 1);
}

void	insert_sort(long int *stack_a, long int *stack_b, t_data *data)
{
	int i;
	int to_push;
	int tmp;
	int count;

	data->count_tmp = 0;
	while (data->remain_b > 0)
	{
		i = 0;
		tmp = 999999999;
		to_push = 0;
		while (i < data->remain_b)
		{
			data->count_tmp = check_count(stack_a, stack_b, stack_b[i], data);
			if (data->count_tmp < tmp)
			{
				data->ra = data->ra_tmp;
				data->rb = data->rb_tmp;
				data->rra = data->rra_tmp;
				data->rrb = data->rrb_tmp;
				tmp = data->count_tmp;
				to_push = stack_b[i]; // avant : tmp = stack_b[0], une erreur a 35 000 operations
			}
			i++;
		}
		data->count_tmp = tmp;
		push_best_nb(stack_a, stack_b, data, to_push);
		data->remain_b--;
	}
	while (stack_a[0] != data->min)
	{
		if (ra_or_rra(stack_a, data->min, data) == 1)
			rotate_a(stack_a, 1);
		else if (ra_or_rra(stack_a, data->min, data) == 2)
			reverse_a(stack_a, 1);
	}
}

void	make_all(long int *stack_a, long int *stack_b, int ac)
{
	int x;
	int v;
	int i;
	int j;
	t_data data;
	int tmp;
	int count;
	int start;
	long int list[502];
	long int fant[502];
	int count_tmp;

	x = 0;
	initialize(&data, ac);
	b_pas_zero(list);
	b_pas_zero(fant);
	copy_stack(fant, stack_a, ac);
	sort_stack(fant, &data);
	count_tmp = 0;
	while (x < ((data.ac) - 1))
	{
		if (stack_a[x])
		{
			i = 0;
			while (i < ((data.ac) - 1))
			{
				count = 1;
				j = i + 1;
				tmp = stack_a[0];
				while (j < ((data.ac) - 1))
				{
					while (tmp < stack_a[j + 1] && stack_a[j + 1] < stack_a[j])
						j++;
					if (tmp < stack_a[j])
					{
						tmp = stack_a[j];
						count++;
					}
					j++;
				}
				if (data.count_tmp < count)
				{
					start = stack_a[0];
					data.count_tmp = count;
					list[0] = stack_a[0];
					
					v = 1;
					tmp = stack_a[0];
					j = i + 1;
					while (j < ((data.ac) - 1))
					{
						while (tmp < stack_a[j + 1] && stack_a[j + 1] < stack_a[j])
							j++;
						if (tmp < stack_a[j])
						{
							tmp = stack_a[j];
							list[v] = tmp;
							v++;
						}
						j++;
					}
				}	
				i++;
			}
			rotate_a(stack_a, 0);
			x++;
		}
		else
		{
			rotate_a(stack_a, 0);
			x++;
		}
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
