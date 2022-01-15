/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltacos <ltacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 06:36:06 by ltacos            #+#    #+#             */
/*   Updated: 2021/12/19 04:56:04 by ltacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static size_t	ft_strlen(const char *s)
{
	const char	*ps;

	ps = s;
	while (*ps)
		ps++;
	return ((size_t)(ps - s));
}

int	ft_putendl(char *s)
{
	if (s != NULL && write(1, s, ft_strlen(s)))
		return ((int)ft_strlen(s));
	else if (s == NULL && write(1, "(null)", 6))
		return (6);
	return (0);
}
