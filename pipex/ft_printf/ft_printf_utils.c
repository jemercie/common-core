/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:34:43 by jemercie          #+#    #+#             */
/*   Updated: 2022/11/11 19:32:28 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_strncmp_char(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

int	ft_putchar_pf(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_pf(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_pf(int nb)
{
	int	size;

	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		size = 11;
		return (size);
	}
	size = ft_intlen((long int)nb);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_pf(nb / 10);
		ft_putnbr_pf(nb % 10);
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	return (size);
}
