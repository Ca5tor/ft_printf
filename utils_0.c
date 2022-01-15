/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltacos <ltacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:18:46 by ltacos            #+#    #+#             */
/*   Updated: 2021/12/19 04:47:47 by ltacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num_hex_0(char a, unsigned int num, int i)
{	
	int			rem;

	if (num == 0)
		return (i);
	rem = num % 16;
	i = ft_num_hex_0(a, num / 16, i);
	if (rem <= 9)
		ft_putchar('0' + rem);
	else
		ft_putchar(a + (rem - 10));
	i++;
	return (i);
}

int	ft_num_hex(char a, unsigned int num)
{
	int	i;

	i = 0;
	if (a == 'X')
		a = 'A';
	else
		a = 'a';
	if (num == 0 && ++i)
		ft_putchar('0');
	else
		i += ft_num_hex_0(a, num, 0);
	return (i);
}

static int	ft_num_hex_0_p(char a, unsigned long num, int i)
{	
	int			rem;

	if (num == 0)
		return (i);
	rem = num % 16;
	i = ft_num_hex_0_p(a, num / 16, i);
	if (rem <= 9)
		ft_putchar('0' + rem);
	else
		ft_putchar(a + (rem - 10));
	i++;
	return (i);
}

static int	ft_num_hex_p(char a, unsigned long num)
{
	int	i;

	i = 0;
	if (a == 'X')
		a = 'A';
	else
		a = 'a';
	i += ft_num_hex_0_p(a, num, 0);
	return (i);
}

int	ft_print_p(va_list ap)
{
	int				i;
	unsigned long	temp;

	i = 0;
	temp = va_arg(ap, unsigned long);
	i += ft_putendl("0x");
	if (temp == 0 && ++i)
		ft_putchar('0');
	else
		i += ft_num_hex_p('a', temp);
	return (i);
}
