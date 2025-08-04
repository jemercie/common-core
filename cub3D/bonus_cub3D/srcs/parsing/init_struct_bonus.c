/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:01:53 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/29 14:05:48 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static int	open_sprite_and_door_tex_s(t_params *params);

int	init_struct(t_params *params, t_check_data data)
{
	if (open_sprite_and_door_tex_s(params) < 0)
		return (-1);
	data.fd = 0;
	data.f[0] = -1;
	data.f[1] = -1;
	data.f[2] = -1;
	data.c[0] = -1;
	data.c[1] = -1;
	data.c[2] = -1;
	return (0);
}

static int	open_sprite_and_door_tex_s(t_params *params)
{
	params->tex_t = mlx_load_png("./img/TacosXL.png");
	params->tex_p = mlx_load_png("./img/door.png");
	if (!params->tex_t || !params->tex_p)
	{
		ft_putstr_fd("Error\nA problem occurred while \
		loading the door images.\n", 2);
		return (-1);
	}
	params->tex_d[0] = mlx_load_png("./img/patate_qui_sourit_1.png");
	params->tex_d[1] = mlx_load_png("./img/patate_qui_sourit_2.png");
	params->tex_d[2] = mlx_load_png("./img/patate_qui_sourit_3.png");
	params->tex_d[3] = mlx_load_png("./img/patate_qui_sourit_4.png");
	params->tex_d[4] = mlx_load_png("./img/patate_qui_sourit_5.png");
	params->tex_d[5] = mlx_load_png("./img/patate_qui_sourit_6.png");
	params->tex_d[6] = mlx_load_png("./img/patate_qui_sourit_7.png");
	params->tex_d[7] = mlx_load_png("./img/patate_qui_sourit_8.png");
	if (!params->tex_d[0] || !params->tex_d[1] || !params->tex_d[2] || \
		!params->tex_d[3] || !params->tex_d[4] || !params->tex_d[5] || \
		!params->tex_d[6] || !params->tex_d[7])
	{
		ft_putstr_fd("Error\nA problem occurred while \
		loading the sprite images.\n", 2);
		return (-1);
	}
	return (0);
}

int	params_error(void)
{
	ft_putstr_fd("Error\nWrong params.\n", 2);
	return (-1);
}
