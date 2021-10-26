/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:11:17 by esafar            #+#    #+#             */
/*   Updated: 2021/10/26 13:36:54 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	i = 0;
	while (str[i])
		i++;
	if (i == 0)
		return (-1);
	return (1);
}

int	check_if_only_numbers(int ac, char **av, long int *stack_a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_number(av[i]) < 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (free_(stack_a));
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int			i;
	long int	*stack_a;
	long int	*stack_b;

	if (check_if_only_numbers(ac, av, stack_a) < 0)
		return (-1);
	stack_a = malloc_init(stack_a, ac);
	if (!stack_a)
		return (-1);
	b_pas_zero(stack_a, ac);
	i = -1;
	while (++i < ac - 1)
		stack_a[i] = ft_atoi(av[i + 1]);
	if (check_tab(stack_a, (ac - 1)) == -1)
		return (ft_error(stack_a, 1));
	else if (ac == 1 || ac == 2 || already_sorted(stack_a, (ac - 1)) == -1)
		return (ft_error(stack_a, 0));
	stack_b = malloc_init(stack_b, ac);
	if (!stack_b)
		return (free_(stack_a));
	b_pas_zero(stack_b, ac);
	solve(stack_a, stack_b, ac);
	return (double_free(stack_a, stack_b));
}
