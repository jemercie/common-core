/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:22:59 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/28 11:51:34 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	parsing(int argc, char **argv, t_params *params)
{
	static t_check_data	data;

	if (argc != 2 || !argv[1])
	{
		ft_putstr_fd("Error\nWrong params.\n", 2);
		return (-1);
	}
	init_struct(data);
	data.fd = check_file(argc, argv[1]);
	if (data.fd < 0)
		return (-1);
	if (check_file_content(params, &data) < 0)
		return (-1);
	if (get_the_map(argv[1], &data, params) < 0)
		return (-1);
	if (data.map_height < 3 || data.map_len < 3)
		return (map_error());
	if (get_perso_position(params, &data) < 0)
		return (-1);
	if (data.nb_params != 7)
		return (perso_number_error());
	if (check_the_map(params, &data) < 0)
		return (-1);
	return (0);
}
