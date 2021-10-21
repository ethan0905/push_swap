/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_or_rra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:38:33 by esafar            #+#    #+#             */
/*   Updated: 2021/10/21 15:23:55 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
