/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:04:46 by jemercie          #+#    #+#             */
/*   Updated: 2023/03/11 17:10:17 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**get_the_file(int i, char *file);
static int	is_map_valid(char **map, t_vars *tvars);
static int	check_char(char **map, t_vars *tvars, int i, int j);
static int	count_lines(char *file);

/* check that the map is valid and get the map */

char	**get_the_map(char *file, t_vars *tvars)
{
	int		i;
	char	**map;

	map = NULL;
	tvars->x = count_lines(file);
	i = tvars->x;
	if (i > 2)
		map = get_the_file(i, file);
	else
		win_exit(tvars);
	if (map == NULL || is_map_valid(map, tvars) < 0)
	{
		free_tab(map);
		ft_putstr_fd("Error\nWrong map, try another one.\n", 2);
		win_exit(tvars);
	}
	i = 0;
	tvars->y = ft_strlen(map[i]);
	return (map);
}

/* get the contents of the .ber file and store it in map */

static char	**get_the_file(int i, char *file)
{
	char	**map;
	int		j;
	int		fd;

	j = 0;
	map = malloc(sizeof(char *) * (i + 1));
	map[i + j] = NULL;
	fd = open(file, O_RDONLY);
	map[j] = get_next_line(fd);
	while (map[j])
	{
		j++;
		map[j] = get_next_line(fd);
	}
	close(fd);
	return (map);
}

/* count the number of lines to be able to malloc and check
			if their length is the same */

static int	count_lines(char *file)
{
	int		fd;
	char	*str;
	size_t	len;
	int		i;

	fd = open(file, O_RDONLY);
	i = 1;
	str = get_next_line(fd);
	len = ft_strlen(str);
	while (str != NULL)
	{
		i++;
		if (ft_strlen(str) != len)
		{
			close(fd);
			free(str);
			return (-1);
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	free(str);
	return (i);
}

static int	is_map_valid(char **map, t_vars *tvars)
{
	if (check_walls(map, 0, 0) < 0)
		return (-1);
	if (check_char(map, tvars, 0, 0) < 0)
		return (-1);
	if (check_map(map) < 0)
		return (-1);
	return (0);
}

/* check if the characters are correct (1, 0, E, P, C) */

static int	check_char(char **map, t_vars *tvars, int i, int j)
{
	int	p;
	int	e;

	p = 0;
	e = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				tvars->collectible++;
			else if (map[i][j] == 'E')
				e++;
			else if (map[i][j] == 'P')
				p++;
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n')
				return (-1);
			j++;
		}
		i++;
	}
	if (e != 1 || p != 1 || tvars->collectible < 1)
		return (-1);
	return (0);
}
