/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_enverment.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajadid <hajadid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:58:16 by hajadid           #+#    #+#             */
/*   Updated: 2025/02/12 14:58:17 by hajadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	push_imag_coin(t_window *win, int x, int y)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win,
		win->imag_coin[0], y * 64, x * 64);
	mlx_put_image_to_window(win->mlx, win->mlx_win,
		win->imag_coin[1], y * 64, x * 64);
	mlx_put_image_to_window(win->mlx, win->mlx_win,
		win->imag_coin[2], y * 64, x * 64);
}

void	push_image_window(t_window *win, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			win->imag_wall, y * 64, x * 64);
	else if (c == 'P')
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			win->t_plyer->plyer_front[0], y * 64, x * 64);
	else if (c == 'X')
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			win->imag_enemy[0], y * 64, x * 64);
	else if (c == '0')
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			win->imag_floor, y * 64, x * 64);
	else if (c == 'E')
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			win->imag_exit[0], y * 64, x * 64);
}

void	push_image_to_window(t_window *win, t_maps t_map)
{
	int (x), (y);
	x = 0;
	while (x < t_map.rows)
	{
		y = 0;
		while (y < t_map.length_of_line)
		{
			if (t_map.map[x][y] == '1')
				push_image_window(win, x, y, '1');
			else if (t_map.map[x][y] == 'P')
				push_image_window(win, x, y, 'P');
			else if (t_map.map[x][y] == '0')
				push_image_window(win, x, y, '0');
			else if (t_map.map[x][y] == 'E')
				push_image_window(win, x, y, 'E');
			else if (t_map.map[x][y] == 'C')
				push_imag_coin(win, x, y);
			else if (t_map.map[x][y] == 'X')
				push_image_window(win, x, y, 'X');
			y++;
		}
		x++;
	}
}

void	initialization_enverment(t_window *win, t_maps t_map)
{
	win->mlx = mlx_init();
	if (!win->mlx)
	{
		perror("Error initializing MLX");
		exit(1);
	}
	win->mlx_win = mlx_new_window(win->mlx,
			t_map.length_of_line * 64, t_map.rows * 64, "so_long");
	if (!win->mlx_win)
	{
		ft_putstr_fd("Error:\nFailed to create window\n", 2);
		mlx_destroy_window(win->mlx, win->mlx_win);
	}
	texture_loader(win);
	push_image_to_window(win, t_map);
	win->total_coins = calcu_how_many_coins(&t_map);
}
