/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltacos <ltacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:19:12 by ltacos            #+#    #+#             */
/*   Updated: 2021/12/18 06:38:14 by ltacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	return (n);
}

int	ft_itoa_print(int n, int i)
{
	if (n / 10 != 0)
		i = ft_itoa_print(n / 10, i);
	else if (n < 0 && write(1, "-", 1))
		i++;
	i++;
	ft_putchar(ft_abs(n % 10) + '0');
	return (i);
}

int	ft_itoa_u_print(unsigned int n, int i)
{
	if (n / 10 != 0)
		i = ft_itoa_u_print(n / 10, i);
	i++;
	ft_putchar(ft_abs(n % 10) + '0');
	return (i);
}
