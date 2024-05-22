/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:58:50 by asaux             #+#    #+#             */
/*   Updated: 2024/05/22 15:12:14 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.collectible);
	mlx_destroy_image(data->mlx, data->img.enemy_f1);
	mlx_destroy_image(data->mlx, data->img.enemy_f2);
	mlx_destroy_image(data->mlx, data->img.exit_closed);
	mlx_destroy_image(data->mlx, data->img.exit_opened);
	mlx_destroy_image(data->mlx, data->img.ground);
	mlx_destroy_image(data->mlx, data->img.p_back_f1);
	mlx_destroy_image(data->mlx, data->img.p_back_f2);
	mlx_destroy_image(data->mlx, data->img.p_face_f1);
	mlx_destroy_image(data->mlx, data->img.p_face_f2);
	mlx_destroy_image(data->mlx, data->img.p_left_f1);
	mlx_destroy_image(data->mlx, data->img.p_left_f2);
	mlx_destroy_image(data->mlx, data->img.p_right_f1);
	mlx_destroy_image(data->mlx, data->img.p_right_f2);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.win);
	mlx_destroy_image(data->mlx, data->img.loose);
	mlx_destroy_image(data->mlx, data->img.p_back_f1_p);
	mlx_destroy_image(data->mlx, data->img.p_back_f2_p);
	mlx_destroy_image(data->mlx, data->img.p_face_f1_p);
	mlx_destroy_image(data->mlx, data->img.p_face_f2_p);
	mlx_destroy_image(data->mlx, data->img.p_left_f1_p);
	mlx_destroy_image(data->mlx, data->img.p_left_f2_p);
	mlx_destroy_image(data->mlx, data->img.p_right_f1_p);
	mlx_destroy_image(data->mlx, data->img.p_right_f2_p);
}

void	display_black_rectangle(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < 18)
	{
		x = 0;
		while (x < 120)
		{
			mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0);
			x++;
		}
		y++;
	}
}

void	display_moves(t_data *data)
{
	char	*moves;

	moves = ft_itoa(data->nb_moves);
	mlx_string_put(data->mlx, data->mlx_win, 20, 12, 0xFFFFFF, "MOVES :");
	mlx_string_put(data->mlx, data->mlx_win, 80, 12, 0xFFFFFF, moves);
	free(moves);
}

int	close_window(t_data *data)
{
	quit_game(data);
	exit(0);
}

int	handle_events(int keycode, t_data *data)
{
	if (keycode == 65307)
		quit_game(data);
	if (keycode == 65362 || keycode == 119)
		move_up(data);
	if (keycode == 65364 || keycode == 115)
		move_down(data);
	if (keycode == 65361 || keycode == 97)
		move_left(data);
	if (keycode == 65363 || keycode == 100)
		move_right(data);
	display_black_rectangle(data);
	display_moves(data);
	if (data->map_data.m_pos.x == data->map_data.p_pos.x
		&& data->map_data.m_pos.y == data->map_data.p_pos.y)
		game_loose(data);
	if (data->map_data.c_collected == data->map_data.c_count
		&& data->map_data.e_pos.x == data->map_data.p_pos.x
		&& data->map_data.e_pos.y == data->map_data.p_pos.y)
		game_succes(data);
	else if (data->map_data.c_collected == data->map_data.c_count)
		display_img(data, data->img.exit_opened, data->map_data.e_pos.y,
			data->map_data.e_pos.x);
	return (0);
}
