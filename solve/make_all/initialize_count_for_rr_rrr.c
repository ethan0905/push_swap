/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_count_for_rr_rrr.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:31:21 by esafar            #+#    #+#             */
/*   Updated: 2021/10/21 11:32:56 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	initialize_count_for_rr_rrr(t_data *data)
{
	data->count_ra = 0;
	data->count_rb = 0;
	data->count_rra = 0;
	data->count_rrb = 0;
	return (data->count_tmp);
}
