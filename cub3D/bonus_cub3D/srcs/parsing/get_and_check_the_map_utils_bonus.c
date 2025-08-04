/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check_the_map_utils_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:23:48 by jemercie          #+#    #+#             */
/*   Updated: 2023/08/19 16:29:18 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

char	*copy_line(int len, char *str)
{
	int		i;
	char	*copy;

	i = 0;
	copy = ft_calloc(1, (len + 1));
	if (!str)
		return (NULL);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	return (copy);
}

int	open_file(t_check_data *data, char *file)
{
	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
		return (-1);
	return (0);
}
