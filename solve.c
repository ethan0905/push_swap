/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 08:48:09 by esafar            #+#    #+#             */
/*   Updated: 2021/10/11 16:56:47 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_two(int *stackA)
{
	reverse_a(stackA, 1);
}

void	make_three(int *stackA)
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

void	make_four(int *stackA, int *stackB, int ac)
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

void	copy_stack(int *dest, int *src, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		dest[i] = src[i];
		i++;
	}
}

int *sort_stack(int *s_ghost, t_data *data)
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

void	high_five(int *stackA, int *stackB, int ac)
{
	int i;
	int count;
	t_data data;
	int s_ghost[1000] = {};
	int s_med[1000] = {};

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
	print_table(stackA, stackB);
	make_four(stackA, stackB, ac);
	push_a(stackA, stackB, ac, 1);
}
/*
void	make_all(int *stackA, int *stackB, int ac)
{
	int i;
	int z;
	int s_ghost[1000] = {};

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

int	ra_or_rra(int *stack, int elem, t_data *data)
{
	int	i;
	int fant[1000] = {};

	i = 0;
	copy_stack(fant, stack, data->ac);
	while (fant[0] != elem)
	{
		rotate_a(stack, 0);
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

void	push_b_only_bads(int *stackA, int *stackB, int *list, t_data *data)
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

int	min_is_in(int *stack, int min)
{
	int i;

	i = 0;
	while (stack[i] != 0)
	{
		if (stack[i] == min)
			return (1);
		i++;
	}
	return (0);
}

int	max_is_in(int *stack, int max)
{
	int i;

	i = 0;
	while (stack[i] != 0)
	{
		if (stack[i] == max)
			return (1);
		i++;
	}
	return (0);
}

void	insert_sort(int *stackA, int *stackB, t_data *data)
{
	int i;

	i = 0;
	while (data->remain_b > 0)
	{
		if (stackB[0] != data->min && min_is_in(stackB, data->min))
		{
			if (ra_or_rra(stackB, data->min, data) == 1)
			{
				while (stackB[0] != data->min)
					rotate_b(stackB, 1);
			}
			else if (ra_or_rra(stackB, data->min, data) == 2)
			{
				while (stackB[0] != data->min)
					reverse_b(stackB, 1);
			}
			push_a(stackA, stackB, data->ac, 1);
			data->remain_b--;
		}
		if (stackB[0] != data->max && max_is_in(stackB, data->max))
		{
			if (ra_or_rra(stackB, data->max, data) == 1)
			{
				while (stackB[0] != data->max)
					rotate_b(stackB, 1);
			}
			else if (ra_or_rra(stackB, data->max, data) == 2)
			{
				while (stackB[0] != data->max)
					reverse_b(stackB, 1);
			}
			push_a(stackA, stackB, data->ac, 1);
			data->remain_b--;
			rotate_a(stackA, 1);
//			print_table(stackA, stackB);
		}
		if (max_is_in(stackB, data->max) == 0 && min_is_in(stackB, data->min) == 0)
		{
//			printf("insert sort 2 printtable\n");
			i = 0;
			while (stackB[0] > stackA[0])
			{
				rotate_a(stackA, 1);
				i++;
			}
//			print_table(stackA, stackB);
//			printf("remain_b = %d, stackA[ac-2 - remain_b] = %d\n", data->remain_b, stackA[data->ac - 2 - data->remain_b]);
			if (stackB[0] < stackA[0] && stackB[0] > stackA[data->ac - 2 - data->remain_b])
				push_a(stackA, stackB, data->ac, 1);
			else if (stackB[0] < stackA[0] && stackB[0] < stackA[data->ac - 2 - data->remain_b])
			{
				while (stackB[0] < stackA[0] && stackB[0] < stackA[data->ac - 2 - data->remain_b])
					reverse_a(stackA, 1);
				push_a(stackA, stackB, data->ac, 1);
			}
//			print_table(stackA, stackB);
			while (i-- > 0)
				reverse_a(stackA , 1);
//			print_table(stackA, stackB);
			data->remain_b--;
		}
	}
	while (stackA[0] != data->min)
	{
		if (ra_or_rra(stackA, data->min, data) == 1)
			rotate_a(stackA, 1);
		else if (ra_or_rra(stackA, data->min, data) == 2)
			reverse_a(stackA, 1);
	}
}

void	make_all(int *stackA, int *stackB, int ac)
{
	int x;
	int v;
	int i;
	int j;
	t_data data;
	int tmp;
	int count;
	int start;
	int list[1000] = {};
	int s_ghost[1000] = {};
	int count_tmp;

	x = 0;
	initialize(&data, ac);
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
	//work to do : coder si RA ou RRA


	push_b_only_bads(stackA, stackB, list, &data);
//	print_table(stackA, stackB);

//	printf("remain b : %d\n", data.remain_b);
	insert_sort(stackA, stackB, &data);
//	print_table(stackA, stackB);
}

int 	solve(int *stackA, int *stackB, int ac)
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
