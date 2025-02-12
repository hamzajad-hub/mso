/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajadid <hajadid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:04:00 by hajadid           #+#    #+#             */
/*   Updated: 2025/02/12 15:04:02 by hajadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "get_next_line.h"
# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h>

# define MAX_ROWS 16
# define MAX_COLS 30

enum	e_key_pord
{
	FRONT = 0,
	BACK = 1,
	LEFT = 2,
	RIGTH = 3,
	ESCAPE = 65307,
	KEY_UP = 119,
	KEY_DOWN = 115,
	KEY_LEFT = 97,
	KEY_RIGHT = 100,
};

typedef struct s_map
{
	int		x;
	int		y;
	int		fd;
	int		rows;
	int		length_of_line;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	char	**cpy_map;
	char	**map;
}	t_maps;

typedef struct s_animation_player
{
	void	*plyer_front[3];
	void	*plyer_back[3];
	void	*plyer_right[3];
	void	*plyer_left[3];
	int		cur_fram;
	int		direction;
	int		animation_speed;
	int		counter_player;
	int		is_moving;
	int		not_move;
}	t_player;

typedef struct s_data_window
{
	void		*mlx;
	void		*mlx_win;
	void		*imag_wall;
	void		*imag_coin[8];
	void		*imag_floor;
	void		*imag_exit[9];
	void		*imag_pack;
	int			img_w;
	int			img_h;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			collected_coins;
	int			total_coins;
	int			player_coins;
	t_maps		*t_map;
	t_player	*t_plyer;
	int			moves;
	int			timer_player;
	int			animation_frame;
	int			coin_frame;
	int			counter_coins;
	int			clos_win;
}	t_window;

typedef struct s_check_hase_characters
{
	int	has_player;
	int	hase_exit;
	int	collectible;
	int	x;
	int	y;
}	t_check_hase_charc;

void	initi_structer_map(t_maps *t_maps);
void	initi_struct_image_plyer(t_player *t_plyer);
void	initi_structer_check_hase_characters(t_check_hase_charc *data_caracter);
void	initi_structer_window(t_window *win, t_maps *t_map);
// chech_file_name
void	check_file_name(char *file_name);
int		check_filename_ber(char *file_name, char *str);
//check maps 5
int		check_valid_maps(char *file, t_maps *t_map);
int		validate_map(t_maps *t_map);
int		check_valid_characters(char **map, int rows, int columns);
int		check_bounderies(char **map, int rows, int columns);
int		is_rectangular(char **map, int rows);

// check map utlis
int		is_sizelimit_maps(int rows, int clomse);
int		calcul_length_of_line(char **map);
int		count_line(int fd);
int		check_if_one_player_exit_collectible(char **map, int length, int rows);
// full maps 
char	**full_map(int fd, int rows);
// chech_flood_fill 3
int		check_if_close_plyer(t_maps *d_map);
void	player_position(t_maps *d_map);
void	flood_fill(t_maps *maps, int x, int y);
// initailization enverament 
void	initialization_enverment(t_window *win, t_maps t_map);
void	push_image_to_window(t_window *win, t_maps t_map);
void	push_imag_exit(t_window *win, int x, int y);
void	push_imag_coin(t_window *win, int x, int y);
// texture loder
int		texture_loader_coins_open_window(t_window *win);
void	texture_loader(t_window *win);
int		texture_loader_exit(t_window *win);
int		texture_loader_exit2(t_window *win);
int		texture_loader_coins(t_window *win);
// texture_loader_plyer2
int		texture_loader_plyer2(t_window *win);
int		texture_loader_plyer(t_window *win);
// free map 
void	ft_free_map(char **map, int rows);
// so_utlis.c
int		calcu_how_many_coins(t_maps *t_map);
// control_key_press
void	chech_if_finsh_game(t_window *window);
void	control_handle_key_press(int keycode, t_window *win);
int		control_key_(int keycode, t_window *window);
// handle_key_press_events
void	check_for_coins_exit(t_window *window);
void	init_key_word(t_window *win, char c);
void	handle_key_press_events(int keycode, t_window *win);
void	handle_key_press_events_not_exit(int keycode, t_window *win);
void	ft_number_of_movements(t_window *win, char c);
//update_player_animation
void	update_player_animation(t_window *window);
void	draw_player(t_window *win);
void	push_floor(t_window *window, int x, int y);
// updat_animatoin_bonus
int		animation_coins(t_window *window);
int		updat_animatoin(t_window *window);
void	update_coin_animation(t_window *win);
void	open_door(t_window *win);
// closw window
int		close_window(t_window *win);

#endif