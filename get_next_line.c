/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:19:27 by dayan             #+#    #+#             */
/*   Updated: 2022/02/10 22:19:31 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char		*tutucu;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tutucu = ustfonk(fd, tutucu);
	if (!tutucu)
		return (NULL);
	line = get_line(tutucu);
	tutucu = new_tutucu(tutucu);
	return (line);
}
