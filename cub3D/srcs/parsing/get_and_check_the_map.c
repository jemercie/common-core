/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check_the_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:48:08 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/28 11:41:17 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int	is_valid(char **map, int i, int j);
static int	check_bn(char **map, int i, int j);

int	get_the_map(char *file, t_check_data *data, t_params *params)
{
	int		i;
	char	*str;

	i = 0;
	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
	{
		ft_putstr_fd("Error\na problem occured opening the file\n.", 2);
		return (-1);
	}
	params->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!params->map)
	{
		close(data->fd);
		return (malloc_error());
	}
	str = get_next_line(data->fd);
	while (str != NULL && is_map(str) == 0)
	{
		free(str);
		str = get_next_line(data->fd);
	}
	copy_the_map(data, params, str);
	close(data->fd);
	return (0);
}

int	check_the_map(t_params *params, t_check_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = params->map;
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
			else if ((map[i][j] == 'W' || map[i][j] == 'S'\
			|| map[i][j] == 'E' || map[i][j] == 'N') && is_valid(map, i, j) < 0)
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
	return (0);
}

char	*copy_line(int len, char *str)
{
	int		i;
	char	*copy;

	i = 0;
	copy = ft_calloc(1, (len + 1));
	if (!str)
		return (NULL);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	return (copy);
}
