/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:39:04 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/19 16:29:48 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static int	open_texture_file(int id_param, char *filename, t_params *params);
static char	*get_filename(char *str, int i);
static int	get_filename_len(char *str, int i);
static int	open_texture(mlx_texture_t **tex, char *filename);

int	get_param(char *str, int id, int i, t_params *params)
{
	int		fd;
	char	*filename;
	int		ret;

	filename = NULL;
	ret = 1;
	if (id > 0 && id < 5)
	{
		filename = get_filename(str, i);
		fd = open(filename, O_RDONLY);
		if (fd < 0)
			return (texture_file_error(filename));
		close(fd);
		if (open_texture_file(id, filename, params) < 0)
			return (texture_file_error(filename));
		ret = 0;
	}
	if (filename)
		free(filename);
	return (ret);
}

static int	open_texture_file(int id_param, char *filename, t_params *params)
{
	if (id_param == 1)
	{
		if (open_texture(&params->tex_n, filename) < 0)
			return (-1);
	}
	else if (id_param == 2)
	{
		if (open_texture(&params->tex_s, filename) < 0)
			return (-1);
	}
	else if (id_param == 3)
	{
		if (open_texture(&params->tex_w, filename) < 0)
			return (-1);
	}
	else if (id_param == 4)
	{
		if (open_texture(&params->tex_e, filename) < 0)
			return (-1);
	}
	return (0);
}

static int	open_texture(mlx_texture_t **tex, char *filename)
{
	if (*tex)
		return (-1);
	*tex = mlx_load_png(filename);
	if (!*tex)
		return (-1);
	return (0);
}

static char	*get_filename(char *str, int i)
{
	int		j;
	int		len;
	char	*filename;

	j = 0;
	skip_isspaces(str, &i);
	if (!str[i] || !str[i + 1] || str[i] != '.' || str[i + 1] != '/')
		return (NULL);
	len = get_filename_len(str, i);
	if (len == 2)
		return (NULL);
	filename = malloc(sizeof(char) * (len + 1));
	while (str[i] && j < len)
	{
		filename[j] = str[i];
		i++;
		j++;
	}
	filename[j] = '\0';
	return (filename);
}

static int	get_filename_len(char *str, int i)
{
	int	len;
	int	spc;

	len = 2;
	spc = 0;
	while (str[i + len] && str[i + len] != '\n')
	{
		if (str[i + len] && ft_isspace(str[i + len]) > 0)
		{
			while (str[i + len + spc] && ft_isspace(str[i + len + spc]) > 0)
				spc++;
		}
		else
			len++;
		if (spc != 0 && str[i + len + spc])
		{
			len += spc;
			spc = 0;
		}
	}
	return (len);
}
