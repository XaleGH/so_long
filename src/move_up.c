/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:14:14 by asaux             #+#    #+#             */
/*   Updated: 2024/04/29 14:09:35 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_data *data)
{
	static int	flag;

	if (flag != 0 && flag != 1)
		flag = 0;
	if (flag == 0)
	{
		move_up_1(data, data->map_data.p_pos.x, data->map_data.p_pos.y);
		flag = 1;
	}
	else if (flag == 1)
	{
		move_up_2(data, data->map_data.p_pos.x, data->map_data.p_pos.y);
		flag = 0;
	}
}

void	move_up_1(t_data *data, int x, int y)
{
	if (data->map_data.map[x - 1][y] == '1' && data->map_data.map[x][y] == 'E')
		display_img(data, data->img.p_back_f1_p, y, x);
	else if (data->map_data.map[x - 1][y] == '1')
		display_img(data, data->img.p_back_f1, y, x);
	else
	{
		if (data->map_data.map[x - 1][y] == 'C')
			data->map_data.c_collected += 1;
		if (data->map_data.map[x][y] == 'E')
			display_img(data, data->img.exit_closed, y ,x);
		else
		{
			data->map_data.map[x][y] = '0';
			display_img(data, data->img.ground, y ,x);
		}
		data->map_data.p_pos.x = x - 1;
		if (data->map_data.map[x - 1][y] == 'E')
			display_img(data, data->img.p_back_f1_p, y ,(x - 1));
		else
			display_img(data, data->img.p_back_f1, y ,(x - 1));
		data->nb_moves++;
		ft_printf("MOVES : %i\n", data->nb_moves);
		move_enemy(data);
	}
}

void	move_up_2(t_data *data, int x, int y)
{
	if (data->map_data.map[x - 1][y] == '1' && data->map_data.map[x][y] == 'E')
		display_img(data, data->img.p_back_f2_p, y, x);
	else if (data->map_data.map[x - 1][y] == '1')
		display_img(data, data->img.p_back_f2, y, x);
	else
	{
		if (data->map_data.map[x - 1][y] == 'C')
			data->map_data.c_collected += 1;
		if (data->map_data.map[x][y] == 'E')
			display_img(data, data->img.exit_closed, y ,x);
		else
		{
			data->map_data.map[x][y] = '0';
			display_img(data, data->img.ground, y ,x);
		}
		data->map_data.p_pos.x = x - 1;
		if (data->map_data.map[x - 1][y] == 'E')
			display_img(data, data->img.p_back_f2_p, y ,(x - 1));
		else
			display_img(data, data->img.p_back_f2, y ,(x - 1));
		data->nb_moves++;
		ft_printf("MOVES : %i\n", data->nb_moves);
		move_enemy(data);
	}
}

void	enemy_up_1(t_data *data, int x, int y)
{
	data->map_data.map[x][y] = '0';
	data->map_data.map[x - 1][y] = 'M';
	display_img(data, data->img.enemy_f1, y, (x - 1));
	display_img(data, data->img.ground, y, x);
	data->map_data.m_pos.x = x - 1;
}

void	enemy_up_2(t_data *data, int x, int y)
{
	data->map_data.map[x][y] = '0';
	data->map_data.map[x - 1][y] = 'M';
	display_img(data, data->img.enemy_f2, y, (x - 1));
	display_img(data, data->img.ground, y, x);
	data->map_data.m_pos.x = x - 1;
}
