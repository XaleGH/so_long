/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:54:26 by asaux             #+#    #+#             */
/*   Updated: 2024/04/29 12:36:07 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_char(char c, t_data *data)
{
	if (c != '0' && c != '1' && c != 'P' && c != 'C' && c != 'E' && c != 'M')
		ft_error_data(data, 1);
	if (c == 'P')
		data->map_data.p_count += 1;
	if (c == 'C')
		data->map_data.c_count += 1;
	if (c == 'E')
		data->map_data.e_count += 1;
	if (c == 'M')
		data->map_data.m_count += 1;
}

void	check_counts(t_data *data)
{
	if (data->map_data.c_count < 1)
		ft_error_data(data, 2);
	if (data->map_data.p_count != 1)
		ft_error_data(data, 3);
	if (data->map_data.e_count != 1)
		ft_error_data_2(data, 0);
	if (data->map_data.m_count > 1)
		ft_error_data_2(data, 2);
}

void	check_walls_and_char(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map_data.map[x])
	{
		y = 0;
		while (data->map_data.map[x][y])
		{
			check_char(data->map_data.map[x][y], data);
			if (data->map_data.map[0][y] != '1')
				ft_error_data(data, 1);
			if (data->map_data.map[data->map_data.nb_row - 1][y] != '1')
				ft_error_data(data, 1);
			if (data->map_data.map[x][0] != '1')
				ft_error_data(data, 1);
			if (data->map_data.map[x][data->map_data.nb_column - 1] != '1')
				ft_error_data(data, 1);
			y++;
		}
		x++;
	}
	check_counts(data);
	
}

char	**read_map(char **av)
{
	char	**map;
	char	*line;
	char	*map_line;
	int		map_file;
	
	map_file = open(av[1], O_RDONLY);
	if (!map_file)
		ft_error(2);
	line = get_next_line(map_file);
	if (!line)
		ft_error(3);
	map_line = ft_strdup("");
	while (1)
	{
		map_line = ft_strjoin_gnl(map_line, line);
		free(line);
		line = get_next_line(map_file);
		if (!line)
			break;
	}
	free(line);
	map = ft_split(map_line, '\n');
	close(map_file);
	free(map_line);
	return (map);
}

void	map_parsing(char **av, t_data *data)
{
	init_map_data(data);
	data->map_data.map = read_map(av);
	is_map_rectangle(data);
	check_walls_and_char(data);
	is_path_valid(av, data);
}
