/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vline <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:38:20 by vline             #+#    #+#             */
/*   Updated: 2023/07/24 17:37:35 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	w_s_key_hooks(t_params *params);
static void	a_d_key_hooks(t_params *params);
static void	right_left_key_hooks(t_params *prm);

void	ft_hook(void *param)
{
	t_params	*params;

	params = param;
	if (mlx_is_key_down(params->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(params->mlx);
	w_s_key_hooks(params);
	a_d_key_hooks(params);
	right_left_key_hooks(params);
}

static void	w_s_key_hooks(t_params *params)
{
	if (mlx_is_key_down(params->mlx, MLX_KEY_W))
	{
		if (params->map[(int)(params->pos_y)] \
		[(int)(params->pos_x + params->dir_x * 0.11)] == '0')
			params->pos_x += params->dir_x * 0.1;
		if (params->map[(int)(params->pos_y + params->dir_y * 0.11)] \
		[(int)(params->pos_x)] == '0')
			params->pos_y += params->dir_y * 0.1;
	}
	if (mlx_is_key_down(params->mlx, MLX_KEY_S))
	{
		if (params->map[(int)(params->pos_y)] \
		[(int)(params->pos_x - params->dir_x * 0.11)] == '0')
			params->pos_x -= params->dir_x * 0.1;
		if (params->map[(int)(params->pos_y - params->dir_y * 0.11)] \
		[(int)(params->pos_x)] == '0')
			params->pos_y -= params->dir_y * 0.1;
	}
}

static void	a_d_key_hooks(t_params *params)
{
	if (mlx_is_key_down(params->mlx, MLX_KEY_A))
	{
		if (params->map[(int)(params->pos_y - params->dir_x * 0.11)] \
		[(int)(params->pos_x)] == '0')
			params->pos_y -= params->dir_x * 0.1;
		if (params->map[(int)(params->pos_y)] \
		[(int)(params->pos_x + params->dir_y * 0.11)] == '0')
			params->pos_x += params->dir_y * 0.1;
	}
	if (mlx_is_key_down(params->mlx, MLX_KEY_D))
	{
		if (params->map[(int)(params->pos_y)] \
		[(int)(params->pos_x - params->dir_y * 0.11)] == '0')
			params->pos_x -= params->dir_y * 0.1;
		if (params->map[(int)(params->pos_y + params->dir_x * 0.11)] \
		[(int)(params->pos_x)] == '0')
			params->pos_y += params->dir_x * 0.1;
	}
}

static void	right_left_key_hooks(t_params *prm)
{
	double	old_dir;
	double	old_plane;

	if (mlx_is_key_down(prm->mlx, MLX_KEY_LEFT))
	{
		old_dir = prm->dir_x;
		prm->dir_x = prm->dir_x * cos(-0.1) - prm->dir_y * sin(-0.1);
		prm->dir_y = old_dir * sin(-0.1) + prm->dir_y * cos(-0.1);
		old_plane = prm->plane_x;
		prm->plane_x = prm->plane_x * cos(-0.1) - prm->plane_y * sin(-0.1);
		prm->plane_y = old_plane * sin(-0.1) + prm->plane_y * cos(-0.1);
	}
	if (mlx_is_key_down(prm->mlx, MLX_KEY_RIGHT))
	{
		old_dir = prm->dir_x;
		prm->dir_x = prm->dir_x * cos(0.1) - prm->dir_y * sin(0.1);
		prm->dir_y = old_dir * sin(0.1) + prm->dir_y * cos(0.1);
		old_plane = prm->plane_x;
		prm->plane_x = prm->plane_x * cos(0.1) - prm->plane_y * sin(0.1);
		prm->plane_y = old_plane * sin(0.1) + prm->plane_y * cos(0.1);
	}
}
