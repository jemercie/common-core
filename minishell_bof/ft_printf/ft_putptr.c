/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:18:38 by jemercie          #+#    #+#             */
/*   Updated: 2022/11/09 20:45:53 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putptr(unsigned long int nb)
{
	int	size;

	size = 0;
	if (!nb)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	size = ft_puthexa_low(nb) + 2;
	return (size);
}
