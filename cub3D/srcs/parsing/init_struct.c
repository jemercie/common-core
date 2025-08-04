/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:01:53 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/16 15:41:47 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	init_struct(t_check_data data)
{
	data.fd = 0;
	data.f[0] = -1;
	data.f[1] = -1;
	data.f[2] = -1;
	data.c[0] = -1;
	data.c[1] = -1;
	data.c[2] = -1;
}

void	init_calcul_param_struct(t_calcul_params *data, int z, t_params *param)
{
	data->camera_x = 2 * z / (double)SCREEN_WIDTH - 1;
	data->ray_dir_x = param->dir_x + param->plane_x * data->camera_x;
	data->ray_dir_y = param->dir_y + param->plane_y * data->camera_x;
	data->map_x = (int)param->pos_x;
	data->map_y = (int)param->pos_y;
	data->side_dist_x = 0;
	data->side_dist_y = 0;
	data->delta_dist_x = 0;
	data->delta_dist_y = 0;
	data->wall_dist = 0;
	data->step_x = 0;
	data->step_y = 0;
	data->hit = 0;
	data->side = 0;
}
