/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:57:52 by jemercie          #+#    #+#             */
/*   Updated: 2022/11/08 11:17:04 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_puthexa_low(long long int nb)
{
	int	ret;

	ret = 2;
	if (ret == 2)
		write(1, "0x", 2);
	if (!nb)
		return (0);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 16)
	{
		ft_puthexa_low(nb / 16);
		ft_puthexa_low(nb % 16);
	}
	if  (nb < 10)
		ft_putchar(nb + '0');
	if (nb > 10 && nb < 16)
	{
		ft_putchar(nb - 10 + 'a');
		ret += 1;
	}
	return (ret);
}
