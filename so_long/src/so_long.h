/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:36:40 by ahkalama          #+#    #+#             */
/*   Updated: 2023/02/18 14:54:20 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define IMG_SIZE 100

typedef struct l_image
{
	char	*character;
	char	*wall;
	char	*coin;
	char	*door;
	char	*bg;
	int		img_w;
	int		img_h;
}			t_image;

typedef struct l_int_map
{
	int		read_count;
	int		step_count;
}			t_int_map;

typedef struct l_data
{
	char		**map;
	char		*mlx;
	char		*win;
	char		*map_tmp;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	int			player_count;
	int			exit_count;
	int			exit_x;
	int			exit_y;
	int			wall_count;
	int			coin_count;
	int			unwanted_character_count;
	int			coin_collected;
	int			step_count;
	t_image		img;
	t_int_map	i_map;
}				t_data;

void		mlx_create(t_data *data);
void		map_control(char **argv, t_data *data);
void		ber_control(char *map_name, t_data *data);
void		tmp_control(char *map_name, t_data *data);
void		map_read(t_data *data);
void		map_create(t_data *data);
void		size_control(t_data *data);
void		*myfree(void *str);
char		*get_next_line(int fd);
void		err_msg(char *msg);
void		hook(t_data *data);
int			key_hook(int keycode, t_data *data);
int			mouse_hook(int mousecode, t_data *data);
void		exit_door(t_data *data);
void		map_bacgraund_put(t_data *data);
void		map_put(int i, int j, t_data *data);
void		min_element_control(t_data *data);
void		placeholder(t_data *list, int x, int y,
				int map_finder_print_is_active);
void		wall_control(t_data *data);

#endif