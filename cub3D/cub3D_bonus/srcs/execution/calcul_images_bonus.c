/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_images_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:22:48 by vline             #+#    #+#             */
/*   Updated: 2023/08/19 16:27:17 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	calcul_wall_distance(t_params *params, t_cam *cam, int z);

void	calcul_images(t_params *params, int z)
{
	static t_cam	cam;

	calcul_direction(params, &cam, z);
	calcul_stripes_size(params, &cam);
	calcul_which_image(params, &cam, z);
}

void	calcul_direction(t_params *params, t_cam *cam, int z)
{
	double	camerax;

	camerax = 2 * z / (double)SCREEN_WIDTH - 1;
	cam->ray_dir_x = params->dir_x + params->plane_x * camerax;
	cam->ray_dir_y = params->dir_y + params->plane_y * camerax;
	if (cam->ray_dir_x != 0)
		cam->delta_dist_x = fabs(1 / cam->ray_dir_x);
	else
		cam->delta_dist_x = 1e30;
	if (cam->ray_dir_y != 0)
		cam->delta_dist_y = fabs(1 / cam->ray_dir_y);
	else
		cam->delta_dist_y = 1e30;
	if (cam->ray_dir_x < 0)
	{
		cam->step_x = -1;
		cam->side_dist_x = (params->pos_x - (int)params->pos_x) \
		* cam->delta_dist_x;
	}
	else
	{
		cam->step_x = 1;
		cam->side_dist_x = ((int)params->pos_x + 1.0 - params->pos_x) \
		* cam->delta_dist_x;
	}
}

void	calcul_stripes_size(t_params *params, t_cam *cam)
{
	cam->map_x = (int)params->pos_x;
	cam->map_y = (int)params->pos_y;
	cam->side2 = 0;
	if (cam->ray_dir_y < 0)
	{
		cam->step_y = -1;
		cam->side_dist_y = (params->pos_y - cam->map_y) * cam->delta_dist_y;
	}
	else
	{
		cam->step_y = 1;
		cam->side_dist_y = (cam->map_y + 1.0 - params->pos_y) \
		* cam->delta_dist_y;
	}
}

void	calcul_which_image(t_params *params, t_cam *cam, int z)
{
	while (1)
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
		if (params->map[cam->map_y][cam->map_x] != '0' && \
			params->map[cam->map_y][cam->map_x] != '8')
			break ;
		if (cam->side2 == 0)
			cam->side2 = -1;
		if (cam->side2 == 5)
			cam->side2 = 2;
	}
	calcul_wall_distance(params, cam, z);
}

static void	calcul_wall_distance(t_params *params, t_cam *cam, int z)
{
	if (cam->side == 0)
		cam->wall_dist = (cam->side_dist_x - cam->delta_dist_x);
	else
		cam->wall_dist = (cam->side_dist_y - cam->delta_dist_y);
	if (params->map[cam->map_y][cam->map_x] == '2' || \
		params->map[cam->map_y][cam->map_x] == '3' || \
		params->map[cam->map_y][cam->map_x] == '4' || \
		params->map[cam->map_y][cam->map_x] == '5')
		door(cam);
	draw_all(params, z, cam);
}
