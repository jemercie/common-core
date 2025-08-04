/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:38:55 by jemercie          #+#    #+#             */
/*   Updated: 2023/03/11 17:05:00 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*display_img(t_vars *tvars, char *filename);
static void	init_tvars_struct(t_vars *tvars);
static void	init_tmap_struct(t_vars *tvars, t_map *tmap);

/* initialize structures */

void	init_structs(t_vars *tvars, t_map *tmap)
{
	init_tvars_struct(tvars);
	init_tmap_struct(tvars, tmap);
}

static void	init_tvars_struct(t_vars *tvars)
{
	tvars->x = 0;
	tvars->y = 0;
	tvars->collectible = 0;
	tvars->nb_move = 0;
	tvars->mlx = mlx_init();
	if (!tvars->mlx)
		exit(0);
	tvars->map = NULL;
	tvars->win = NULL;
	tvars->images = NULL;
	tvars->img_width = 64;
	tvars->key = -1;
	tvars->img_height = 64;
}

static void	init_tmap_struct(t_vars *tvars, t_map *tmap)
{
	tmap->corner_up_left = display_img(tvars, "./img/upL_corner.xpm");
	tmap->corner_up_right = display_img(tvars, "./img/upR_corner.xpm");
	tmap->corner_down_right = display_img(tvars, "./img/downR_corner.xpm");
	tmap->corner_down_left = display_img(tvars, "./img/downL_corner.xpm");
	tmap->wall_up = display_img(tvars, "./img/up_wall.xpm");
	tmap->wall_down = display_img(tvars, "./img/down_wall.xpm");
	tmap->wall_left = display_img(tvars, "./img/left_wall.xpm");
	tmap->wall_right = display_img(tvars, "./img/right_wall.xpm");
	tmap->collectible = display_img(tvars, "./img/collectible.xpm");
	tmap->exit = display_img(tvars, "./img/exit.xpm");
	tmap->perso = display_img(tvars, "./img/perso.xpm");
	tmap->mid_wall = display_img(tvars, "./img/obstacle.xpm");
	tmap->ground = display_img(tvars, "./img/ground.xpm");
	tvars->images = tmap;
}

/* make images usable */

static void	*display_img(t_vars *tvars, char *filename)
{
	void	*tmp;

	tmp = mlx_xpm_file_to_image(tvars->mlx, filename,
			&(tvars->img_width), &(tvars->img_height));
	return (tmp);
}
