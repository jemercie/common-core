/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:08:08 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/29 13:45:24 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static int	get_color_format(char *str, int i, int *rgb);
static int	check_color_format(int *rgb);

int	is_color(char *str, t_params *params, t_check_data *data, int *ret)
{
	int	i;

	i = 0;
	skip_isspaces(str, &i);
	if (str[i] == 'F')
	{
		if (get_color_format(str, i + 1, data->f) < 0)
			return (-1);
		params->fcolor = get_rgba(data->f, 255);
		*ret = 0;
		return (0);
	}
	else if (str[i] == 'C')
	{
		if (get_color_format(str, i + 1, data->c) < 0)
			return (-1);
		params->ccolor = get_rgba(data->c, 255);
		*ret = 0;
		return (0);
	}
	*ret = 1;
	return (0);
}

static int	get_color_format(char *str, int i, int *rgb)
{
	int	comma;
	int	j;

	comma = 0;
	skip_isspaces(str, &i);
	j = i;
	while (str[i] && str[i] != '\n')
	{
		while (str[i] && str[i] != ',' && str[i] != '\n')
		{
			if (ft_isdigit(str[i]) == 0 || ((i - j - comma) > 8))
				return (error_format_color(-1));
			rgb[comma] = (rgb[comma] * 10) + str[i] - '0';
			i++;
		}
		skip_isspaces(str, &i);
		if (str[i] == ',')
			comma++;
		if (str[i] == ',')
			i++;
	}
	if (comma != 2 || check_color_format(rgb) < 0)
		return (error_format_color(-1));
	return (0);
}

static int	check_color_format(int *rgb)
{
	if (rgb[0] < 0 || rgb[0] > 255)
		return (-1);
	if (rgb[1] < 0 || rgb[1] > 255)
		return (-1);
	if (rgb[2] < 0 || rgb[2] > 255)
		return (-1);
	return (0);
}
