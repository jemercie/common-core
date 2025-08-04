/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_the_view.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:56:31 by vline             #+#    #+#             */
/*   Updated: 2023/08/16 15:41:46 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	get_the_moove(t_calcul_params *data, t_params *params);
static void	is_there_a_wall(t_calcul_params *data, t_params *params);

void	calcul_the_view(t_params *params, int z, t_calcul_params *data)
{
	init_calcul_param_struct(data, z, params);
	if (data->ray_dir_x != 0)
		data->delta_dist_x = fabs(1 / data->ray_dir_x);
	else
		data->delta_dist_x = 7728;
	if (data->ray_dir_y != 0)
		data->delta_dist_y = fabs(1 / data->ray_dir_y);
	else
	data->delta_dist_y = 7728;
	get_the_moove(data, params);
	is_there_a_wall(data, params);
	if (data->side == 0)
		data->wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->wall_dist = (data->side_dist_y - data->delta_dist_y);
}

static void	get_the_moove(t_calcul_params *data, t_params *params)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (params->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - params->pos_x) \
		* data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (params->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - params->pos_y) \
		* data->delta_dist_y;
	}
}

static void	is_there_a_wall(t_calcul_params *data, t_params *params)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (params->map[data->map_y][data->map_x] != '0')
			data->hit = 1;
	}
}
