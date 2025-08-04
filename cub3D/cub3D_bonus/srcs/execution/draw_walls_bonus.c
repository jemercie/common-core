/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:13:49 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/19 16:28:09 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static int	wall_is_door(t_cam *data, t_params *params, t_draw *draw, int z);
static void	inverse_image(t_cam *data, t_params *params, t_draw *draw);

void	draw_walls(t_cam *data, t_params *params, t_draw *draw, int z)
{
	if (data->side == 0)
		draw->wall_x = params->pos_y + data->wall_dist * data->ray_dir_y;
	else
		draw->wall_x = params->pos_x + data->wall_dist * data->ray_dir_x;
	draw->wall_x -= floor((draw->wall_x));
	get_the_texture(data->side, params, data);
	draw->tex_x = (int)(draw->wall_x * (double)(params->texture->width));
	if (wall_is_door(data, params, draw, z) == 0)
		return ;
	inverse_image(data, params, draw);
	draw->step = 1.0 * params->texture->height / draw->height;
	draw->tex_pos = (draw->start - SCREEN_HEIGHT / 2 + draw->height / 2) \
	* draw->step;
	draw->y = draw->start;
	draw_pixels(data, draw, params, z);
}

static int	wall_is_door(t_cam *data, t_params *params, t_draw *draw, int z)
{
	if ((params->map[data->map_y][data->map_x] == '2' || \
		params->map[data->map_y][data->map_x] == '3' || \
		params->map[data->map_y][data->map_x] == '4' || \
		params->map[data->map_y][data->map_x] == '5') && (data->side2 == 3))
	{
		draw->tex_x = params->tab[data->map_y][data->map_x] * \
		params->texture->width + draw->tex_x;
		if (draw->tex_x >= (int)params->texture->width)
		{
			data->side2 = 5;
			calcul_which_image(params, data, z);
			return (0);
		}
	}
	return (1);
}

static void	inverse_image(t_cam *data, t_params *params, t_draw *draw)
{
	if (data->side == 0 && data->ray_dir_x < 0)
		draw->tex_x = params->texture->width - draw->tex_x - 1;
	if (data->side == 1 && data->ray_dir_y > 0)
		draw->tex_x = params->texture->width - draw->tex_x - 1;
	if ((data->side == 0 && data->side2 == 3) && data->ray_dir_x > 0)
		draw->tex_x = params->texture->width - draw->tex_x - 1;
	if ((data->side == 1 && data->side2 == 3) && data->ray_dir_y < 0)
		draw->tex_x = params->texture->width - draw->tex_x - 1;
	if ((data->side == 0 && data->side2 > 3) && data->ray_dir_x > 0)
		draw->tex_x = params->texture->width - draw->tex_x - 1;
	if ((data->side == 1 && data->side2 > 3) && data->ray_dir_y < 0)
		draw->tex_x = params->texture->width - draw->tex_x - 1;
	if ((data->side == 0 && data->side2 == 0) && data->ray_dir_x > 0 && \
		params->map[(int)params->pos_y][(int)params->pos_x] == '5')
		draw->tex_x = params->texture->width - draw->tex_x - 1;
	if ((data->side == 1 && data->side2 == 0) && data->ray_dir_y < 0 && \
		params->map[(int)params->pos_y][(int)params->pos_x] == '5')
		draw->tex_x = params->texture->width - draw->tex_x - 1;
}
