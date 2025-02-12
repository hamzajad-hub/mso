/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utlis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajadid <hajadid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:58:43 by hajadid           #+#    #+#             */
/*   Updated: 2025/02/12 14:58:44 by hajadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	open_door(t_window *win)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win,
		win->imag_exit[win->animation_frame], win->t_map->exit_y * 64,
		win->t_map->exit_x * 64);
}
