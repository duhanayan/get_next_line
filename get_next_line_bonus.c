/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:25:20 by dayan             #+#    #+#             */
/*   Updated: 2022/02/10 22:25:21 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ustfonk(int fd, char *tutucu)
{
	char	*oku;
	int		okunan;

	oku = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!oku)
		return (NULL);
	okunan = 1;
	while (okunan != 0 && !ft_strchr(tutucu, '\n'))
	{
		okunan = read(fd, oku, BUFFER_SIZE);
		if (okunan == -1)
		{
			free(oku);
			return (NULL);
		}
		oku[okunan] = '\0';
		tutucu = ft_strjoin(tutucu, oku);
	}
	free(oku);
	return (tutucu);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*tutucu[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tutucu[fd] = ustfonk(fd, tutucu[fd]);
	if (!tutucu[fd])
		return (NULL);
	line = get_line(tutucu[fd]);
	tutucu[fd] = new_tutucu(tutucu[fd]);
	return (line);
}
