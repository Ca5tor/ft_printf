/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltacos <ltacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:53:50 by ltacos            #+#    #+#             */
/*   Updated: 2021/12/19 04:54:55 by ltacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(char c);
int		ft_printf(const char *fmt, ...);
int		ft_putendl(char *s);
int		ft_num_hex(char a, unsigned int num);
int		ft_itoa_print(int n, int i);
int		ft_itoa_u_print(unsigned int n, int i);
int		ft_print_p(va_list ap);

#endif