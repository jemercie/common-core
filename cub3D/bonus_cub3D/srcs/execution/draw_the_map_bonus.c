/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_the_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:29:30 by vline             #+#    #+#             */
/*   Updated: 2023/08/19 16:28:03 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	draw_map_background(t_params *params);
static void	draw_map_area(t_params *params);
static void	draw_a_square_of_the_map(t_params *params, int i, int j, char c);
static void	draw_pixel_position(t_params *params);

void	draw_the_map(t_params *params)
{
	draw_map_background(params);
	draw_map_area(params);
	draw_pixel_position(params);
}

static void	draw_map_background(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < (130))
	{
		i = 0;
		while (i < (130))
		{
			mlx_put_pixel(params->img, i, j, 0xFFFFFFFF);
			i++;
		}
		j++;
	}
}

static void	draw_map_area(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	while (i < 11)
	{
		while (params->pos_y - 5 + i < 0 && params->map[i] != NULL)
			i++;
		j = 0;
		if (params->map[(int)(params->pos_y + i - 6)] == NULL)
			break ;
		while (params->pos_x - 5 + j < 0)
			j++;
		while (params->map[(int)(params->pos_y + i - 5)] != NULL \
			&& params->map[(int)(params->pos_y + i - 5)] \
			[(int)params->pos_x + j - 5] != '\0' && j < 11)
		{
			if (params->pos_x + j - 5 >= 0)
				draw_a_square_of_the_map(params, i, j, params->map[(int) \
				(params->pos_y + i - 5)][(int)(params->pos_x + j - 5)]);
			j++;
		}
		i++;
	}
}

static void	draw_a_square_of_the_map(t_params *params, int i, int j, char c)
{
	int	k;
	int	l;

	k = 0;
	while (k < 10)
	{
		l = 0;
		while (l < 10 && ft_strlen(params->map[(int)(params->pos_y + i - 5)]) \
		> params->pos_x + j - 5)
		{
			if (c == '1')
				mlx_put_pixel(params->img, l + j * 10 + 10, k + i * 10 + 10, P);
			else if (c == '0')
				mlx_put_pixel(params->img, l + j * 10 + 10, k + i * 10 + 10, Y);
			else if (c >= '2' && c <= '5')
				mlx_put_pixel(params->img, l + j * 10 + 10, k + i * 10 + 10, R);
			else if (c == '8')
				mlx_put_pixel(params->img, l + j * 10 + 10, k + i * 10 + 10, O);
			l++;
		}
		k++;
	}
}

static void	draw_pixel_position(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < (10))
	{
		i = 0;
		while (i < (10))
		{
			mlx_put_pixel(params->img, i + 60, j + 60, 0xFFFFFFFF);
			i++;
		}
		j++;
	}
}
