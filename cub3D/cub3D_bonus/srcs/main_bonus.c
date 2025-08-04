/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:01:39 by vline             #+#    #+#             */
/*   Updated: 2023/08/19 16:30:33 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

static int	new_images(t_params *params);
static void	calcul_and_draw(void *param);
static void	draw_floor(t_params *param, mlx_image_t *background);
static void	draw_ceiling(t_params *param, mlx_image_t *background);

int	main(int argc, char **argv)
{
	static t_params		params;

	if (parsing(argc, argv, &params) == -1)
		return (free_and_delete(&params));
	params.mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", true);
	if (!params.mlx)
		return (free_and_delete(&params));
	mlx_set_mouse_pos(params.mlx, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	mlx_set_cursor_mode(params.mlx, MLX_MOUSE_HIDDEN);
	if (new_images(&params) < 0)
		return (-1);
	mlx_loop_hook(params.mlx, calcul_and_draw, &params);
	mlx_loop_hook(params.mlx, ft_hook, &params);
	mlx_key_hook(params.mlx, door_key_hook, &params);
	mlx_loop(params.mlx);
	mlx_terminate(params.mlx);
	free_and_delete(&params);
}

static int	new_images(t_params *params)
{
	static mlx_image_t	*background;

	background = mlx_new_image(params->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	draw_ceiling(params, background);
	draw_floor(params, background);
	if (!background || \
		(mlx_image_to_window(params->mlx, background, 0, 0) < 0))
	{
		free_and_delete(params);
		return (-1);
	}
	params->img = mlx_new_image(params->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!params->img || \
		(mlx_image_to_window(params->mlx, params->img, 0, 0) < 0))
	{
		free_and_delete(params);
		return (-1);
	}
	return (0);
}

static void	calcul_and_draw(void *param)
{
	int						i;
	t_params				*params;

	params = param;
	i = 0;
	while (i < SCREEN_WIDTH)
	{
		calcul_images(params, i);
		i++;
	}
	draw_sprite(params);
	draw_the_map(params);
	move_the_door(params);
}

static void	draw_ceiling(t_params *param, mlx_image_t *background)
{
	int	i;
	int	j;
	int	color;
	int	nb;

	nb = 0;
	color = param->ccolor;
	i = SCREEN_HEIGHT / 2;
	while (i > 0)
	{
		j = 0;
		if (nb == 3)
		{
			color -= 1;
			nb = 0;
		}
		while (j < SCREEN_WIDTH)
		{
			mlx_put_pixel(background, j, i, color);
			j++;
		}
		nb++;
		i--;
	}
}

static void	draw_floor(t_params *param, mlx_image_t *background)
{
	int	i;
	int	j;
	int	color;
	int	nb;

	nb = 0;
	i = SCREEN_HEIGHT / 2;
	color = param->fcolor;
	while (i < SCREEN_HEIGHT)
	{
		j = 0;
		if (nb == 3)
		{
			color -= 1;
			nb = 0;
		}
		while (j < SCREEN_WIDTH)
		{
			mlx_put_pixel(background, j, i, color);
			j++;
		}
		nb++;
		i++;
	}
}
