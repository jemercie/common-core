/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:01:39 by vline             #+#    #+#             */
/*   Updated: 2023/08/19 16:18:25 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	calcul_and_draw(void *param);

int	main(int argc, char **argv)
{
	static t_params	params;

	if (parsing(argc, argv, &params) == -1)
	{
		close_and_free(&params);
		return (0);
	}
	params.mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", true);
	if (params.mlx == NULL)
		return (0);
	params.img = mlx_new_image(params.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!params.img || \
		(mlx_image_to_window(params.mlx, params.img, 0, 0) < 0))
		return (0);
	mlx_loop_hook(params.mlx, calcul_and_draw, &params);
	mlx_loop_hook(params.mlx, ft_hook, &params);
	mlx_loop(params.mlx);
	mlx_terminate(params.mlx);
	close_and_free(&params);
}

static void	calcul_and_draw(void *param)
{
	int						i;
	t_params				*params;
	static t_calcul_params	data;

	params = param;
	i = 0;
	while (i < SCREEN_WIDTH)
	{
		calcul_the_view(params, i, &data);
		draw_all(params, i, &data);
		i++;
	}
}
