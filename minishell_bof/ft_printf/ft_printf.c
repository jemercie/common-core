/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:22:20 by jemercie          #+#    #+#             */
/*   Updated: 2022/11/11 01:44:57 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_is_convert(char c, char c1, int j, va_list args)
{
	int	size;

	size = 0;
	if (j == 1)
		size = ft_putchar_pf(va_arg(args, int));
	else if (j == 2)
		size = ft_putstr_pf(va_arg(args, char *));
	else if (j == 3)
		size = ft_putptr(va_arg(args, unsigned long int));
	else if (j == 4 || j == 5)
		size = ft_putnbr_pf(va_arg(args, int));
	else if (j == 6)
		size = ft_putunsigned(va_arg(args, unsigned int));
	else if (j == 7)
		size = ft_puthexa_low(va_arg(args, unsigned int));
	else if (j == 8)
		size = ft_puthexa_upp(va_arg(args, unsigned int));
	else if (j == 9 || (j == 0 && c && c1))
		size = ft_putchar_pf('%');
	else if (j == 0 && c && !c1)
		return (-1);
	if (j == 0 && c && c1)
		size += write(1, &c, 1);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		size;
	int		j;

	i = 0;
	size = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			j = ft_strncmp_char(str[i], "cspdiuxX%");
			size += ft_is_convert(str[i], str[i + 1], j, args);
		}
		else
			size += ft_putchar_pf(str[i]);
		i++;
	}
	va_end(args);
	return (size);
}
