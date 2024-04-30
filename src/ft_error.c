/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:31:49 by asaux             #+#    #+#             */
/*   Updated: 2024/04/29 12:33:34 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(int flag)
{
	errno = 1;
	if (flag == 0)
		perror("Invalid arguments");
	if (flag == 1)
		perror("Wrong extension, only .ber extension");
	if (flag == 2)
		perror("Error\nFile can't be opened");
	if (flag == 3)
		perror("Error\nMap file is empty");
	exit (1);
}

void	ft_error_data(t_data *data, int flag)
{
	errno = 1;
	if (flag == 0)
	{
		perror("Error\nMap Must be a rectangle");
		free_array(data->map_data.map);
	}
	if (flag == 1)
	{
		perror("Error\nWrong char in map");
		free_array(data->map_data.map);
	}
	if (flag == 2)
	{
		perror("Error\nOne collectible is required");
		free_array(data->map_data.map);
	}
	if (flag == 3)
	{
		perror("Error\nOnly one player is accepted");
		free_array(data->map_data.map);
	}
	exit (1);
}

void	ft_error_data_2(t_data *data, int flag)
{
	errno = 1;
	if (flag == 0)
	{
		perror("Error\nOnly one exit is accepted");
		free_array(data->map_data.map);
	}
	if (flag == 1)
	{
		perror("Error\nExit and all collectibles must be reachable in the map");
		free_array(data->map_data.map);
	}
	if (flag == 2)
	{
		perror("Error\nOne monster maximum in the map");
		free_array(data->map_data.map);
	}
	exit (1);
}
