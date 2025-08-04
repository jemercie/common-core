/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:22:59 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/29 14:05:21 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

int	parsing(int argc, char **argv, t_params *params)
{
	static t_check_data	data;

	if (argc != 2 || !argv[1])
		return (params_error());
	if (init_struct(params, data) < 0)
		return (-1);
	data.fd = check_file(argc, argv[1]);
	if (data.fd < 0)
		return (-1);
	if (check_file_content(params, &data) < 0)
		return (-1);
	if (get_the_map(argv[1], &data, params, 0) < 0)
		return (-1);
	if (data.map_height < 3 || data.map_len < 3)
		return (map_error());
	if (get_perso_position(params, &data) < 0)
		return (-1);
	if (data.nb_params != 7)
		return (perso_number_error());
	if (check_the_map(&data, params->map) < 0)
		return (-1);
	if (get_sprite_tab(params) < 0)
		return (-1);
	return (0);
}

int	texture_file_error(char *filename)
{
	ft_putstr_fd
	("Error\nA problem occurred while opening the texture file\n", 2);
	if (filename)
		free(filename);
	return (-1);
}

int	close_fd_return(int fd, char *str)
{
	if (str)
		free(str);
	if (fd >= 0)
		close(fd);
	return (-1);
}
