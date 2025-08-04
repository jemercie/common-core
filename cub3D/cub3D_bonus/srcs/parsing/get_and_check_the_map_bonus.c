/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check_the_map_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:48:08 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/20 15:13:08 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static int	is_valid(char **map, int i, int j);
static int	check_first_line(char *str);
static int	check_bn(char **map, int i, int j);

int	get_the_map(char *file, t_check_data *data, t_params *param, int i)
{
	char	*str;

	param->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (open_file(data, file) < 0 || !param->map || \
		get_float_map(data, param) < 0)
		return (malloc_error(data->fd));
	str = get_next_line(data->fd);
	while (str != NULL && is_map(str) == 0)
	{
		free(str);
		str = get_next_line(data->fd);
	}
	while (i < data->map_height)
	{
		param->map[i] = copy_line(data->map_len, str);
		free(str);
		str = get_next_line(data->fd);
		i++;
	}
	if (str)
		free(str);
	param->map[i] = NULL;
	close(data->fd);
	return (0);
}

int	check_the_map(t_check_data *data, char **map)
{
	int		i;
	int		j;

	if (check_first_line(map[0]) < 0)
		return (-1);
	i = 1;
	while (i < data->map_height)
	{
		j = 0;
		if (map[i] && map[i][j] && map[i][j] == '\n' && check_bn(map, i, j) < 0)
			return (map_error());
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == '0' && is_valid(map, i, j) < 0)
				return (-1);
			else if ((map[i][j] == '8' || map[i][j] == 'W' || map[i][j] == 'S'\
				|| map[i][j] == 'E' || map[i][j] == 'N' || map[i][j] == '2') \
				&& is_valid(map, i, j) < 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_bn(char **map, int i, int j)
{
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == '0')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_valid(char **map, int i, int j)
{
	if (!map[i + 1] || !map[i + 1][j] || \
	map[i + 1][j] == ' ' || map[i + 1][j] == '\n')
	{
		ft_putstr_fd("Error\nThe map isn't closed.\n", 2);
		return (-1);
	}
	if (!map[i - 1] || !map[i - 1][j] || \
	map[i - 1][j] == ' ' || map[i - 1][j] == '\n')
	{
		ft_putstr_fd("Error\nThe map isn't closed.\n", 2);
		return (-1);
	}
	if (!map[i][j + 1] || map[i][j + 1] == ' ' || map[i][j + 1] == '\n')
	{
		ft_putstr_fd("Error\nThe map isn't closed.\n", 2);
		return (-1);
	}
	if (!map[i][j - 1] || map[i][j - 1] == ' ' || map[i][j - 1] == '\n')
	{
		ft_putstr_fd("Error\nThe map isn't closed.\n", 2);
		return (-1);
	}
	if (map[i][j] == '2' && is_door_valid(map, i, j) < 0)
		return (-1);
	return (0);
}

static int	check_first_line(char *str)
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
