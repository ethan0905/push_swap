/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 08:48:09 by esafar            #+#    #+#             */
/*   Updated: 2021/10/19 16:30:50 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_two(long int *stackA)
{
	reverse_a(stackA, 1);
}

void	make_three(long int *stackA)
{
	if (stackA[0] < stackA[1])
	{
		if (stackA[0] < stackA[2])
		{
			swap_a(stackA, 1);
			rotate_a(stackA, 1);
		}
		else
			reverse_a(stackA, 1);
	}
	else if (stackA[0] > stackA[1])
	{
		if (stackA[1] > stackA[2])
		{
			swap_a(stackA, 1);
			reverse_a(stackA, 1);
		}
		else if (stackA[0] < stackA[2])
			swap_a(stackA, 1);
		else
			rotate_a(stackA, 1);
	}
}

void	make_four(long int *stackA, long int *stackB, int ac)
{
	//cas commencant par quatre
	if (stackA[0] > stackA[1] && stackA[0] > stackA[2] && stackA[0] > stackA[3])
	{
		if (stackA[2] > stackA[3] && stackA[1] < stackA[3])
		{
			reverse_a(stackA, 1);
			reverse_a(stackA, 1);
			swap_a(stackA, 1);
			reverse_a(stackA, 1);
		}
		else if (stackA[2] > stackA[3] && stackA[1] > stackA[3] && stackA[1] < stackA[2])
		{
			reverse_a(stackA, 1);
			swap_a(stackA, 1);
			rotate_a(stackA, 1);
		}
		else if (stackA[1] < stackA[2] && stackA[2] < stackA[3])
			rotate_a(stackA, 1);
		else if (stackA[1] > stackA[2] && stackA[1] > stackA[3])
		{
			if (stackA[2] < stackA[3])
			{
				swap_a(stackA, 1);
				rotate_a(stackA, 1);
				rotate_a(stackA, 1);
			}
			else
			{
				swap_a(stackA, 1);
				reverse_a(stackA, 1);
				reverse_a(stackA, 1);
				swap_a(stackA, 1);
			}
		}
		else if (stackA[2] < stackA[1] && stackA[1] < stackA[3])
		{
			rotate_a(stackA, 1);
			swap_a(stackA, 1);
		}
	}
	//cas commencant par un
	else if (stackA[0] < stackA[1] && stackA[0] < stackA[2] && stackA[0] < stackA[3])
	{
		if (stackA[1] < stackA[3] && stackA[3] < stackA[2])
		{	
			reverse_a(stackA, 1);
			reverse_a(stackA, 1);
			swap_a(stackA, 1);				
			reverse_a(stackA, 1);
			reverse_a(stackA, 1);
		}
		else if (stackA[1] < stackA[3] && stackA[3] > stackA[2])
		{
			rotate_a(stackA, 1);
			swap_a(stackA, 1);				
			reverse_a(stackA, 1);
		}
		else if (stackA[1] > stackA[3] && stackA[3] < stackA[2] && stackA[1] < stackA[2])
		{
			reverse_a(stackA, 1);
			swap_a(stackA, 1);			
		}
		else if (stackA[1] > stackA[2] && stackA[1] > stackA[3])
		{
			if (stackA[2] < stackA[3])
			{
				reverse_a(stackA, 1);
				swap_a(stackA, 1);	
				reverse_a(stackA, 1);
				swap_a(stackA, 1);			
			}
			else
			{
				push_b(stackA, stackB, ac, 1);
				swap_a(stackA, 1);	
				reverse_a(stackA, 1);
				push_a(stackA, stackB, ac, 1);
			}
		}
	}
	//cas commencant par deux
	// 2 1 X X
	else if (stackA[0] > stackA[1] && stackA[0] < stackA[2] && stackA[0] < stackA[3])
	{
		if (stackA[2] < stackA[3])
			swap_a(stackA, 1);	
		else
		{
			push_b(stackA, stackB, ac, 1);
			push_b(stackA, stackB, ac, 1);
			swap_ab(stackA, stackB, 1);	
			push_a(stackA, stackB, ac, 1);
			push_a(stackA, stackB, ac, 1);
		}
	}
	// 2 4 X X
	else if (stackA[0] < stackA[1] && stackA[1] > stackA[2] && stackA[1] > stackA[3] && (stackA[0] < stackA[2] || stackA[0] < stackA[3]))
	{
		if (stackA[2] < stackA[3])
		{
			swap_a(stackA, 1);	
			rotate_a(stackA, 1);
			swap_a(stackA, 1);	
		}
		else
		{
			rotate_a(stackA, 1);
			swap_a(stackA, 1);	
			rotate_a(stackA, 1);
			rotate_a(stackA, 1);
		}
	}
	// 2 3 X X
	else if (stackA[0] < stackA[1] && (stackA[1] < stackA[2] || stackA[1] < stackA[3]))
	{
		if (stackA[2] < stackA[3])
		{
			rotate_a(stackA, 1);
			rotate_a(stackA, 1);
			swap_a(stackA, 1);	
			rotate_a(stackA, 1);
		}
		else
			reverse_a(stackA, 1);
	}
	//cas commencant par trois
	// 3 4 X X
	else if (stackA[0] < stackA[1] && stackA[0] > stackA[2] && stackA[0] > stackA[3])
	{
		rotate_a(stackA, 1);
		rotate_a(stackA, 1);
		if (stackA[0] > stackA[1])
			swap_a(stackA, 1);
	}
	// 3 1 X X
	else if (stackA[0] > stackA[1] && stackA[1] < stackA[2] && stackA[1] < stackA[3])
	{
		if (stackA[2] < stackA[3])
		{
			reverse_a(stackA, 1);
			swap_a(stackA, 1);	
			rotate_a(stackA, 1);
			rotate_a(stackA, 1);
		}
		else
		{
			swap_a(stackA, 1);	
			reverse_a(stackA, 1);
			swap_a(stackA, 1);	
		}
	}
	// 3 2 X X
	else if (stackA[0] > stackA[1] && (stackA[1] < stackA[2] || stackA[1] < stackA[3]))
	{
		if (stackA[2] < stackA[3])
		{
			reverse_a(stackA, 1);
			swap_a(stackA, 1);	
			rotate_a(stackA, 1);
			rotate_a(stackA, 1);
			swap_a(stackA, 1);	
		}
		else
		{
			swap_a(stackA, 1);	
			reverse_a(stackA, 1);
		}
	}
}

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

long int *sort_stack(long int *s_ghost, t_data *data)
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
			if (s_ghost[j] < s_ghost[i])
			{
				tmp = s_ghost[j];
				s_ghost[j] = s_ghost[i];
				s_ghost[i] = tmp;
			}
			j++;
		}
		i++;
	}
	data->min = s_ghost[0];
	data->max = s_ghost[data->ac - 2];
	return (s_ghost);
}

void	high_five(long int *stackA, long int *stackB, int ac)
{
	int i;
	int count;
	t_data data;
	long int s_ghost[1000] = {};
	long int s_med[1000] = {};

	i = 0;
	copy_stack(s_ghost, stackA, ac);
	copy_stack(s_med, stackA, ac);
	sort_stack(s_ghost, &data);
	count = 0;
	//regarder si RA ou RRA
	while  (i < (ac - 1) && (s_med[0] != s_ghost[0]))
	{
		rotate_a(s_med, 0);
		count++;
		if (count > ((ac - 1) /2))
		{
			count = 0;
			break ;
		}
		i++;
	}
	while (i < (ac - 1) && (stackA[0] != s_ghost[0]) && count > 0)
	{
		rotate_a(stackA, 1);
		i++;
	}
	while  (i < (ac - 1) && (stackA[0] != s_ghost[0]) && count == 0)
	{
		reverse_a(stackA, 1);
		i++;
	}
	push_b(stackA, stackB, ac, 1);
	make_four(stackA, stackB, ac);
	push_a(stackA, stackB, ac, 1);
}
/* // algo de tri utilisant un stack fantome trie
void	make_all(long int *stackA, long int *stackB, int ac)
{
	int i;
	int z;
	long int s_ghost[1000] = {};

	i = 0;
	copy_stack(s_ghost, stackA, ac);
	sort_stack(s_ghost, ac);
	while (i < (ac - 1))
	{
		push_b(stackA, stackB, ac, 1);
		i++;
	}
	z = ac - 2;
	while (z > 0)
	{
		if (stackB[0] != 0)
		{
			while (stackB[0] != s_ghost[z])
				rotate_b(stackB, 1);
			push_a(stackA, stackB, ac, 1);
		}
		z--;
	}
	push_a(stackA, stackB, ac, 1);
}
*/

int	ra_or_rra(long int *stack, int elem, t_data *data)
{
	int	i;
	long int fant[1000] = {};

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

void	push_b_only_bads(long int *stackA, long int *stackB, long int *list, t_data *data)
{
	int j;

	j = 0;
	if (ra_or_rra(stackA, list[0], data) == 1)
	{
		while (stackA[0] != list[0])
			rotate_a(stackA, 1);
	}
	else if (ra_or_rra(stackA, list[0], data) == 2)
	{
		while (stackA[0] != list[0])
			reverse_a(stackA, 1);
	}
	while (j < data->count_tmp)
	{
		while (stackA[0] != list[j])
		{
			push_b(stackA, stackB, data->ac, 1);
			data->remain_b++;
		}
		if (stackA[0] == list[j])
		{
			rotate_a(stackA, 1);
			j++;
		}
	}
	while (j + data->remain_b < (data->ac - 1))
	{
		push_b(stackA, stackB, data->ac, 1);
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

void	find_min_and_max_in_stack(long int *stackA, long int *stackB, t_data *data)
{
	int i;
	long int tmp;

	i = 0;
	tmp = 3000000000;
	//find min
	while (stackA[i] != 3000000000)
	{
		if (stackA[i] < tmp)
			tmp = stackA[i];
		i++;
	}
	data->min_du_stack = tmp;
	//find max
	i = 0;
	tmp = -3000000000;
	while (stackA[i] != 3000000000)
	{
		if (stackA[i] > tmp)
			tmp = stackA[i];
		i++;
	}
	data->max_du_stack = tmp;
}

int check_count(long int *stackA, long int *stackB, long int value, t_data *data)
{
	int ca, cb;
	int i;
	int remain_a;
	long int fantA[1000] = {};
	long int fantB[1000] = {};

	b_pas_zero(fantA);
	copy_stack(fantA, stackA, data->ac);
	b_pas_zero(fantB);
	copy_stack(fantB, stackB, data->ac);

	//part 1 : recuperer ma median ainsi que la taille de mon stackA
	remain_a = data->ac-1-data->remain_b;
	data->medA = remain_a/2;
	data->medB = data->remain_b/2;

	//part 2 : trouver mon min et max de A actuel
	find_min_and_max_in_stack(fantA, fantB, data);

	//part 3 : compter
	cb = 0;
	while (fantB[cb] != value)
	{
		cb++;
		data->rb_tmp = 1;
		data->rrb_tmp = 0;
		if (cb > data->medB)
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
		while (fantB[data->remain_b - 1 - cb] != value)
			cb++;
		cb++;
	}

	//deuxieme partie de l'algo:chercher le chemin le plus court pour placer stackB[0]
	ca = 0;
	if (value < data->min_du_stack)
	{
		data->ra_tmp = 1;
		data->rra_tmp = 0;
		while (fantA[ca] != data->min_du_stack)
			ca++;
		if (ca > data->medA)
			ca = -1;
		if (ca < 0)
		{
			ca = 0;
			data->ra_tmp = 0;
			data->rra_tmp = 1;
			while (fantA[remain_a-1-ca] != data->max_du_stack)
				ca++;
		}
	}
	else if (value > data->max_du_stack)
	{
		data->ra_tmp = 1;
		data->rra_tmp = 0;
		while (fantA[ca] != data->min_du_stack)
			ca++;
		if (ca > data->medA)
			ca = -1;
		if (ca < 0)
		{
			ca = 0;
			data->ra_tmp = 0;
			data->rra_tmp = 1;
			while (fantA[remain_a - 1 - ca] != data->min_du_stack)
				ca++;
			ca++;
		}
	}
	else if (value > fantA[ca])
	{

		if (value < data->max_du_stack)
		{
			data->ra_tmp = 1;
			data->rra_tmp = 0;
			while (value > fantA[ca])
				ca++;
			if (ca > data->medA)
				ca = -1;
			if (ca < 0)
			{
				ca = 0;
				data->ra_tmp = 0;
				data->rra_tmp = 1;
				if (value > fantA[remain_a - 1 - ca])
				{
					while (value > fantA[remain_a - 1 - ca])
						ca++;
					while (value < fantA[remain_a - 1 - ca])
						ca++;
				}
				else
				{
					while (value < fantA[remain_a - 1 - ca])
						ca++;
				}
			}
		}
	}
	else if (value < fantA[ca])
	{
		data->ra_tmp = 1;
		data->rra_tmp = 0;
		while (value < fantA[ca])
			ca++;
		while (value > fantA[ca])
			ca++;
		if (ca > data->medA)
			ca = -1;
		if (ca < 0)
		{
			ca = 0;
			data->ra_tmp = 0;
			data->rra_tmp = 1;
			while (value < fantA[remain_a - 1 - ca])
				ca++;
		}
	}
	return (ca+cb+1);
}

void	push_best_nb(long int *stackA, long int *stackB, t_data *data, int to_push)
{
	while (stackB[0] != to_push && data->count_tmp > 1)
	{
		if (data->rb == 1 && data->rrb == 0)
			rotate_b(stackB, 1);
		else if (data->rrb == 1 && data->rb == 0)
			reverse_b(stackB, 1);
		data->count_tmp--;
	}
	while (data->count_tmp > 1)
	{
		if (data->ra == 1 && data->rra == 0)
			rotate_a(stackA, 1);
		else if (data->ra == 0 && data->rra == 1)
			reverse_a(stackA, 1);
		data->count_tmp--;
	}
	push_a(stackA, stackB, data->ac, 1);
}

void	insert_sort(long int *stackA, long int *stackB, t_data *data)
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
			data->count_tmp = check_count(stackA, stackB, stackB[i], data);
			if (data->count_tmp < tmp)
			{
				data->ra = data->ra_tmp;
				data->rb = data->rb_tmp;
				data->rra = data->rra_tmp;
				data->rrb = data->rrb_tmp;
				tmp = data->count_tmp;
				to_push = stackB[i]; // avant : tmp = stackB[0], une erreur a 35 000 operations
			}
			i++;
		}
		data->count_tmp = tmp;
		push_best_nb(stackA, stackB, data, to_push);
		data->remain_b--;
	}
	while (stackA[0] != data->min)
	{
		if (ra_or_rra(stackA, data->min, data) == 1)
			rotate_a(stackA, 1);
		else if (ra_or_rra(stackA, data->min, data) == 2)
			reverse_a(stackA, 1);
	}
}

void	make_all(long int *stackA, long int *stackB, int ac)
{
	int x;
	int v;
	int i;
	int j;
	t_data data;
	int tmp;
	int count;
	int start;
	long int list[1000] = {};
	long int s_ghost[1000] = {};
	int count_tmp;

	x = 0;
	initialize(&data, ac);
	b_pas_zero(list);
	b_pas_zero(s_ghost);
	copy_stack(s_ghost, stackA, ac);
	sort_stack(s_ghost, &data);
	count_tmp = 0;
	while (x < ((data.ac) - 1))
	{
		if (stackA[x])
		{
			i = 0;
			while (i < ((data.ac) - 1))
			{
				count = 1;
				j = i + 1;
				tmp = stackA[0];
				while (j < ((data.ac) - 1))
				{
					while (tmp < stackA[j + 1] && stackA[j + 1] < stackA[j])
						j++;
					if (tmp < stackA[j])
					{
						tmp = stackA[j];
						count++;
					}
					j++;
				}
				if (data.count_tmp < count)
				{
					start = stackA[0];
					data.count_tmp = count;
					list[0] = stackA[0];
					
					v = 1;
					tmp = stackA[0];
					j = i + 1;
					while (j < ((data.ac) - 1))
					{
						while (tmp < stackA[j + 1] && stackA[j + 1] < stackA[j])
							j++;
						if (tmp < stackA[j])
						{
							tmp = stackA[j];
							list[v] = tmp;
							v++;
						}
						j++;
					}
				}	
				i++;
			}
			rotate_a(stackA, 0);
			x++;
		}
		else
		{
			rotate_a(stackA, 0);
			x++;
		}
	}
	push_b_only_bads(stackA, stackB, list, &data);
	insert_sort(stackA, stackB, &data);
}

int 	solve(long int *stackA, long int *stackB, int ac)
{
	if ((ac - 1) == 2)
		make_two(stackA);
	if ((ac - 1) == 3)
		make_three(stackA);
	if ((ac - 1) == 4)
		make_four(stackA, stackB, ac);
	if ((ac - 1) == 5)
		high_five(stackA, stackB, ac);
	if ((ac - 1) >= 6)
		make_all(stackA, stackB, ac);
	return (1);
}
