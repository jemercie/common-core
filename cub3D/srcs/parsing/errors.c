/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:50:39 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/29 13:44:27 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	error_format_color(int fd)
{
	if (fd >= 0)
		close(fd);
	ft_putstr_fd("Error\nWrong color format.\n", 2);
	return (-1);
}

int	texture_file_error(char *filename)
{
	ft_putstr_fd("Error\nWrong texture file.\n", 2);
	if (filename)
		free(filename);
	return (-1);
}

int	texture_error(char *str, int fd)
{
	ft_putstr_fd("Error\nWrong textures.\n", 2);
	if (str)
		free(str);
	close(fd);
	return (-1);
}

int	perso_number_error(void)
{
	ft_putstr_fd("Error\nWrong number of perso.\n", 2);
	return (-1);
}

int	map_error(void)
{
	ft_putstr_fd("Error\nThe map is wrong.\n", 2);
	return (-1);
}
