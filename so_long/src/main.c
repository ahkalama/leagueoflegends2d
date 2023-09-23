/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:37:00 by ahkalama          #+#    #+#             */
/*   Updated: 2023/02/18 14:37:03 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	map_control(argv, &data); // map control yapılıyor
	size_control(&data); // size control yapılıyor
	mlx_create(&data); // mlx create yapılıyor basit ez
}
