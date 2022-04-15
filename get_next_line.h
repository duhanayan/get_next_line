/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:20:06 by dayan             #+#    #+#             */
/*   Updated: 2022/02/10 22:20:08 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ustfonk(int fd, char *tutucu);
char	*get_next_line(int fd);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *tutucu, char *str);
char	*get_line(char *tutucu);
char	*new_tutucu(char *tutucu);

#endif
