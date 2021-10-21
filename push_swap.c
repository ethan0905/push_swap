/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:11:17 by esafar            #+#    #+#             */
/*   Updated: 2021/10/21 17:27:04 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

void	print_table(long int *stack_a, long int *stack_b)
{
	int	i;
	int	j;
	int	diff;
	int	j2;
	int	diff2;

	i = 0;
	printf("\n||                   ||                   ||\n");
	while (stack_a[i] != 3000000000 || stack_b[i] != 3000000000)
	{
		if (stack_a[i] < 2999999999)
			diff = 15 - ft_strlen((ft_itoa(stack_a[i]))) - 1;
		else if (stack_a[i] == 3000000000)
			diff = 15 - ft_strlen((ft_itoa(stack_a[i])));
		j = diff - 1;
		printf("||    [%ld]", stack_a[i]);
		while (j-- > 0)
			printf(" ");
		printf("||");
		printf("    [%ld]", stack_b[i]);
		diff2 = 15 - ft_strlen((ft_itoa(stack_b[i])));
		j2 = diff2 - 2;
		while (j2-- > 0)
				printf(" ");
		printf("||\n");
		i++;
	}
	printf("===========================================\n");
	printf(" 		STACK A               STACK B\n");
}

void	b_pas_zero(long int *tab)
{
	int	i;

	i = 0;
	while (i < 502)
	{
		tab[i] = 3000000000;
		i++;
	}
}

int	main(int ac, char **av)
{
	int			i;
	long int	stack_a[502];
	long int	stack_b[502];

	i = 0;
	b_pas_zero(stack_a);
	b_pas_zero(stack_b);
	while (i < ac - 1)
	{
		if (ft_atoi(av[i + 1]) || ft_atoi(av[i + 1]) == 0)
			stack_a[i] = ft_atoi(av[i + 1]);
		else
			ft_error();
		i++;
	}
	if (check_tab(stack_a, (ac - 1)) == -1)
		ft_error();
	else if (ac == 1 || ac == 2 || already_sorted(stack_a, (ac - 1)) == -1)
		return (-1);
	solve(stack_a, stack_b, ac);
	return (0);
}
