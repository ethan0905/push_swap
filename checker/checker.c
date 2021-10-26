/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:18:24 by esafar            #+#    #+#             */
/*   Updated: 2021/10/26 16:01:17 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	compare(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] = 0 && s2[i] == 0)
		return (1);
	return (0);
}

void	do_operation(long int *stack_a, long int *stack_b, char *buff, int ac)
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
		push_a(stack_a, stack_b, ac, 0);
	else if (compare(buff, "pb\n"))
		push_b(stack_a, stack_b, ac, 0);
}

void	checker(long int *stack_a, long int *stack_b, int ac)
{
	int		i;
	int		op;
	char	buff[1000];

	while (1)
	{
		i = 0;
		while (i == 0 || (i > 0 && buff[i-1] != '\n'))
		{
			op = read(0, &buff[i], 1);
			i++;
			if (op < -1)
				return (-1);
			if (op == 0)
				return (verif_stack(stack_a, stack_b));
		}
		buff[i] = 0;
		do_operation(stack_a, stack_b, buff, ac);
	}
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
	checker(stack_a, stack_b, ac);
	return (double_free(stack_a, stack_b));
}
