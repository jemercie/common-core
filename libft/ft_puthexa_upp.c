/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_caps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:18:51 by jemercie          #+#    #+#             */
/*   Updated: 2022/11/08 11:18:59 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexa_upp(long long int nb)
{
	int	ret;

	ret = 0;
	if (!nb)
		return (0);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 16)
	{
		ft_puthexa_upp(nb / 16);
		ft_puthexa_upp(nb % 16);
	}
	if  (nb < 10)
		ft_putchar(nb + '0');
	if (nb > 10 && nb < 16)
	{
		ft_putchar(nb - 10 + 'A');
		ret += 1;
	}
	return (ret);
}
