/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_dbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 23:27:56 by altikka           #+#    #+#             */
/*   Updated: 2022/05/26 00:01:51 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static long double	ft_powl(long double x, long double y)
{
	long double		n;

	n = 1;
	while (y-- > 0)
		n *= x;
	return (n);
}

long double	round_dbl(long double val, unsigned int preci)
{
	long double		temp;
	long double		pow;
	unsigned int	i;
	unsigned long	whl;

	pow = ft_powl(0.1, preci);
	temp = val;
	i = 0;
	while (i++ < preci)
	{
		whl = temp;
		temp -= whl;
		temp *= 10;
	}
	whl = temp;
	temp -= whl;
	if (temp == 0.5)
	{
		if (whl % 2 != 0)
			val = val + pow - (pow * 0.1);
	}
	else if (temp > 0.5)
		val = val + pow - (pow * 0.1);
	return (val);
}
