/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:51:12 by jemercie          #+#    #+#             */
/*   Updated: 2022/09/29 00:10:27 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	a;
	int	sign;
	int	nbr;

	a = 0;
	sign = 1;
	nbr = 0;
	while (nptr[a] == ' ' || (nptr[a] >= '\t' && nptr[a] <= '\r'))
		a++;
	if (nptr[a] == '-' || nptr[a] == '+')
	{
		if (nptr[a] == '-')
			sign = -1;
		a++;
	}
	while (nptr[a] >= '0' && nptr[a] <= '9')
	{
		nbr = ((nbr * 10) + nptr[a] - '0');
		a++;
	}
	return (nbr * sign);
}
