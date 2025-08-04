/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:48:46 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/29 13:57:44 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int	check_filename(char *file);
static int	check_file_permission(char *file);

int	check_file(int argc, char *file)
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments.\n", 2);
		exit(-1);
	}
	if (check_filename(file) < 0)
		return (-1);
	fd = check_file_permission(file);
	return (fd);
}

static int	check_filename(char *file)
{
	int	i;

	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	if (i == 0 || !i || file[i] != '.')
	{
		ft_putstr_fd("Error\nWrong filename.\n", 2);
		exit(-1);
	}
	if (file[i + 1] && file[i + 2] && file[i + 3] && !file[i + 4])
	{
		if (file[i + 1] == 'c' || file[i + 2] == 'u' || file[i + 3] == 'b')
			return (0);
	}
	ft_putstr_fd("Error\nWrong filename extension.\n", 2);
	exit(-1);
}

static int	check_file_permission(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nWrong file permissions.\n", 2);
		exit(-1);
	}
	return (fd);
}

int	check_first_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1' && str[i] != '\n')
		{
			ft_putstr_fd("Error\nThe map isn't closed.\n", 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	copy_the_map(t_check_data *data, t_params *params, char *str)
{
	int		i;

	i = 0;
	while (i < data->map_height)
	{
		params->map[i] = copy_line(data->map_len, str);
		free(str);
		str = get_next_line(data->fd);
		i++;
	}
	if (str)
		free(str);
	params->map[i] = NULL;
	return (0);
}
