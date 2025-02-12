/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajadid <hajadid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:57:41 by hajadid           #+#    #+#             */
/*   Updated: 2025/02/12 14:57:42 by hajadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**full_map(int fd, int rows)
{
	char	*line;
	char	**str;
	int		i;

	i = 0;
	str = malloc((rows + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		str[i] = line;
		line = get_next_line(fd);
		i++;
	}
	str[i] = NULL;
	close(fd);
	return (str);
}
