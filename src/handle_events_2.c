/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:09:36 by asaux             #+#    #+#             */
/*   Updated: 2024/04/29 14:16:26 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_succes(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.exit_opened,
		data->map_data.p_pos.y * SIZE,
		data->map_data.p_pos.x * SIZE);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.win,
		(data->map_data.width / 8), (data->map_data.height / 8));
	mlx_do_sync(data->mlx);
	usleep(8000000);
	quit_game(data);
}

void	game_loose(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.loose,
		(data->map_data.width / 8), (data->map_data.height / 8));
	mlx_do_sync(data->mlx);
	usleep(8000000);
	quit_game(data);
}

void	move_enemy(t_data *data)
{
	static int	flag;

	if (flag != 0 && flag != 1)
		flag = 0;
	if (flag == 0)
	{
		move_enemy_1(data, data->map_data.m_pos.x, data->map_data.m_pos.y);
		flag = 1;
	}
	else if (flag == 1)
	{
		move_enemy_2(data, data->map_data.m_pos.x, data->map_data.m_pos.y);
		flag = 0;
	}
}

void	move_enemy_1(t_data *data, int x, int y)
{
	if (data->nb_moves % 3 == 0)
	{
		if (data->map_data.map[x][y + 1] == '0')
			enemy_right_1(data, x, y);	
		else if (data->map_data.map[x + 1][y] == '0')
			enemy_down_1(data, x, y);
		else if (data->map_data.map[x][y - 1] == '0')
			enemy_left_1(data, x, y);
		else if (data->map_data.map[x - 1][y] == '0')
			enemy_up_1(data, x, y);
	}
	else if (data->nb_moves % 1 == 0)
	{
		if (data->map_data.map[x][y - 1] == '0')
			enemy_left_1(data, x, y);
		else if (data->map_data.map[x - 1][y] == '0')
			enemy_up_1(data, x, y);
		else if (data->map_data.map[x][y + 1] == '0')
			enemy_right_1(data, x, y);	
		else if (data->map_data.map[x + 1][y] == '0')
			enemy_down_1(data, x, y);
	}
}

void	move_enemy_2(t_data *data, int x, int y)
{
	if (data->nb_moves % 5 == 0)
	{
		if (data->map_data.map[x][y + 1] == '0')
			enemy_right_2(data, x, y);	
		else if (data->map_data.map[x + 1][y] == '0')
			enemy_down_2(data, x, y);
		else if (data->map_data.map[x][y - 1] == '0')
			enemy_left_2(data, x, y);
		else if (data->map_data.map[x - 1][y] == '0')
			enemy_up_2(data, x, y);
	}
	else if (data->nb_moves % 1 == 0)
	{
		if (data->map_data.map[x - 1][y] == '0')
			enemy_up_2(data, x, y);
		else if (data->map_data.map[x][y - 1] == '0')
			enemy_left_2(data, x, y);
		else if (data->map_data.map[x][y + 1] == '0')
			enemy_right_2(data, x, y);	
		else if (data->map_data.map[x + 1][y] == '0')
			enemy_down_2(data, x, y);
	}
}
