/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:14:42 by jemercie          #+#    #+#             */
/*   Updated: 2022/11/09 01:15:14 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_strncmp_char(char c, char *set);
int	ft_putchar_pf(int c);
int	ft_putstr_pf(char *str);
int	ft_putnbr_pf(int nb);
int	ft_putptr(unsigned long int nb);
int	ft_puthexa_low(unsigned long int nb);
int	ft_puthexa_upp(unsigned int nb);
int	ft_putunsigned(unsigned int nb);
int	ft_intlen_hexa(unsigned long int nb);

#endif
