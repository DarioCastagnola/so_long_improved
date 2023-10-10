/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:56:18 by dcastagn          #+#    #+#             */
/*   Updated: 2023/02/06 17:03:33 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

void	ft_putchar(char c, int *count);
int		ft_putnbr(int n, int *count);
void	ft_putsrc(char c, int *count, va_list ptr);
int		ft_printf(const char *src, ...);
int		ft_putstr(char *s, int *count);
int		ft_putbignbr(unsigned int n, int *count);
int		ft_hexsmall(unsigned int n, int *count);
int		ft_hexbig(unsigned int n, int *count);
int		ft_putaddress(unsigned long i, int *count);
int		ft_hexsmall_p(unsigned long n, int *count);

#endif
