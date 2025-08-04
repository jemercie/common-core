/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:37:53 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/19 16:27:50 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

void	draw_all(t_params *params, int z, t_cam *data)
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

void	get_the_texture(int side, t_params *params, t_cam *data)
{
	if (data->side2 == 5)
		params->texture = params->tex_t;
	else
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
	if (data->side2 == 3)
		params->texture = params->tex_p;
	if (data->side2 == 4)
		params->texture = params->tex_t;
	if (data->side2 == 0 && params->map[(int)params->pos_y] \
		[(int)params->pos_x] == '5')
		params->texture = params->tex_t;
}

void	draw_floor_and_ceiling(t_draw *draw, t_params *param, int z)
{
	int	i;

	i = 0;
	while (i < draw->start && i < SCREEN_HEIGHT)
	{
		mlx_put_pixel(param->img, z, i, 0);
		i++;
	}
	while (i < draw->end && i < SCREEN_HEIGHT)
		i++;
	while (i < SCREEN_HEIGHT)
	{
		mlx_put_pixel(param->img, z, i, 0);
		i++;
	}
}

void	draw_pixels(t_cam *data, t_draw *draw, t_params *params, int z)
{
	int			color;
	int			tex_y;
	static int	rgb[4];

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
		rgb[3] = params->texture->pixels[((params->texture->width * tex_y) \
		+ draw->tex_x) * params->texture->bytes_per_pixel + 3];
		color = get_rgba(rgb, rgb[3]);
		mlx_put_pixel(params->img, z, draw->y, color);
		draw->y++;
	}
	params->perr[z] = data->wall_dist;
}
