/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_delete_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:47:17 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/29 13:57:05 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	free_float_tab(float **tab);
static void	delete_sprite_textures(t_params *params);
static void	free_sprite_tab(t_sprite **spritetab);

int	free_and_delete(t_params *params)
{
	if (params->tex_n)
		mlx_delete_texture(params->tex_n);
	if (params->tex_s)
		mlx_delete_texture(params->tex_s);
	if (params->tex_e)
		mlx_delete_texture(params->tex_e);
	if (params->tex_w)
		mlx_delete_texture(params->tex_w);
	if (params->tex_p)
		mlx_delete_texture(params->tex_p);
	if (params->tex_t)
		mlx_delete_texture(params->tex_t);
	delete_sprite_textures(params);
	if (params->map)
		free_char_tab(params->map);
	if (params->tab)
		free_float_tab(params->tab);
	if (params->sprite)
		free_sprite_tab(params->sprite);
	return (-1);
}

void	free_char_tab(char **tabtab)
{
	int	i;

	i = 0;
	if (!tabtab)
		return ;
	while (tabtab[i])
	{
		free(tabtab[i]);
		i++;
	}
	free(tabtab);
	tabtab = NULL;
}

static void	free_sprite_tab(t_sprite **spritetab)
{
	int	i;

	i = 0;
	if (!spritetab)
		return ;
	while (spritetab[i])
	{
		free(spritetab[i]);
		i++;
	}
	free(spritetab);
	spritetab = NULL;
}

static void	free_float_tab(float **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

static void	delete_sprite_textures(t_params *params)
{
	if (params->tex_d[0])
		mlx_delete_texture(params->tex_d[0]);
	if (params->tex_d[1])
		mlx_delete_texture(params->tex_d[1]);
	if (params->tex_d[2])
		mlx_delete_texture(params->tex_d[2]);
	if (params->tex_d[3])
		mlx_delete_texture(params->tex_d[3]);
	if (params->tex_d[4])
		mlx_delete_texture(params->tex_d[4]);
	if (params->tex_d[5])
		mlx_delete_texture(params->tex_d[5]);
	if (params->tex_d[6])
		mlx_delete_texture(params->tex_d[6]);
	if (params->tex_d[7])
		mlx_delete_texture(params->tex_d[7]);
}
