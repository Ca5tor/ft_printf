/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltacos <ltacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:18:59 by ltacos            #+#    #+#             */
/*   Updated: 2021/12/19 05:01:31 by ltacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_replace_spec_ch(const char *fmt, va_list ap)
{
	int	i;

	i = 0;
	if (*fmt == 'c' && ++i)
		ft_putchar(va_arg(ap, int));
	else if (*fmt == 's')
		i = ft_putendl(va_arg(ap, char *));
	else if (*fmt == 'p')
		i = ft_print_p(ap);
	else if (*fmt == 'd' || *fmt == 'i')
		i = ft_itoa_print(va_arg(ap, int), 0);
	else if (*fmt == 'u')
		i = ft_itoa_u_print(va_arg(ap, unsigned int), 0);
	else if (*fmt == 'x' || *fmt == 'X')
		i = ft_num_hex(*fmt, va_arg(ap, int));
	else if (*fmt == '%' && ++i)
		write(1, "%", 1);
	return (i);
}

static int	ft_spec_ch(char ch)
{
	static char	sim[10] = "cspdiuxX%";
	int			i;

	i = 0;
	while (9 > i)
	{
		if (sim[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_pars(const char *fmt, va_list ap)
{
	int	i;

	i = 0;
	while (*fmt)
	{
		if (*fmt == '%' && ft_spec_ch(*(fmt + 1)) == 1 && ++fmt)
			i += ft_replace_spec_ch(fmt++, ap);
		else
		{
			ft_putchar(*(fmt++));
			i++;
		}
	}
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, fmt);
	if (!fmt)
		return (-1);
	i = ft_pars(fmt, ap);
	va_end(ap);
	return (i);
}
