/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vline <vline@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:32:54 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/19 15:14:11 by vline            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	skip_whitespaces(char	*arg, int *i)
{
	while (arg[*i] && is_whitespace(arg[*i]) > 0)
		++*i;
}

int	is_whitespace(char c)
{
	if (c == ' ')
		return (1);
	return (-1);
}

int	get_rgba(int rgb[3], int a)
{
	return (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | a);
}

void	skip_isspaces(char *arg, int *i)
{
	while (arg[*i] && ft_isspace(arg[*i]) == 1)
		++*i;
}

int	malloc_error(void)
{
	ft_putstr_fd("Error\nMalloc failed.\n", 2);
	return (-1);
}
