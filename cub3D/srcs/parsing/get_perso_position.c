/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_and_perso_position.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:43:34 by jemercie          #+#    #+#             */
/*   Updated: 2023/07/24 17:44:36 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int	get_position_data(t_params *prm, t_check_data *data, int i, int j);
static void	get_direction_data(int dir, t_params *params);

int	get_perso_position(t_params *params, t_check_data *data)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	tmp = params->map;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] != ' ' && tmp[i][j] != '1' && \
			tmp[i][j] != '0' && tmp[i][j] != '\n')
			{
				params->pos_x = j + 0.5;
				params->pos_y = i + 0.5;
				if (get_position_data(params, data, i, j) < 0)
					return (-1);
				tmp[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	get_position_data(t_params *prm, t_check_data *data, int i, int j)
{
	char	c;

	data->nb_params++;
	c = prm->map[i][j];
	if (c == 'N')
		get_direction_data(1, prm);
	else if (c == 'S')
		get_direction_data(2, prm);
	else if (c == 'W')
		get_direction_data(3, prm);
	else if (c == 'E')
		get_direction_data(4, prm);
	else
	{
		ft_putstr_fd("Error\nWrong character.\n", 2);
		return (-1);
	}
	return (0);
}

static void	get_direction_data(int dir, t_params *params)
{
	if (dir == 1)
	{
	params->dir_y = -1;
	params->plane_x = 0.66;
	}
	if (dir == 2)
	{
	params->dir_y = 1;
	params->plane_x = -0.66;
	}
	if (dir == 3)
	{
	params->dir_x = -1;
	params->plane_y = -0.66;
	}
	if (dir == 4)
	{
	params->dir_x = 1;
	params->plane_y = 0.66;
	}
}
