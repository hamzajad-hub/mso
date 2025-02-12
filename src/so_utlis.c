/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utlis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajadid <hajadid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:04:09 by hajadid           #+#    #+#             */
/*   Updated: 2025/02/12 15:04:10 by hajadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	calcu_how_many_coins(t_maps *t_map)
{
	int (x), (y), (total_coins);
	x = 0;
	total_coins = 0;
	while (t_map->map[x])
	{
		y = 0;
		while (t_map->map[x][y])
		{
			if (t_map->map[x][y] == 'C')
				total_coins++;
			y++;
		}
		x++;
	}
	return (total_coins);
}
