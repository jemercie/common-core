/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:57:52 by jemercie          #+#    #+#             */
/*   Updated: 2022/11/09 20:31:09 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthexa_low(unsigned long int nb)
{
	int	size;

	if (!nb)
	{
		write(1, "0", 1);
		return (1);
	}
	size = ft_intlen_hexa(nb);
	if (nb >= 16)
	{
		ft_puthexa_low(nb / 16);
		ft_puthexa_low(nb % 16);
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	if (nb >= 10 && nb < 16)
		ft_putchar(nb - 10 + 'a');
	return (size);
}
