/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaga-agu <eaga-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:17:37 by eaga-agu          #+#    #+#             */
/*   Updated: 2025/05/09 14:42:13 by eaga-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*save_remaining(char *save)
{
	int		i;
	int		n;
	char	*new_save;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	new_save = ft_calloc(sizeof(char), (ft_strlen(save) - i + 1));
	i++;
	n = 0;
	while (save[i] != '\0')
		new_save[n++] = save[i++];
	free(save);
	return (new_save);
}

char	*make_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save || save[0] == '\0')
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
        line = ft_calloc(i + 2, sizeof(char));
	else
        line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_file(char *save, int fd)
{
	char	*tmp;
	int		chars_read;

	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return ( NULL);
	chars_read = 1;
	while (chars_read > 0 )
	{
		chars_read = read(fd, tmp, BUFFER_SIZE);
		if (chars_read == -1)
			return (free(tmp), free(save), NULL);
		tmp[chars_read] = '\0';
		save = ft_strjoin_and_free(save, tmp);
		if(ft_strchr(save, '\n'))
		break;
	}
	free(tmp);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!save)
	save = ft_calloc(1,sizeof(char));
	if (!ft_strchr(save, '\n'))
	save = read_file(save, fd);
	if (!save)
	return (free(save), NULL);
	line = make_line(save);
	save = save_remaining(save);
	return (line);
}
