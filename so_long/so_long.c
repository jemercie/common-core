/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:29:17 by jemercie          #+#    #+#             */
/*   Updated: 2023/03/11 17:06:58 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_perso_position(t_vars *tvars);
static int	check_input(char *input, char *str);

int	main(int argc, char **argv)
{
	t_map	tmap;
	t_vars	tvars;

	if (argc != 2 || check_input(argv[1], ".ber") < 0)
	{
		ft_putstr_fd("Error\nWrong input\n", 2);
		return (0);
	}
	init_structs(&tvars, &tmap);
	tvars.map = get_the_map(argv[1], &tvars);
	tvars.win = mlx_new_window(tvars.mlx, (tvars.img_height * (tvars.y - 1)),
			(tvars.img_width * (tvars.x - 1)), "so_long");
	if (!tvars.win)
		win_exit(&tvars);
	print_map(&tvars);
	get_perso_position(&tvars);
	mlx_key_hook(tvars.win, key_hook, &tvars);
	mlx_hook(tvars.win, 17, 0, win_exit, &tvars);
	mlx_loop(tvars.mlx);
	free_tab(tvars.map);
	return (0);
}

static int	check_input(char *input, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (input[i] == '.')
		return (-1);
	while (input[i] != '.')
		i++;
	if (input[i - 1] == '/')
		return (-1);
	while (input[i] && str[j])
	{
		if (input[i] != str[j])
			return (-1);
		i++;
		j++;
	}
	if (j == 4 && !input[i])
		return (0);
	return (-1);
}

static void	get_perso_position(t_vars *tvars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tvars->map[i])
	{
		while (tvars->map[i][j] != '\n')
		{
			if (tvars->map[i][j] == 'P')
			{
				tvars->x = j;
				tvars->y = i;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
