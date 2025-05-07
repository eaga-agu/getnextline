/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaga-agu <eaga-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:31:13 by eaga-agu          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/05/05 12:24:56 by eaga-agu         ###   ########.fr       */
=======
/*   Updated: 2025/05/07 13:57:20 by eaga-agu         ###   ########.fr       */
>>>>>>> 5fc5adc (7 mayo)
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

<<<<<<< HEAD
char	*the_rest(char *save)
=======
char	*save_remaining(char *save)
>>>>>>> 5fc5adc (7 mayo)
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

<<<<<<< HEAD
char	*make_line_from(char *save)
=======
char	*make_line(char *save)
>>>>>>> 5fc5adc (7 mayo)
{
	int		i;
	char	*line;

	if (!save || save[0] == '\0')
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (save[i] == '\n' ? i + 2 : i + 1));
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

<<<<<<< HEAD
char	*read_until_enter(int fd, char *save)
=======
char	*read_until_line_end(int fd, char *save)
>>>>>>> 5fc5adc (7 mayo)
{
	int		n_of_chars;
	char	*tmp;

	if (!save)
		save = ft_calloc(1, 1);
	tmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	n_of_chars = 1;
	while (n_of_chars > 0)
	{
		n_of_chars = read(fd, tmp, BUFFER_SIZE);
		if (n_of_chars == -1)
		{
			free(tmp);
			free(save);
			return (NULL);
		}
		tmp[n_of_chars] = '\0';
		save = ft_free_strjoin(save, tmp);
		if (ft_strchr(save, '\n'))
			break ;
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
<<<<<<< HEAD
	save = read_until_enter(fd, save);
	if (save == NULL)
		return (NULL);
	line = make_line_from(save);
	save = the_rest(save);
=======
	char	*read_until_line_end(int fd, char *save)
	save = (fd, save);
	if (save == NULL)
		return (NULL);
	line = make_line(save);
	save = same_remaining(save);
>>>>>>> 5fc5adc (7 mayo)
	return (line);
}

