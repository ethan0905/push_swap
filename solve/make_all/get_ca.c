/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ca.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:10:06 by esafar            #+#    #+#             */
/*   Updated: 2021/10/22 08:27:24 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	under_min_of_stack(long int *fant_a, t_data *data, int ca, int remain_a)
{
	data->ra_tmp = 1;
	data->rra_tmp = 0;
	while (fant_a[ca] != data->min_du_stack)
		ca++;
	if (ca > data->med_a)
		ca = -1;
	if (ca < 0)
	{
		ca = 0;
		data->ra_tmp = 0;
		data->rra_tmp = 1;
		while (fant_a[remain_a - 1 - ca] != data->max_du_stack)
			ca++;
	}
	return (ca);
}

int	superior_to_max_of_stack(long int *fant_a,
		t_data *data, int ca, int remain_a)
{
	data->ra_tmp = 1;
	data->rra_tmp = 0;
	while (fant_a[ca] != data->min_du_stack)
		ca++;
	if (ca > data->med_a)
		ca = -1;
	if (ca < 0)
	{
		ca = 0;
		data->ra_tmp = 0;
		data->rra_tmp = 1;
		while (fant_a[remain_a - 1 - ca] != data->min_du_stack)
			ca++;
		ca++;
	}
	return (ca);
}

int	increase_count(long int *fant_a, int value, int ca, int remain_a)
{
	while (value > fant_a[remain_a - 1 - ca])
		ca++;
	while (value < fant_a[remain_a - 1 - ca])
		ca++;
	return (ca);
}

int	under_max_of_stack(long int *fant_a, t_data *data, int value, int remain_a)
{
	int	ca;

	ca = 0;
	data->ra_tmp = 1;
	data->rra_tmp = 0;
	while (value > fant_a[ca])
		ca++;
	if (ca > data->med_a)
		ca = -1;
	if (ca < 0)
	{
		ca = 0;
		data->ra_tmp = 0;
		data->rra_tmp = 1;
		if (value > fant_a[remain_a - 1 - ca])
			ca = increase_count(fant_a, value, ca, remain_a);
		else
		{
			while (value < fant_a[remain_a - 1 - ca])
				ca++;
		}
	}
	return (ca);
}

int	under_top_of_stack(long int *fant_a, t_data *data, int value, int remain_a)
{
	int	ca;

	ca = 0;
	data->ra_tmp = 1;
	data->rra_tmp = 0;
	while (value < fant_a[ca])
		ca++;
	while (value > fant_a[ca])
		ca++;
	if (ca > data->med_a)
		ca = -1;
	if (ca < 0)
	{
		ca = 0;
		data->ra_tmp = 0;
		data->rra_tmp = 1;
		while (value < fant_a[remain_a - 1 - ca])
			ca++;
	}
	return (ca);
}
