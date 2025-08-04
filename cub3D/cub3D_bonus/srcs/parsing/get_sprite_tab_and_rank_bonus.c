/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_tab_and_rank_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:10:20 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/19 16:29:59 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	get_sprite_position(char **map, t_sprite *sprite);
static int	count_sprites(char **map);
static void	get_the_rank(t_sprite **sprite, double small, int nb);

int	get_sprite_tab(t_params *params)
{
	int			i;
	int			nb_sprite;

	i = 0;
	nb_sprite = count_sprites(params->map);
	params->sprite = malloc(sizeof(t_sprite *) * (nb_sprite + 1));
	if (!params->sprite)
		return (malloc_error(-1));
	while (i < nb_sprite)
	{
		params->sprite[i] = malloc(sizeof(t_sprite));
		if (!params->sprite[i])
			return (malloc_error(-1));
		get_sprite_position(params->map, params->sprite[i]);
		params->sprite[i]->rank = 0;
		i++;
	}
	params->sprite[i] = NULL;
	get_sprite_rank(params->sprite, params->pos_x, params->pos_y);
	return (0);
}

static void	get_sprite_position(char **map, t_sprite *sprite)
{
	static int	i;
	static int	j;

	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '8')
			{
				sprite->x = j + 0.5;
				sprite->y = i + 0.5;
				j++;
				return ;
			}	
			j++;
		}
		i++;
		j = 0;
	}
}

static int	count_sprites(char **map)
{
	int	nb_sprite;
	int	i;
	int	j;

	nb_sprite = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '8')
				nb_sprite++;
			j++;
		}
		i++;
	}
	return (nb_sprite);
}

int	get_sprite_rank(t_sprite **sprite, double perso_x, double perso_y)
{
	int		i;
	double	pow_x;
	double	pow_y;
	int		nb;
	double	small;

	i = 0;
	nb = 0;
	small = 1.797693e+308;
	while (sprite[i])
	{
		pow_x = pow(perso_x - (sprite[i]->x), 2);
		pow_y = pow(perso_y - (sprite[i]->y), 2);
		sprite[i]->distance = sqrt(pow_x + pow_y);
		if (small > sprite[i]->distance)
			small = sprite[i]->distance;
		i++;
		nb++;
	}
	get_the_rank(sprite, small, nb - 1);
	return (nb);
}

static void	get_the_rank(t_sprite **sprite, double small, int nb)
{
	double	new_small;
	int		i;

	i = 0;
	while (sprite[i])
	{
		sprite[i]->rank = 0;
		i++;
	}
	while (nb > 0)
	{
		new_small = 1.797693e+308;
		i = 0;
		while (sprite[i])
		{
			if (sprite[i]->distance > small)
				sprite[i]->rank++;
			if (new_small > sprite[i]->distance && sprite[i]->distance > small)
				new_small = sprite[i]->distance;
			i++;
		}
		small = new_small;
		nb--;
	}
}
