/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:40:09 by jemercie          #+#    #+#             */
/*   Updated: 2022/10/26 23:19:57 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bufcpy(char *buf, int i)
{
	int	j;

	if (i == 0)
		i = ft_strlen(buf);
	j = 0;
	if (!buf[i])
		buf[0] = '\0';
	while (buf[i])
	{
		buf[j] = buf[i];
		i++;
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		buf[j] = '\0';
		j++;
	}
}

int	ft_is_end_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	int			i;
	int			r;
	char		*s1;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	s1 = NULL;
	r = 1;
	while (r > 0)
	{
		if (!buf[0])
			r = read(fd, buf, BUFFER_SIZE);
		else
		{
			i = ft_is_end_line(buf);
			s1 = ft_gnl_strjoin(s1, buf, i);
			ft_bufcpy(buf, i);
			if ((i == 0 && i == r) || (i > 0))
				return (s1);
		}
	}
	return (s1);
}
