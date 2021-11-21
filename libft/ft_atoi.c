/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 10:53:24 by esafar            #+#    #+#             */
/*   Updated: 2021/10/31 12:46:48 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\n'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_isnumber(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_issymbol(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

long int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long int		res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issymbol(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isnumber(str[i]))
	{
		res = res * 10 + (long int)(str[i] - '0');
		i++;
	}
	return ((long int)sign * res);
}
