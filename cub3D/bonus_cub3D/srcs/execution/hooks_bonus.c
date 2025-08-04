/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:38:20 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/19 16:28:14 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	a_d_key_hooks(t_params *params, double pos_x, double pos_y);
static	void	turn_left_hook(t_params *prm);
static	void	turn_right_hook(t_params *prm);
static	void	turn(t_params *prm);

void	ft_hook(void *param)
{
	t_params	*params;

	params = param;
	if (mlx_is_key_down(params->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(params->mlx);
	w_s_key_hooks(params, params->pos_x, params->pos_y);
	a_d_key_hooks(params, params->pos_x, params->pos_y);
	turn(params);
}

static void	a_d_key_hooks(t_params *params, double pos_x, double pos_y)
{
	double	dir_x;
	double	dir_y;

	dir_x = params->dir_x;
	dir_y = params->dir_y;
	if (mlx_is_key_down(params->mlx, MLX_KEY_A))
	{
		if (params->map[(int)(pos_y - dir_x * 0.11)][(int)(pos_x)] == '0' || \
			params->map[(int)(pos_y - dir_x * 0.11)][(int)(pos_x)] == '5')
			params->pos_y -= dir_x * 0.1;
		if (params->map[(int)(pos_y)][(int)(pos_x + dir_y * 0.11)] == '0' || \
			params->map[(int)(pos_y)][(int)(pos_x + dir_y * 0.11)] == '5')
			params->pos_x += dir_y * 0.1;
	}
	if (mlx_is_key_down(params->mlx, MLX_KEY_D))
	{
		if (params->map[(int)(pos_y)][(int)(pos_x - dir_y * 0.11)] == '0' || \
			params->map[(int)(pos_y)][(int)(pos_x - dir_y * 0.11)] == '5')
			params->pos_x -= params->dir_y * 0.1;
		if (params->map[(int)(pos_y + dir_x * 0.11)][(int)(pos_x)] == '0' || \
			params->map[(int)(pos_y + dir_x * 0.11)][(int)(pos_x)] == '5')
			params->pos_y += dir_x * 0.1;
	}
}

static	void	turn(t_params *prm)
{
	int32_t			mouse_x;
	int32_t			mouse_y;

	mlx_get_mouse_pos(prm->mlx, &mouse_x, &mouse_y);
	if (mouse_x > SCREEN_WIDTH / 2 || mlx_is_key_down(prm->mlx, MLX_KEY_RIGHT))
		turn_right_hook(prm);
	if (mouse_x < SCREEN_WIDTH / 2 || mlx_is_key_down(prm->mlx, MLX_KEY_LEFT))
		turn_left_hook(prm);
	mlx_set_mouse_pos(prm->mlx, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

static	void	turn_right_hook(t_params *prm)
{
	double	old_dir;
	double	old_plane;

	old_dir = prm->dir_x;
	prm->dir_x = prm->dir_x * cos(0.1) - prm->dir_y * sin(0.1);
	prm->dir_y = old_dir * sin(0.1) + prm->dir_y * cos(0.1);
	old_plane = prm->plane_x;
	prm->plane_x = prm->plane_x * cos(0.1) - prm->plane_y * sin(0.1);
	prm->plane_y = old_plane * sin(0.1) + prm->plane_y * cos(0.1);
}

static	void	turn_left_hook(t_params *prm)
{
	double	old_dir;
	double	old_plane;

	old_dir = prm->dir_x;
	prm->dir_x = prm->dir_x * cos(-0.1) - prm->dir_y * sin(-0.1);
	prm->dir_y = old_dir * sin(-0.1) + prm->dir_y * cos(-0.1);
	old_plane = prm->plane_x;
	prm->plane_x = prm->plane_x * cos(-0.1) - prm->plane_y * sin(-0.1);
	prm->plane_y = old_plane * sin(-0.1) + prm->plane_y * cos(-0.1);
}
