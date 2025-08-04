/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_the_door_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vline <vline@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:38:20 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/19 16:28:18 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	open_the_door(t_params *params, int k, int l);
static void	close_the_door(t_params *params, int k, int l);

void	move_the_door(t_params *params)
{
	int	k;
	int	l;

	k = 0;
	while (params->map[k] != NULL)
	{
		l = 0;
		while (params->map[k][l] != '\0')
		{
			if (params->map[k][l] == '3')
				open_the_door(params, k, l);
			else if (params->map[k][l] == '4')
				close_the_door(params, k, l);
			l++;
		}
		k++;
	}
	params->sprite_nb += 0.1;
	if (params->sprite_nb >= 8)
		params->sprite_nb = 0;
}

static void	open_the_door(t_params *params, int k, int l)
{
	params->tab[k][l] += 0.01;
	if (params->tab[k][l] >= 1)
	{
		params->tab[k][l] = 1;
		params->map[k][l] = '5';
	}
}

static void	close_the_door(t_params *params, int k, int l)
{
	params->tab[k][l] -= 0.01;
	if (params->tab[k][l] <= 0)
	{
		params->tab[k][l] = 0;
		params->map[k][l] = '2';
	}
}
