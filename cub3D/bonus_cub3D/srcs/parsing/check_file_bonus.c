/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:48:46 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/19 16:28:45 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static int	check_filename(int argc, char *file);
static int	check_file_permission(char *file);

int	check_file(int argc, char *file)
{
	int	fd;

	if (check_filename(argc, file) < 0)
		return (-1);
	fd = check_file_permission(file);
	return (fd);
}

static int	check_filename(int argc, char *file)
{
	int	i;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments.\n", 2);
		return (-1);
	}
	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	if (i == 0 || !i || file[i] != '.')
	{
		ft_putstr_fd("Error\nWrong filename.\n", 2);
		return (-1);
	}
	if (file[i + 1] && file[i + 2] && file[i + 3] && !file[i + 4])
	{
		if (file[i + 1] == 'c' || file[i + 2] == 'u' || file[i + 3] == 'b')
			return (0);
	}
	ft_putstr_fd("Error\nWrong filename extension.\n", 2);
	return (-1);
}

static int	check_file_permission(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nWrong file permissions.\n", 2);
		return (-1);
	}
	return (fd);
}
