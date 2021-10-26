/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rfx_or_rrfx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:50:36 by esafar            #+#    #+#             */
/*   Updated: 2021/10/26 13:51:23 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

long int	*rfb_or_rrfb(long int *fant_b, t_data *data)
{
	if (data->rb == 1 && data->rrb == 0)
	{
		rotate_b(fant_b, 0);
		data->count_rb++;
	}
	else if (data->rrb == 1 && data->rb == 0)
	{
		reverse_b(fant_b, 0);
		data->count_rrb++;
	}
	data->tmp_tmp--;
	return (fant_b);
}

long int	*rfa_or_rrfa(long int *fant_a, t_data *data)
{
	if (data->ra == 1 && data->rra == 0)
	{
		rotate_a(fant_a, 0);
		data->count_ra++;
	}
	else if (data->ra == 0 && data->rra == 1)
	{
		reverse_a(fant_a, 0);
		data->count_rra++;
	}
	data->tmp_tmp--;
	return (fant_a);
}
