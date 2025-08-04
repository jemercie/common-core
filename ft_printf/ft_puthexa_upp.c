/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_upp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:18:51 by jemercie          #+#    #+#             */
/*   Updated: 2022/11/09 20:33:08 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthexa_upp(unsigned int nb)
{
	int	size;

	if (!nb)
	{
		write(1, "0", 1);
		return (1);
	}
	size = ft_intlen_hexa((unsigned long int)nb);
	if (nb >= 16)
	{
		ft_puthexa_upp(nb / 16);
		ft_puthexa_upp(nb % 16);
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	if (nb >= 10 && nb < 16)
		ft_putchar(nb - 10 + 'A');
	return (size);
}
