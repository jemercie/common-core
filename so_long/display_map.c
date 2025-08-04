/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:11:31 by jemercie          #+#    #+#             */
/*   Updated: 2023/03/05 14:22:59 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	print_up_wall(t_vars *tvars, int i, int j);
static int	print_map_middle(t_vars *tvars, int i, int j);
static void	print_down_wall(t_vars *tvars, int i, int j);
void		put_image(t_vars *tvars, void *img, int i, int j);

int	print_map(t_vars *tvars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = print_up_wall(tvars, i, j);
	i = print_map_middle(tvars, i, j);
	print_down_wall(tvars, i, j);
	return (0);
}

/* print the up wall */

static int	print_up_wall(t_vars *tvars, int i, int j)
{
	while (tvars->map[i][j] != '\n')
	{
		if (j == 0)
			put_image(tvars, tvars->images->corner_up_left, i, j);
		else if (j > 0 && tvars->map[i][j + 1] != '\n')
			put_image(tvars, tvars->images->wall_up, i, j);
		else
			put_image(tvars, tvars->images->corner_up_right, i, j);
		j++;
	}
	return (i);
}

/* print the map exept the up and down walls */

static int	print_map_middle(t_vars *tvars, int i, int j)
{
	while (tvars->map[i + 2])
	{
		i++;
		while (tvars->map[i][j] && tvars->map[i][j] != '\n')
		{
			if (j == 0)
				put_image(tvars, tvars->images->wall_right, i, j);
			else if (tvars->map[i][j + 1] && tvars->map[i][j + 1] == '\n')
				put_image(tvars, tvars->images->wall_left, i, j);
			else if (tvars->map[i][j] == 'C')
				put_image(tvars, tvars->images->collectible, i, j);
			else if (tvars->map[i][j] == 'E')
				put_image(tvars, tvars->images->exit, i, j);
			else if (tvars->map[i][j] == '0')
				put_image(tvars, tvars->images->ground, i, j);
			else if (tvars->map[i][j] == '1')
				put_image(tvars, tvars->images->mid_wall, i, j);
			else if (tvars->map[i][j] == 'P')
				put_image(tvars, tvars->images->perso, i, j);
			j++;
		}
		j = 0;
	}
	return (i + 1);
}

/* print the down wall */

static void	print_down_wall(t_vars *tvars, int i, int j)
{
	while (tvars->map[i][j] != '\n')
	{
		if (j == 0)
			put_image(tvars, tvars->images->corner_down_left, i, j);
		else if (j > 0 && tvars->map[i][j + 1] != '\n')
			put_image(tvars, tvars->images->wall_down, i, j);
		else
			put_image(tvars, tvars->images->corner_down_right, i, j);
		j++;
	}
}

void	put_image(t_vars *tvars, void *img, int i, int j)
{
	mlx_put_image_to_window(tvars->mlx, tvars->win, img,
		j * tvars->img_height, i * tvars->img_width);
}
