/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaga-agu <eaga-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:17:20 by eaga-agu          #+#    #+#             */
/*   Updated: 2025/05/07 15:51:33 by eaga-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}


