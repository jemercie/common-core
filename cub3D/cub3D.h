/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:06:38 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/29 14:01:17 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
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
# include "libft/libft.h"
# include "MLX42/MLX42.h"
# include <math.h>

			/***************
			*    STRUCTS   *
			***************/

typedef struct s_check_data
{
	int		fd;
	int		f[3];
	int		c[3];
	int		map_height;
	int		map_len;
	int		nb_params;
}				t_check_data;

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
	char			**map;
	mlx_texture_t	*texture;
	mlx_texture_t	*tex_n;
	mlx_texture_t	*tex_w;
	mlx_texture_t	*tex_e;
	mlx_texture_t	*tex_s;
	mlx_t			*mlx;
	mlx_image_t		*img;
}				t_params;

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

typedef struct s_calcul_params
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}				t_calcul_params;

			/****************
			*   FONCTIONS	*
			****************/

/*			parsing.c					*/
int		parsing(int argc, char **argv, t_params *params);

/*			init_struct.c			*/
void	init_struct(t_check_data data);
void	init_calcul_param_struct(t_calcul_params *data, int z, t_params *param);

/*			errors.c				*/
int		error_format_color(int fd);
int		texture_file_error(char *filename);
int		texture_error(char *str, int fd);
int		map_error(void);
int		perso_number_error(void);

/*			check_file.c			*/
int		check_file(int argc, char *file);
int		copy_the_map(t_check_data *data, t_params *params, char *str);
int		check_first_line(char *str);

/*			check_file_content.c	*/
int		check_file_content(t_params *params, t_check_data *data);
int		check_line(char *str, int flag, t_params *params, t_check_data *data);
int		is_map(char *str);

/*			get_params.c			*/
int		get_param(char *str, int id_param, int i, t_params *params);

/*			get_perso_position.c	*/
int		get_perso_position(t_params *params, t_check_data *data);

/*			get_colors.c					*/
int		is_color(char *str, t_params *params, t_check_data *data, int *ret);

/*			get_and_check_the_map.c	*/
int		get_the_map(char *file, t_check_data *data, t_params *params);
int		check_the_map(t_params *params, t_check_data *data);
char	*copy_line(int len, char *str);

/*			parsing_utils.c			*/
void	skip_whitespaces(char	*arg, int *i);
int		is_whitespace(char c);
int		get_rgba(int rgb[3], int a);
void	skip_isspaces(char *arg, int *i);
int		malloc_error(void);

/*			free-and_close.c		*/
void	close_and_free(t_params *params);
void	free_tab(char **tabtab);
int		close_fd_return(int fd, char *str);

/*			draw.c					*/
void	draw_all(t_params *params, int z, t_calcul_params *data);
void	get_the_texture(int side, t_params *params, t_calcul_params *data);
void	draw_floor_and_ceiling(t_draw *draw, t_params *param, int z);
void	draw_walls(t_calcul_params *data, t_params *param, t_draw *draw, int z);

/*			hook.c					*/
void	ft_hook(void *param);

/*			calcul_the_view.c		*/
void	calcul_the_view(t_params *params, int z, t_calcul_params *data);

#endif
