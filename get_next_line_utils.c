/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:19:38 by dayan             #+#    #+#             */
/*   Updated: 2022/02/10 22:19:41 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *tutucu, char *str)
{
	int		i;
	int		j;
	char	*s;

	if (!tutucu)
	{
		tutucu = malloc(sizeof(char) * 1);
		tutucu[0] = '\0';
	}
	if (!tutucu || !str)
		return (NULL);
	s = malloc(sizeof(char) * (ft_strlen(tutucu) + ft_strlen(str) + 1));
	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	if (tutucu)
		while (tutucu[++i])
			s[i] = tutucu[i];
	while (str[j])
		s[i++] = str[j++];
	s[i] = '\0';
	free(tutucu);
	return (s);
}

char	*get_line(char *tutucu)
{
	int		i;
	char	*str;

	i = 0;
	if (!tutucu[i])
		return (NULL);
	while (tutucu[i] && tutucu[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (tutucu[i] && tutucu[i] != '\n')
	{
		str[i] = tutucu[i];
		i++;
	}
	if (tutucu[i] == '\n')
	{
		str[i] = tutucu[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_tutucu(char *tutucu)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (tutucu[i] && tutucu[i] != '\n')
		i++;
	if (!tutucu[i])
	{
		free(tutucu);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(tutucu) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (tutucu[i])
		str[j++] = tutucu[i++];
	str[j] = '\0';
	free(tutucu);
	return (str);
}
