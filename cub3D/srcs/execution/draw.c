/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:37:53 by vline             #+#    #+#             */
/*   Updated: 2023/08/19 16:18:11 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	draw_pixels(t_draw *draw, t_params *params, int z);

void	draw_all(t_params *params, int z, t_calcul_params *data)
{
	static t_draw	draw;

	draw.height = (int)(SCREEN_HEIGHT / data->wall_dist);
	draw.start = -draw.height / 2 + SCREEN_HEIGHT / 2;
	if (draw.start < 0)
		draw.start = 0;
	draw.end = draw.height / 2 + SCREEN_HEIGHT / 2;
	if (draw.end > SCREEN_HEIGHT)
		draw.end = SCREEN_HEIGHT;
	draw_floor_and_ceiling(&draw, params, z);
	draw_walls(data, params, &draw, z);
}

void	get_the_texture(int side, t_params *params, t_calcul_params *data)
{
	if (side == 0 && data->ray_dir_x < 0)
		params->texture = params->tex_w;
	if (side == 0 && data->ray_dir_x >= 0)
		params->texture = params->tex_e;
	if (side == 1 && data->ray_dir_y <= 0)
		params->texture = params->tex_n;
	if (side == 1 && data->ray_dir_y > 0)
		params->texture = params->tex_s;
}

void	draw_floor_and_ceiling(t_draw *draw, t_params *param, int z)
{
	int	i;

	i = 0;
	while (i < draw->start && i < SCREEN_HEIGHT)
	{
		mlx_put_pixel(param->img, z, i, param->ccolor);
		i++;
	}
	while (i < draw->end && i < SCREEN_HEIGHT)
		i++;
	while (i < SCREEN_HEIGHT)
	{
		mlx_put_pixel(param->img, z, i, param->fcolor);
		i++;
	}
}

void	draw_walls(t_calcul_params *data, t_params *param, t_draw *draw, int z)
{
	if (data->side == 0)
		draw->wall_x = param->pos_y + data->wall_dist * data->ray_dir_y;
	else
		draw->wall_x = param->pos_x + data->wall_dist * data->ray_dir_x;
	draw->wall_x -= floor((draw->wall_x));
	get_the_texture(data->side, param, data);
	draw->tex_x = (int)(draw->wall_x * (double)(param->texture->width));
	if (data->side == 0 && data->ray_dir_x < 0)
		draw->tex_x = param->texture->width - draw->tex_x - 1;
	if (data->side == 1 && data->ray_dir_y > 0)
		draw->tex_x = param->texture->width - draw->tex_x - 1;
	draw->step = 1.0 * param->texture->height / draw->height;
	draw->tex_pos = (draw->start - SCREEN_HEIGHT / 2 + draw->height / 2) \
	* draw->step;
	draw->y = draw->start;
	draw_pixels(draw, param, z);
}

static void	draw_pixels(t_draw *draw, t_params *params, int z)
{
	int			color;
	int			tex_y;
	static int	rgb[3];

	while (draw->y < draw->end && draw->y <= SCREEN_HEIGHT)
	{
		tex_y = (int)draw->tex_pos;
		draw->tex_pos += draw->step;
		rgb[0] = params->texture->pixels[((params->texture->width * tex_y) \
		+ draw->tex_x) * params->texture->bytes_per_pixel];
		rgb[1] = params->texture->pixels[((params->texture->width * tex_y) \
		+ draw->tex_x) * params->texture->bytes_per_pixel + 1];
		rgb[2] = params->texture->pixels[((params->texture->width * tex_y) \
		+ draw->tex_x) * params->texture->bytes_per_pixel + 2];
		color = get_rgba(rgb, 255);
		mlx_put_pixel(params->img, z, draw->y, color);
		draw->y++;
	}
}
