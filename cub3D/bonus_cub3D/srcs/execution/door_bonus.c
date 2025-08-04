/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:17:10 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/19 16:27:36 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	door_if_side_is(t_cam *cam);
static void	door_if_side(t_cam *cam);

void	door(t_cam *cam)
{
	if (cam->side == 0)
		door_if_side(cam);
	else
		door_if_side_is(cam);
}

static void	door_if_side(t_cam *cam)
{
	if (cam->side_dist_x - cam->delta_dist_x / 2 < cam->side_dist_y)
	{
		cam->wall_dist = (cam->side_dist_x - cam->delta_dist_x / 2);
		cam->side = 0;
		cam->side2 = 3;
	}
	else
	{
		cam->wall_dist = (cam->side_dist_y);
		cam->side = 1;
		cam->side2 = 4;
	}
}

static void	door_if_side_is(t_cam *cam)
{	
	if (cam->side_dist_x < cam->side_dist_y - cam->delta_dist_y / 2)
	{
		cam->wall_dist = cam->side_dist_x;
		cam->side = 0;
		cam->side2 = 4;
	}
	else
	{
		cam->wall_dist = cam->side_dist_y - cam->delta_dist_y / 2;
		cam->side = 1;
		cam->side2 = 3;
	}
}

int	next_door(t_params *params, t_cam *cam)
{
	if (cam->side_dist_x < cam->side_dist_y)
	{
		cam->side_dist_x += cam->delta_dist_x;
		cam->map_x += cam->step_x;
		cam->side = 0;
	}
	else
	{
		cam->side_dist_y += cam->delta_dist_y;
		cam->map_y += cam->step_y;
		cam->side = 1;
	}
	if (params->map[cam->map_y][cam->map_x] != '2' \
	&& params->map[cam->map_y][cam->map_x] != '3' \
	&& params->map[cam->map_y][cam->map_x] != '4' \
	&& params->map[cam->map_y][cam->map_x] != '5')
		return (1);
	return (0);
}

int	is_door_valid(char **map, int i, int j)
{
	if ((map[i - 1][j] != '1' || map[i + 1][j] != '1') && \
		(map[i][j - 1] != '1' || map[i][j + 1] != '1'))
	{
		ft_putstr_fd("Error\nThe door isn't surrounded by walls.\n", 2);
		return (-1);
	}
	return (0);
}
