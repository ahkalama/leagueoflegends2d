/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:36:26 by ahkalama          #+#    #+#             */
/*   Updated: 2023/02/18 15:05:48 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_control(t_data *data)
{
	int		fd;
	char	*line;
	int		y;
	int		x;

	y = 0;
	fd = open(data->map_tmp, O_RDONLY);
	line = get_next_line(fd);
	x = ft_strlen(line);
	while (1)
	{
		free(line);
		y++;
		line = get_next_line(fd);
		if (line[0] == '\0')
			break ;
		if (x != (int)ft_strlen(line) && line[0] != '\0')
			err_msg("Error : Harita Esit Degil");
	}
	if (!line)
		free(line);
	data->map_height = y;
	data->map_width = x - 1;
	close (fd);
}

void	wall_control(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map_width)
		if (data->map[0][x++] != '1')
			err_msg("Error : Haritanin etrafi cevrili olmalı");
	while (y < data->map_height)
	{
		if (data->map[y][0] != '1' || data->map[y][data->map_width - 1] != '1')
			err_msg("Error : Haritanin etrafi cevrili degil");
		y++;
	}
	x = 0;
	while (x < data->map_width)
		if (data->map[data->map_height - 1][x++] != '1')
			err_msg("Error : Haritanin etrafi hala cevrili degil");
}

void	min_element_control(t_data *data)
{
	if (data->player_count != 1)
		err_msg("There must be 1 player on the map");
	if (data->exit_count != 1)
		err_msg("There must be 1 exit on the map");
	if (data->coin_count < 1)
		err_msg("Must have at least 1 collectible on the map");
	if (data->wall_count < 12)
		err_msg("Wrong on the map");
	if (data->unwanted_character_count != 0)
		err_msg("The map must contain only [0,1,E,P,C] characters");
}
