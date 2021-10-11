/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:11:17 by esafar            #+#    #+#             */
/*   Updated: 2021/10/11 16:59:57 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	initialize(t_data *data, int ac)
{
  data->ac = ac;
	data->count_tmp = 0;
	data->remain_b = 0;
	data->min = 0;
	data->max = 0;
}

int	already_sorted(int *stackA, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stackA[i] < stackA[i + 1])
			i++;
		else if (!stackA[i + 1])
			return (-1);
		else
			return (1);
	}
	return (-1);
}

int check_tab(int *stackA, int size)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stackA[i] == stackA[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_table(int *stackA, int *stackB)
{
	int i;
	int j;
	int diff;
	int j2;
	int diff2;

	i = 0;
	printf("\n||            ||            ||\n");
	while (stackA[i] != 0 || stackB[i] != 0)
	{
		diff = 7 - ft_strlen((ft_itoa(stackA[i])));
		j = diff - 1;
		printf("||    [%d]", stackA[i]);
		while (j-- > 0)
			printf(" ");
		printf("||");
		printf("    [%d]", stackB[i]);
		diff2 = 7 - ft_strlen((ft_itoa(stackB[i])));
		j2 = diff2 - 1;
		while (j2-- > 0)
			printf(" ");
		printf("||\n");
		i++;
	}
	printf("==============================\n     STACK A       STACK B\n");
}

int	main(int ac, char **av)
{
	int	i;
	int stackA[1000] = {};
	int stackB[1000] = {};

	i = 0;
	while (i < ac - 1)
	{
		if (ft_atoi(av[i + 1]))
			stackA[i] = ft_atoi(av[i + 1]);
		else
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		i++;
	}
	if (check_tab(stackA, (ac - 1)) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	else if (ac == 1 || ac == 2 || already_sorted(stackA, (ac - 1)) == -1)
		return (-1);
//print_table(stackA, stackB);
	solve(stackA, stackB, ac);
//print_table(stackA, stackB);
	return (0);
}
