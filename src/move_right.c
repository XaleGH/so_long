/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:12:47 by asaux             #+#    #+#             */
/*   Updated: 2024/05/14 13:29:37 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_right(t_data *data)
{
	static int	flag;

	if (flag != 0 && flag != 1)
		flag = 0;
	if (flag == 0)
	{
		move_right_1(data, data->map_data.p_pos.x, data->map_data.p_pos.y);
		flag = 1;
	}
	else if (flag == 1)
	{
		move_right_2(data, data->map_data.p_pos.x, data->map_data.p_pos.y);
		flag = 0;
	}
}

void	move_right_1(t_data *data, int x, int y)
{
	if (data->map_data.map[x][y + 1] == '1' && data->map_data.map[x][y] == 'E')
		display_img(data, data->img.p_right_f1_p, y, x);
	else if (data->map_data.map[x][y + 1] == '1')
		display_img(data, data->img.p_right_f1, y, x);
	else
	{
		if (data->map_data.map[x][y + 1] == 'C')
			data->map_data.c_collected += 1;
		if (data->map_data.map[x][y] == 'E')
			display_img(data, data->img.exit_closed, y, x);
		else
		{
			data->map_data.map[x][y] = '0';
			display_img(data, data->img.ground, y, x);
		}
		data->map_data.p_pos.y = y + 1;
		if (data->map_data.map[x][y + 1] == 'E')
			display_img(data, data->img.p_right_f1_p, (y + 1), x);
		else
			display_img(data, data->img.p_right_f1, (y + 1), x);
		data->nb_moves++;
		ft_printf("MOVES : %i\n", data->nb_moves);
		move_enemy(data);
	}
}

void	move_right_2(t_data *data, int x, int y)
{
	if (data->map_data.map[x][y + 1] == '1' && data->map_data.map[x][y] == 'E')
		display_img(data, data->img.p_right_f2_p, y, x);
	else if (data->map_data.map[x][y + 1] == '1')
		display_img(data, data->img.p_right_f2, y, x);
	else
	{
		if (data->map_data.map[x][y + 1] == 'C')
			data->map_data.c_collected += 1;
		if (data->map_data.map[x][y] == 'E')
			display_img(data, data->img.exit_closed, y, x);
		else
		{
			data->map_data.map[x][y] = '0';
			display_img(data, data->img.ground, y, x);
		}
		data->map_data.p_pos.y = y + 1;
		if (data->map_data.map[x][y + 1] == 'E')
			display_img(data, data->img.p_right_f2_p, (y + 1), x);
		else
			display_img(data, data->img.p_right_f2, (y + 1), x);
		data->nb_moves++;
		ft_printf("MOVES : %i\n", data->nb_moves);
		move_enemy(data);
	}
}

void	enemy_right_1(t_data *data, int x, int y)
{
	data->map_data.map[x][y] = '0';
	data->map_data.map[x][y + 1] = 'M';
	display_img(data, data->img.enemy_f1, (y + 1), x);
	display_img(data, data->img.ground, y, x);
	data->map_data.m_pos.y = y + 1;
}

void	enemy_right_2(t_data *data, int x, int y)
{
	data->map_data.map[x][y] = '0';
	data->map_data.map[x][y + 1] = 'M';
	display_img(data, data->img.enemy_f2, (y + 1), x);
	display_img(data, data->img.ground, y, x);
	data->map_data.m_pos.y = y + 1;
}
