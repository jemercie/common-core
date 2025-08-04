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
#include "libft.h"

int ft_putunsigned(unsigned long int nb)
{
	int	ret;

	ret = 0;
	if (!nb)
		return (0);
	if (nb > 16)
	{
		ft_putunsigned(nb / 10);
		ft_putunsigned(nb % 10);
	}
	if  (nb < 10)
	{
		ft_putchar(nb + '0');
		ret += 1;
	}
	return (ret);
}
