/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:06:38 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/29 14:02:35 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# define SCREEN_WIDTH 900
# define SCREEN_HEIGHT 640

		/**************
		*   INCLUDE   *
		**************/

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "MLX42/MLX42.h"
# include <math.h>
# define P 0xFFAAAAFF
# define Y 0xFFB400FF
# define R 0xCC0000FF
# define O 0xFF8700FF

		/***************
		*	 STRUCTS   *
		***************/

typedef struct s_check_data
{
	int		fd;
	int		f[3];
	int		c[3];
	int		sprite_nb;
	int		map_height;
	int		map_len;
	int		nb_params;
}				t_check_data;

typedef struct s_sprite
{
	int		rank;
	double	distance;
	double	x;
	double	y;
}				t_sprite;

typedef struct s_params
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				fcolor;
	int				ccolor;
	float			**tab;
	char			**map;
	double			perr[SCREEN_WIDTH];
	double			sprite_nb;
	t_sprite		**sprite;
	mlx_texture_t	*texture;
	mlx_texture_t	*tex_n;
	mlx_texture_t	*tex_w;
	mlx_texture_t	*tex_e;
	mlx_texture_t	*tex_s;
	mlx_texture_t	*tex_p;
	mlx_texture_t	*tex_t;
	mlx_texture_t	*tex_d[8];
	mlx_t			*mlx;
	mlx_image_t		*img;
}				t_params;

typedef struct s_cam
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		side2;
	int		map_x;
	int		map_y;
	int		hit;
}				t_cam;

typedef struct s_drawing_params
{
	int		height;
	int		start;
	int		end;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		y;
}				t_draw;

typedef struct s_draw_sprite
{
	int		sprite_screen_x;
	int		sprite_height;
	int		sprite_width;
	int		draw_start_x;
	int		draw_end_x;
	int		draw_start_y;
	int		draw_end_y;
	double	transform_y;
	int		tex_x;
}				t_draw_sprite;

			/****************
			*   FONCTIONS	*
			****************/

/*			parsing_bonus.c					*/
int		parsing(int argc, char **argv, t_params *params);
int		texture_file_error(char *filename);
int		close_fd_return(int fd, char *str);

/*			init_struct_bonus.c				*/
int		init_struct(t_params *params, t_check_data data);
int		params_error(void);

/*			errors_bonus.c					*/
int		error_format_color(int fd);
int		texture_error(char *str, int fd);
int		perso_number_error(void);
int		map_error(void);
int		malloc_error(int fd);

/*			check_file_bonus.c				*/
int		check_file(int argc, char *file);

/*			check_file_content_bonus.c		*/
int		check_file_content(t_params *params, t_check_data *data);
int		check_line(char *str, int flag, t_params *params, t_check_data *data);
int		is_map(char *str);

/*			get_params_bonus.c				*/
int		get_param(char *str, int id_param, int i, t_params *params);

/*			get_perso_position_bonus.c		*/
int		get_perso_position(t_params *params, t_check_data *data);

/*			get_colors_bonus.c				*/
int		is_color(char *str, t_params *params, t_check_data *data, int *ret);

/*			get_and_check_the_map_bonus.c		*/
int		get_the_map(char *file, t_check_data *data, t_params *params, int i);
int		check_the_map(t_check_data *data, char **map);

/*			get_and_check_the_map_utils_bonus.c		*/
char	*copy_line(int len, char *str);
int		open_file(t_check_data *data, char *file);

/*			get_sprite_tab_and_rank_bonus.c	*/
int		get_sprite_tab(t_params *params);
int		get_sprite_rank(t_sprite **sprite, double perso_x, double perso_y);

/*			parsing_utils_bonus.c				*/
void	skip_whitespaces(char	*arg, int *i);
int		is_whitespace(char c);
int		get_rgba(int rgb[3], int a);
int		get_float_map(t_check_data *data, t_params *params);
void	skip_isspaces(char *arg, int *i);

/*			free_and_delete_bonus.c			*/
int		free_and_delete(t_params *params);
void	free_char_tab(char **tabtab);

/*			draw_bonus.c						*/
void	draw_all(t_params *params, int z, t_cam *data);
void	get_the_texture(int side, t_params *params, t_cam *data);
void	draw_floor_and_ceiling(t_draw *draw, t_params *param, int z);
void	draw_pixels(t_cam *data, t_draw *draw, t_params *params, int z);

/*			draw_walls_bonus.c				*/
void	draw_walls(t_cam *data, t_params *params, t_draw *draw, int z);

/*			draw_the_map_bonus.c				*/
void	draw_the_map(t_params *params);

/*			hook_bonus.c						*/
void	ft_hook(void *param);
void	door_key_hook(mlx_key_data_t keydata, void *param);

/*			door_w_s_hook_bonus.c				*/
void	w_s_key_hooks(t_params *params, double pos_x, double pos_y);

/*			calcul_the_view_bonus.c			*/
void	calcul_the_view(t_params *params, t_cam *data);

/*			calcul_images_bonus.c				*/
void	calcul_images(t_params *params, int z);
void	calcul_direction(t_params *params, t_cam *cam, int z);
void	calcul_stripes_size(t_params *params, t_cam *cam);
void	calcul_which_image(t_params *params, t_cam *cam, int z);

/*			door_bonus.c						*/
void	door(t_cam *cam);
int		next_door(t_params *params, t_cam *cam);
int		is_door_valid(char **map, int i, int j);

/*			moove_the_door_bonus.c			*/
void	move_the_door(t_params *params);

/*			draw_sprite_bonus.c				*/
void	draw_sprite(t_params *prm);

#endif
