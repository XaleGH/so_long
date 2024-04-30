/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:03:44 by asaux             #+#    #+#             */
/*   Updated: 2024/04/29 12:32:33 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map_data(t_data *data)
{
	data->map_data.nb_column = 0;
	data->map_data.nb_row = 0;
	data->map_data.c_count = 0;
	data->map_data.e_count = 0;
	data->map_data.p_count = 0;
	data->map_data.m_count = 0;
	data->map_data.c_collected = 0;
	data->map_data.width = 0;
	data->map_data.height = 0;
	data->nb_moves = 0;
}

void	set_pos(t_data *data, int x, int y)
{
	if (data->map_data.map[x][y] == 'P')
	{
		data->map_data.p_pos.x = x;
		data->map_data.p_pos.y = y;
	}
	if (data->map_data.map[x][y] == 'E')
	{
		data->map_data.e_pos.x = x;
		data->map_data.e_pos.y = y;
	}
	if (data->map_data.map[x][y] == 'M')
	{
		data->map_data.m_pos.x = x;
		data->map_data.m_pos.y = y;
	}
}

void	init_player_exit_pos(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map_data.map[x])
	{
		y = 0;
		while (data->map_data.map[x][y])
		{
			set_pos(data, x, y);
			y++;
		}
		x++;
	}
}

void	flood_map(char **map, t_pos pos)
{
	if (map[pos.x][pos.y] == '1' || map[pos.x][pos.y] == 'F')
		return;
	map[pos.x][pos.y] = 'F';
	flood_map(map, (t_pos){pos.x, pos.y + 1});
	flood_map(map, (t_pos){pos.x, pos.y - 1});
	flood_map(map, (t_pos){pos.x + 1, pos.y});
	flood_map(map, (t_pos){pos.x - 1, pos.y});
}

void	is_path_valid(char **av, t_data *data)
{
	char	**new_map;
	t_pos	pos;

	init_player_exit_pos(data);
	new_map = read_map(av);
	pos = data->map_data.p_pos;
	flood_map(new_map, pos);
	if (!check_path(new_map))
	{
		free_array(new_map);
		ft_error_data_2(data, 1);
	}
	free_array(new_map);
}