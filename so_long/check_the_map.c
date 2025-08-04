/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:31:24 by jemercie          #+#    #+#             */
/*   Updated: 2023/03/11 17:36:13 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int			check_walls(char **map, int i, int j);
static char	**map_copy(char **map);
static int	is_there_a_way(char **copy, int i, int j);
static void	pathfinding(char **copy, int i, int j);

/* check if there is a way in the map, if there is walls */

int	check_map(char **map)
{
	int		i;
	int		j;
	char	**copy;

	copy = map_copy(map);
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'P' && is_there_a_way(copy, i, j) >= 0)
			{
				free_tab(copy);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_tab(copy);
	return (-1);
}

int	check_walls(char **map, int i, int j)
{
	int	len;

	len = ft_strlen(map[0]);
	while (map[i][j] && map[i][j] != '\n')
	{
		if (map[i][j] != '1')
			return (-1);
		j++;
	}
	j = 0;
	while (map[i])
	{
		if (map [i][0] != '1' || map[i][len - 2] != '1')
			return (-1);
		i++;
	}
	while (map[i - 1][j] && map[i - 1][j] != '\n')
	{
		if (map[i - 1][j] != '1')
			return (-1);
		j++;
	}
	return (0);
}

/* check if there is any collectible or the exit after the flood fill */

static int	is_there_a_way(char **copy, int i, int j)
{
	pathfinding(copy, i, j);
	i = 0;
	j = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'E' || copy[i][j] == 'C')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

/* flood fill the map for see is the perso can reach every 
		collectible and the exit */

static void	pathfinding(char **copy, int i, int j)
{
	if (copy[i + 1][j] && copy[i + 1][j] != '1')
	{
		copy[i][j] = '2';
		if (copy[i + 1][j] != '2')
			pathfinding(copy, i + 1, j);
	}
	if (copy[i][j - 1] && copy[i][j - 1] != '1')
	{
		copy[i][j] = '2';
		if (copy[i][j - 1] != '2')
			pathfinding(copy, i, j - 1);
	}
	if (copy[i][j + 1] && copy[i][j + 1] != '1')
	{
		copy[i][j] = '2';
		if (copy[i][j + 1] != '2')
			pathfinding(copy, i, j + 1);
	}
	if (copy[i - 1][j] && copy[i - 1][j] != '1')
	{
		copy[i][j] = '2';
		if (copy[i - 1][j] != '2')
			pathfinding(copy, i - 1, j);
	}
}

static char	**map_copy(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
