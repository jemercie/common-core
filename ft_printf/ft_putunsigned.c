/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:39:01 by jemercie          #+#    #+#             */
/*   Updated: 2022/11/08 11:41:17 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunsigned(unsigned int nb)
{
	int	size;

	if (!nb)
	{
		write(1, "0", 1);
		return (1);
	}
	size = ft_intlen(nb);
	if (nb >= 10)
	{
		ft_putunsigned(nb / 10);
		ft_putunsigned(nb % 10);
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	return (size);
}
