/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaga-agu <eaga-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:48:23 by eaga-agu          #+#    #+#             */
/*   Updated: 2025/05/05 12:08:16 by eaga-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>    // Para open()
#include <unistd.h>   // Para close()
#include <stdio.h>    // Para printf()
#include <stdlib.h>   // Para free()

#include "get_next_line.h"

int main(void)
{
	int     fd;
	char    *line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
    {
        perror("No se pudo abrir el archivo");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}