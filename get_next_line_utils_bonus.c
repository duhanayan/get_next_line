/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:30:36 by dayan             #+#    #+#             */
/*   Updated: 2022/02/10 22:30:37 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *tutucu, char *oku)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!tutucu)
	{
		tutucu = malloc(sizeof(char) * 1);
		tutucu[0] = '\0';
	}
	if (!tutucu || !oku)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(tutucu) + ft_strlen(oku) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (tutucu)
		while (tutucu[++i] != '\0')
			str[i] = tutucu[i];
	while (oku[j] != '\0')
		str[i++] = oku[j++];
	str[i] = '\0';
	free(tutucu);
	return (str);
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
