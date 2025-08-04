/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_close_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:47:17 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/29 14:02:43 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	delete_textures(t_params *params);

void	close_and_free(t_params *params)
{
	if (params->map)
		free_tab(params->map);
	delete_textures(params);
}

void	free_tab(char **tabtab)
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

static void	delete_textures(t_params *params)
{
	if (params->tex_n)
		mlx_delete_texture(params->tex_n);
	if (params->tex_s)
		mlx_delete_texture(params->tex_s);
	if (params->tex_e)
		mlx_delete_texture(params->tex_e);
	if (params->tex_w)
		mlx_delete_texture(params->tex_w);
}

int	close_fd_return(int fd, char *str)
{
	if (str)
		free(str);
	if (fd >= 0)
		close(fd);
	return (-1);
}
