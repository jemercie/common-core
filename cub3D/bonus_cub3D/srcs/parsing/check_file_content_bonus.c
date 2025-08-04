/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:21:52 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/29 14:03:49 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static int	which_params_is_it(char *str, t_params *params, t_check_data *data);
static int	check_tex_s_and_params(t_params *params, int nb, int fd, char *str);

int	check_file_content(t_params *params, t_check_data *data)
{
	char	*str;
	int		flag_map;
	int		ret;

	flag_map = 0;
	str = get_next_line(data->fd);
	while (str != NULL)
	{
		if (flag_map == 0)
			flag_map = is_map(str);
		ret = check_line(str, flag_map, params, data);
		if (ret == -1)
			return (close_fd_return(data->fd, str));
		free(str);
		str = get_next_line(data->fd);
	}
	if (check_tex_s_and_params(params, data->nb_params, data->fd, str) < 0)
		return (close_fd_return(data->fd, str));
	if (str)
		free(str);
	close(data->fd);
	return (0);
}

int	is_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_whitespace(str[i]) > 0)
		i++;
	if (str[i] && (str[i] == '0' || str[i] == '1'))
		return (1);
	return (0);
}

int	check_line(char *str, int flag, t_params *params, t_check_data *data)
{
	int	i;
	int	ret;
	int	len;

	i = 0;
	ret = 0;
	if (flag == 0)
	{
		skip_isspaces(str, &i);
		if (str == NULL || !str[i] || (str[i] && str[i] == '\n'))
			return (0);
		ret = which_params_is_it(str, params, data);
	}
	else
		data->map_height++;
	len = ft_strlen(str);
	if (len > data->map_len)
		data->map_len = len;
	return (ret);
}

static int	which_params_is_it(char *str, t_params *params, t_check_data *data)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	skip_isspaces(str, &i);
	if (!str[i])
		return (-1);
	if (str[i + 1] && str[i] == 'N' && str[i + 1] == 'O')
		ret = get_param(str, 1, i + 2, params);
	else if (str[i + 1] && str[i] == 'S' && str[i + 1] == 'O')
		ret = get_param(str, 2, i + 2, params);
	else if (str[i + 1] && str[i] == 'W' && str[i + 1] == 'E')
		ret = get_param(str, 3, i + 2, params);
	else if (str[i + 1] && str[i] == 'E' && str[i + 1] == 'A')
		ret = get_param(str, 4, i + 2, params);
	else if (is_color(str, params, data, &ret) < 0)
		return (-1);
	if (ret == 0)
		data->nb_params++;
	return (ret);
}

static int	check_tex_s_and_params(t_params *params, int nb, int fd, char *str)
{
	if (!params->tex_n || !params->tex_w \
	|| !params->tex_e || !params->tex_s)
		return (texture_error(str, fd));
	if (nb != 6)
		return (error_format_color(fd));
	return (0);
}
