/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:05:15 by asaux             #+#    #+#             */
/*   Updated: 2024/04/29 12:35:42 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_exten(char *av)
{
	int		i;
	int		j;
	char	*ext;
	
	ext = ".ber";
	i = ft_strlen(av) - 1;
	j = 3;
	while (av[i] != '.')
	{
		if (av[i] != ext[j])
			ft_error(1);
		i--;
		j--;
	}
	return (0);
}

void	is_map_rectangle(t_data *data)
{
	int	x;
	
	x = 0;
	data->map_data.nb_column = ft_strlen(data->map_data.map[x]);
	while (data->map_data.map[x])
	{
		if (ft_strlen(data->map_data.map[x]) != data->map_data.nb_column)
			ft_error_data(data, 0);
		x++;
	}
	data->map_data.nb_row = x;
	if (data->map_data.nb_column == data->map_data.nb_row)
		ft_error_data(data, 0);
}

int	check_path(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C' || map[x][y] == 'E')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	
	if (ac != 2)
		ft_error(0);
	check_exten(av[1]);
	map_parsing(av, &data);
	display_map(&data);
	mlx_key_hook(data.mlx_win, handle_events, &data);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
}
