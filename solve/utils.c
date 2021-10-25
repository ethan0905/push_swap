/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:24:36 by esafar            #+#    #+#             */
/*   Updated: 2021/10/25 17:17:59 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long int *malloc_init(long int *tab, int ac)
{
	tab = (long int *)malloc(sizeof(long int) * (ac));
	if (!tab)
		return (NULL);
	return (tab);
}

void	b_pas_zero(long int *tab, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		tab[i] = 3000000000;
		i++;
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

long int	*sort_stack(long int *fant, t_data *data)
{
	int	i;
	int	j;
	int	tmp;

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

long int *copy_and_sort(long int *fant, long int *stack, t_data *data, int ac)
{
	copy_stack(fant, stack, ac);
	sort_stack(fant, data);
	return (fant);
}
