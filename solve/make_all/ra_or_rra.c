/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_or_rra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:38:33 by esafar            #+#    #+#             */
/*   Updated: 2021/10/27 11:44:06 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ra_or_rra(long int *stack, int elem, t_data *data)
{
	int			i;
	long int	*fant;

	i = 0;
	fant = (long int *)malloc(sizeof(long int) * data->ac);
	b_pas_zero(fant, data->ac);
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
	free(fant);
	if (i == -1)
		return (2);
	if (i >= 0)
		return (1);
	return (0);
}
