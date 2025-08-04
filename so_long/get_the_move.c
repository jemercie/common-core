/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:30:36 by jemercie          #+#    #+#             */
/*   Updated: 2023/03/07 10:29:49 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_wall(t_vars *tvars, int i, int j);
static void	move_change_map(t_vars *tvars, int i, int j);
static void	move_display_map(t_vars *tvars, int i, int j);

/* check which key is pressed and move accordingly */

int	key_hook(int keynb, t_vars *tvars)
{
	if (keynb == XK_Escape)
		win_exit(tvars);
	if ((keynb == XK_w || keynb == XK_Up) && is_wall(tvars, -1, 0) == 0)
	{
		move_change_map(tvars, -1, 0);
		move_display_map(tvars, -1, 0);
	}
	else if ((keynb == XK_a || keynb == XK_Left) && is_wall(tvars, 0, -1) == 0)
	{
		move_change_map(tvars, 0, -1);
		move_display_map(tvars, 0, -1);
	}
	else if ((keynb == XK_s || keynb == XK_Down) && is_wall(tvars, 1, 0) == 0)
	{
		move_change_map(tvars, 1, 0);
		move_display_map(tvars, 1, 0);
	}
	else if ((keynb == XK_d || keynb == XK_Right) && is_wall(tvars, 0, 1) == 0)
	{
		move_change_map(tvars, 0, 1);
		move_display_map(tvars, 0, 1);
	}
	return (0);
}

static int	is_wall(t_vars *tvars, int i, int j)
{
	if (tvars->map[tvars->y + i][tvars->x + j] == '1')
		return (1);
	return (0);
}

/* change the value of the case the personage is on and next,
	the case the personage will be on and change the img*/

static	void	move_change_map(t_vars *tvars, int i, int j)
{
	if (tvars->map[tvars->y + i][tvars->x + j] == '1')
		return ;
	if (tvars->map[tvars->y][tvars->x] == 'A')
	{
		tvars->map[tvars->y][tvars->x] = 'E';
		put_image(tvars, tvars->images->exit, tvars->y, tvars->x);
	}
	else
	{
	tvars->map[tvars->y][tvars->x] = '0';
		put_image(tvars, tvars->images->ground, tvars->y, tvars->x);
	}
	tvars->nb_move++;
	ft_printf("You moved %d times.\n", tvars->nb_move);
}

/* check if the player won or move the perso */

static void	move_display_map(t_vars *tvars, int i, int j)
{
	tvars->y += i;
	tvars->x += j;
	if (tvars->map[tvars->y][tvars->x] == 'C')
		tvars->collectible--;
	if (tvars->map[tvars->y][tvars->x] == 'E')
	{
		if (tvars->collectible == 0)
			win_exit(tvars);
		else
			tvars->map[tvars->y][tvars->x] = 'A';
	}
	else
		tvars->map[tvars->y][tvars->x] = 'P';
	put_image(tvars, tvars->images->perso, tvars->y, tvars->x);
}
