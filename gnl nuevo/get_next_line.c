/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaga-agu <eaga-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:17:37 by eaga-agu          #+#    #+#             */
/*   Updated: 2025/05/08 15:10:45 by eaga-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		bytes_read;
	char	*buf;

	buf = ft_calloc (5, sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read = read(fd, buf, 5);
	if (bytes_read <= 0)
		return (NULL);
	return (buf);
}
 
