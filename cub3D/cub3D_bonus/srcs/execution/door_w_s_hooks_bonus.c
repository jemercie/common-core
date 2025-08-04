/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_w_s_hooks_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:38:20 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/19 16:27:43 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

void	w_s_key_hooks(t_params *params, double pos_x, double pos_y)
{
	double	dir_x;
	double	dir_y;

	dir_x = params->dir_x;
	dir_y = params->dir_y;
	if (mlx_is_key_down(params->mlx, MLX_KEY_W))
	{
		if (params->map[(int)(pos_y)][(int)(pos_x + dir_x * 0.11)] == '0' || \
			params->map[(int)(pos_y)][(int)(pos_x + dir_x * 0.11)] == '5')
			params->pos_x += dir_x * 0.1;
		if (params->map[(int)(pos_y + dir_y * 0.11)][(int)(pos_x)] == '0' || \
			params->map[(int)(pos_y + dir_y * 0.11)][(int)(pos_x)] == '5')
			params->pos_y += dir_y * 0.1;
	}
	if (mlx_is_key_down(params->mlx, MLX_KEY_S))
	{
		if (params->map[(int)(pos_y)][(int)(pos_x - dir_x * 0.11)] == '0' || \
			params->map[(int)(pos_y)][(int)(pos_x - dir_x * 0.11)] == '5')
			params->pos_x -= dir_x * 0.1;
		if (params->map[(int)(pos_y - dir_y * 0.11)][(int)(pos_x)] == '0' || \
			params->map[(int)(pos_y - dir_y * 0.11)][(int)(pos_x)] == '5')
			params->pos_y -= dir_y * 0.1;
	}
}

void	door_key_hook(mlx_key_data_t keydata, void *param)
{
	t_params		*params;
	static t_cam	cam;

	params = param;
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	{
		calcul_direction(params, &cam, SCREEN_WIDTH / 2);
		calcul_stripes_size(params, &cam);
		if (next_door(params, &cam) == 0)
		{
			if (params->map[cam.map_y][cam.map_x] == '2' \
			|| params->map[cam.map_y][cam.map_x] == '4')
			{
				params->map[cam.map_y][cam.map_x] = '3';
			}
			else if (params->map[cam.map_y][cam.map_x] == '3' \
			|| params->map[cam.map_y][cam.map_x] == '5')
				params->map[cam.map_y][cam.map_x] = '4';
		}
	}
}
