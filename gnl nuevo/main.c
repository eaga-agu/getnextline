/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaga-agu <eaga-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:08:28 by eaga-agu          #+#    #+#             */
/*   Updated: 2025/05/08 15:49:09 by eaga-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open ("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error al abrir el archivo");
		return (1);
	}
	while (1)
	{
		next_line = get_next_line (fd);
		if (next_line == NULL)
			break;
		count++;
		printf ("[%d]:%s\n", count, next_line);
		free (next_line);
		next_line = NULL;
	}
	close(fd);
	return (0);
}