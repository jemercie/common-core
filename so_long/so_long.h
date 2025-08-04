/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:46:37 by jemercie          #+#    #+#             */
/*   Updated: 2023/03/07 10:24:08 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <mlx_int.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include "./ft_printf/libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>

typedef struct s_map
{	
	void	*corner_up_right;
	void	*corner_up_left;
	void	*corner_down_right;
	void	*corner_down_left;
	void	*wall_up;
	void	*wall_down;
	void	*wall_left;
	void	*wall_right;
	void	*collectible;
	void	*exit;
	void	*perso;
	void	*mid_wall;
	void	*ground;
}				t_map;

typedef struct s_vars
{
	int		x;
	int		y;
	int		key;
	int		nb_move;
	int		img_width;
	int		img_height;
	int		collectible;
	void	*mlx;
	void	*win;
	char	**map;
	t_map	*images;
}				t_vars;

/*          check_the_map.c          */
int		check_map(char **map);
int		check_walls(char **map, int i, int j);

/*          get_the_map.c          */
char	**get_the_map(char *file, t_vars *tvars);

/*          init_struct.c          */
void	init_structs(t_vars *tvars, t_map *tmap);

/*          display_map.c          */
int		print_map(t_vars *tvars);
void	put_image(t_vars *tvars, void *img, int i, int j);

/*          get_the_move.c          */
int		key_hook(int keynb, t_vars *tvars);

/*          destroy_and_free.c          */
int		win_exit(t_vars *tvars);
void	free_tab(char **str);

#endif
