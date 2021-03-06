/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:18:24 by esafar            #+#    #+#             */
/*   Updated: 2021/11/03 14:43:24 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	verif_stack(long int *stack_a, long int *stack_b, t_data *data)
{
	int	i;

	if (data->tmp < 0)
		ft_putstr_fd("Error\n", 2);
	else if (already_sorted(stack_a, data->ac - 1) < 0)
	{
		i = 0;
		while (stack_b[i] != 3000000000)
			i++;
		if (i == 0)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	else if (already_sorted(stack_a, data->ac - 1) > 0)
		ft_putstr_fd("KO\n", 1);
	return (0);
}

void	do_operation(long int *stack_a, long int *stack_b, char
		*buff, t_data *data)
{
	if (compare(buff, "sa\n"))
		swap_a(stack_a, 0);
	else if (compare(buff, "sb\n"))
		swap_b(stack_b, 0);
	else if (compare(buff, "ss\n"))
		swap_ab(stack_a, stack_b, 0);
	else if (compare(buff, "ra\n"))
		rotate_a(stack_a, 0);
	else if (compare(buff, "rb\n"))
		rotate_b(stack_b, 0);
	else if (compare(buff, "rr\n"))
		rotate_ab(stack_a, stack_b, 0);
	else if (compare(buff, "rra\n"))
		reverse_a(stack_a, 0);
	else if (compare(buff, "rrb\n"))
		reverse_b(stack_b, 0);
	else if (compare(buff, "rrr\n"))
		reverse_ab(stack_a, stack_b, 0);
	else if (compare(buff, "pa\n"))
		special_push_a(stack_a, stack_b, data->ac, 0);
	else if (compare(buff, "pb\n"))
		special_push_b(stack_a, stack_b, data->ac, 0);
	else
		data->tmp = -1;
}

int	checker(long int *stack_a, long int *stack_b, int ac)
{
	int		i;
	int		op;
	t_data	data;
	char	buff[1000];

	initialize(&data, ac);
	data.ac = ac;
	data.tmp = 1;
	while (1)
	{
		i = 0;
		while (i == 0 || (i > 0 && buff[i - 1] != '\n'))
		{
			op = read(0, &buff[i], 1);
			i++;
			if (op < -1)
				return (-1);
			if (op == 0)
				return (verif_stack(stack_a, stack_b, &data));
		}
		buff[i] = 0;
		do_operation(stack_a, stack_b, buff, &data);
	}
}

int	main(int ac, char **av)
{
	int			i;
	long int	*stack_a;
	long int	*stack_b;

	if (check_if_only_numbers(ac, av) < 0)
		return (-1);
	stack_a = (long int *)malloc(sizeof(long int) * (ac + 1));
	if (!stack_a)
		return (-1);
	b_pas_zero(stack_a, ac);
	i = -1;
	while (++i < ac - 1)
		stack_a[i] = ft_atoi(av[i + 1]);
	if (check_tab(stack_a, (ac - 1)) == -1)
		return (ft_error(stack_a, 1));
	else if (ac == 1 || ac == 2)
		return (ft_error(stack_a, 0));
	stack_b = (long int *)malloc(sizeof(long int) * (ac + 1));
	if (!stack_b)
		return (free_(stack_a));
	b_pas_zero(stack_b, ac);
	checker(stack_a, stack_b, ac);
	return (double_free(stack_a, stack_b));
}
