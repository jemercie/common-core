/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:42:01 by jemercie          #+#    #+#             */
/*   Updated: 2023/03/11 16:53:32 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_images(t_vars *tvars);

/* free and destroy everything before exit */

int	win_exit(t_vars *tvars)
{
	if (tvars->map)
		free_tab(tvars->map);
	if (tvars->mlx && tvars->win)
		mlx_clear_window(tvars->mlx, tvars->win);
	destroy_images(tvars);
	if (tvars->mlx && tvars->win)
		mlx_destroy_window(tvars->mlx, tvars->win);
	if (tvars->mlx)
		mlx_destroy_display(tvars->mlx);
	free(tvars->mlx);
	exit(0);
	return (0);
}

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	destroy_images(t_vars *tvars)
{
	mlx_destroy_image(tvars->mlx, tvars->images->corner_up_right);
	mlx_destroy_image(tvars->mlx, tvars->images->corner_up_left);
	mlx_destroy_image(tvars->mlx, tvars->images->corner_down_right);
	mlx_destroy_image(tvars->mlx, tvars->images->corner_down_left);
	mlx_destroy_image(tvars->mlx, tvars->images->wall_up);
	mlx_destroy_image(tvars->mlx, tvars->images->wall_down);
	mlx_destroy_image(tvars->mlx, tvars->images->wall_right);
	mlx_destroy_image(tvars->mlx, tvars->images->wall_left);
	mlx_destroy_image(tvars->mlx, tvars->images->collectible);
	mlx_destroy_image(tvars->mlx, tvars->images->exit);
	mlx_destroy_image(tvars->mlx, tvars->images->perso);
	mlx_destroy_image(tvars->mlx, tvars->images->mid_wall);
	mlx_destroy_image(tvars->mlx, tvars->images->ground);
}
