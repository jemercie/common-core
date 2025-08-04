/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:20:47 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/19 16:27:57 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	calcul_sprite(t_draw_sprite *dr_sp, t_params *params, int x, int y);
static void	get_sprite_line(t_draw_sprite *dr_sp, t_params *params);
static void	get_sprite_stripe(t_draw_sprite *dr_sp, t_params *prm, int stripe);
static void	draw_pixel(t_draw_sprite *sp, t_params *params, int stripe, int i);

void	draw_sprite(t_params *prm)
{
	int						i;
	int						j;
	static t_draw_sprite	dr_sp;

	get_sprite_rank(prm->sprite, prm->pos_x, prm->pos_y);
	i = 0;
	j = -1;
	while (prm->sprite[i])
	{
		i++;
		j++;
	}
	i = 0;
	while (prm->sprite[i])
	{
		if (prm->sprite[i]->rank == j)
		{
			calcul_sprite(&dr_sp, prm, prm->sprite[i]->x, prm->sprite[i]->y);
			get_sprite_line(&dr_sp, prm);
			j--;
			i = 0;
		}
		else
			i++;
	}
}

static void	calcul_sprite(t_draw_sprite *dr_sp, t_params *params, int x, int y)
{
	double	sprite_x;
	double	sprite_y;
	double	invdt;
	double	transform_x;

	sprite_x = x + 0.5 - params->pos_x;
	sprite_y = y + 0.5 - params->pos_y;
	invdt = 1.0 / (params->plane_x * params->dir_y
			- params->dir_x * params->plane_y);
	transform_x = invdt * (params->dir_y * sprite_x - params->dir_x * sprite_y);
	dr_sp->transform_y = invdt * (-params->plane_y * sprite_x
			+ params->plane_x * sprite_y);
	dr_sp->sprite_screen_x = (int)((SCREEN_WIDTH / 2) * (1 + transform_x
				/ dr_sp->transform_y));
	dr_sp->sprite_height = fabs((SCREEN_HEIGHT / (dr_sp->transform_y)));
	dr_sp->draw_start_y = -dr_sp->sprite_height / 2 + SCREEN_HEIGHT / 2;
	if (dr_sp->draw_start_y < 0)
		dr_sp->draw_start_y = 0;
	dr_sp->draw_end_y = dr_sp->sprite_height / 2 + SCREEN_HEIGHT / 2;
	if (dr_sp->draw_end_y >= SCREEN_HEIGHT)
		dr_sp->draw_end_y = SCREEN_HEIGHT;
	dr_sp->sprite_width = fabs((SCREEN_HEIGHT / (dr_sp->transform_y)));
	dr_sp->draw_start_x = -dr_sp->sprite_width / 2 + dr_sp->sprite_screen_x;
	if (dr_sp->draw_start_x <= 0)
		dr_sp->draw_start_x = 0;
}

static void	get_sprite_line(t_draw_sprite *dr_sp, t_params *params)
{
	int	stripe;

	dr_sp->draw_end_x = dr_sp->sprite_width / 2 + dr_sp->sprite_screen_x;
	if (dr_sp->draw_end_x >= SCREEN_WIDTH)
		dr_sp->draw_end_x = SCREEN_WIDTH;
	params->texture = params->tex_d[(int)params->sprite_nb];
	stripe = dr_sp->draw_start_x;
	while (stripe < dr_sp->draw_end_x)
	{
		get_sprite_stripe(dr_sp, params, stripe);
		stripe++;
	}
}

static void	get_sprite_stripe(t_draw_sprite *dr_sp, t_params *prm, int stripe)
{
	int	i;

	dr_sp->tex_x = (int)((stripe - (-dr_sp->sprite_width / 2
					+ dr_sp->sprite_screen_x)) * prm->texture->width
			/ dr_sp->sprite_width);
	if (dr_sp->transform_y > 0 && stripe >= 0 && stripe < SCREEN_WIDTH
		&& dr_sp->transform_y < prm->perr[stripe])
	{
		i = dr_sp->draw_start_y;
		while (i < dr_sp->draw_end_y)
		{
			draw_pixel(dr_sp, prm, stripe, i);
			i++;
		}
	}
}

static void	draw_pixel(t_draw_sprite *sp, t_params *params, int stripe, int i)
{
	int			tex_y;
	static int	rgb[4];
	int			d;
	int			color;

	d = (i) * 256 - SCREEN_HEIGHT * 128 + sp->sprite_height * 128;
	tex_y = ((d * params->texture->height) / sp->sprite_height) / 256;
	rgb[0] = params->texture->pixels[((params->texture->width * tex_y)
			+ sp->tex_x) * params->texture->bytes_per_pixel];
	rgb[1] = params->texture->pixels[((params->texture->width * tex_y)
			+ sp->tex_x) * params->texture->bytes_per_pixel + 1];
	rgb[2] = params->texture->pixels[((params->texture->width * tex_y)
			+ sp->tex_x) * params->texture->bytes_per_pixel + 2];
	rgb[3] = params->texture->pixels[((params->texture->width * tex_y)
			+ sp->tex_x) * params->texture->bytes_per_pixel + 3];
	color = get_rgba(rgb, rgb[3]);
	if (rgb[3] == 255)
		mlx_put_pixel(params->img, stripe, i, color);
}
