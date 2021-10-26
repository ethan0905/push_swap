/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:11:46 by esafar            #+#    #+#             */
/*   Updated: 2021/10/26 10:47:47 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	free_(long int *stack)
{
	free(stack);
	return (-1);
}

void	double_free(long int *fant_a, long int *fant_b)
{
	free(fant_a);
	free(fant_b);
}
