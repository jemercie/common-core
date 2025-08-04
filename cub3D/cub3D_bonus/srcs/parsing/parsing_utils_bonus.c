/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:32:54 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/19 16:30:17 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

void	skip_whitespaces(char *arg, int *i)
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

void	skip_isspaces(char *arg, int *i)
{
	while (arg[*i] && ft_isspace(arg[*i]) == 1)
		++*i;
}

int	get_rgba(int rgb[3], int a)
{
	return (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | a);
}

int	get_float_map(t_check_data *data, t_params *params)
{
	float	**tab_map;
	int		i;
	int		j;

	i = 0;
	tab_map = malloc(sizeof(float *) * (data->map_height + 1));
	if (!tab_map)
		return (-1);
	while (i < data->map_height)
	{
		j = 0;
		tab_map[i] = malloc(sizeof(float) * data->map_len);
		if (!tab_map[i])
			return (-1);
		while (j < data->map_len)
		{
			tab_map[i][j] = 0;
			j++;
		}
		i++;
	}
	tab_map[i] = NULL;
	params->tab = tab_map;
	return (0);
}
