/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:01:10 by asaux             #+#    #+#             */
/*   Updated: 2024/05/14 13:33:14 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <errno.h>

# define SIZE 64

typedef struct s_img{
	int				size;
	void			*collectible;
	void			*enemy_f1;
	void			*enemy_f2;
	void			*exit_closed;
	void			*exit_opened;
	void			*ground;
	void			*p_back_f1;
	void			*p_back_f2;
	void			*p_face_f1;
	void			*p_face_f2;
	void			*p_left_f1;
	void			*p_left_f2;
	void			*p_right_f1;
	void			*p_right_f2;
	void			*wall;
	void			*win;
	void			*loose;
	void			*p_back_f1_p;
	void			*p_back_f2_p;
	void			*p_face_f1_p;
	void			*p_face_f2_p;
	void			*p_left_f1_p;
	void			*p_left_f2_p;
	void			*p_right_f1_p;
	void			*p_right_f2_p;
}	t_img;

typedef struct s_pos{
	int				x;
	int				y;
}	t_pos;

typedef struct s_map_data{
	char			**map;
	unsigned int	nb_column;
	unsigned int	nb_row;
	int				c_count;
	int				e_count;
	int				p_count;
	int				m_count;
	int				c_collected;
	int				width;
	int				height;
	t_pos			p_pos;
	t_pos			e_pos;
	t_pos			m_pos;
}	t_map_data;

typedef struct s_data{
	void			*mlx;
	void			*mlx_win;
	int				nb_moves;
	t_map_data		map_data;
	t_img			img;
}		t_data;

//so_long.c
int		main(int ac, char **av);
int		check_exten(char *av);
int		check_path(char **map);
void	is_map_rectangle(t_data *data);

//ft_error.c
void	ft_error(int flag);
void	ft_error_data(t_data *data, int flag);
void	ft_error_data_2(t_data *data, int flag);

//parsing_1.c
void	map_parsing(char **av, t_data *data);
char	**read_map(char **av);
void	check_walls_and_char(t_data *data);
void	check_char(char c, t_data *data);
void	check_counts(t_data *data);

//parsing_2.c
void	is_path_valid(char **av, t_data *data);
void	flood_map(char **map, t_pos pos);
void	init_map_data(t_data *data);
void	init_player_exit_pos(t_data *data);
void	set_pos(t_data *data, int x, int y);

//get_next_line.c
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);

//free.c
void	free_array(char **array);
void	quit_game(t_data *data);

//display_map.c
void	display_map(t_data *data);
void	put_img_to_map(t_data *data);
void	display_img(t_data *data, void *img, int y, int x);
void	set_img(t_data *data);
void	*convert_img(t_data *data, char *path);

//handle_events_1.c
int		handle_events(int keycode, t_data *data);
void	destroy_img(t_data *data);
int		close_window(t_data *data);
void	display_moves(t_data *data);
void	display_black_rectangle(t_data *data);

//handle_events_2.c
void	move_enemy(t_data *data);
void	move_enemy_1(t_data *data, int x, int y);
void	move_enemy_2(t_data *data, int x, int y);
void	game_succes(t_data *data);
void	game_loose(t_data *data);

//move_right.c
void	move_right(t_data *data);
void	move_right_1(t_data *data, int x, int y);
void	move_right_2(t_data *data, int x, int y);
void	enemy_right_1(t_data *data, int x, int y);
void	enemy_right_2(t_data *data, int x, int y);

//move_down.c
void	move_down(t_data *data);
void	move_down_1(t_data *data, int x, int y);
void	move_down_2(t_data *data, int x, int y);
void	enemy_down_1(t_data *data, int x, int y);
void	enemy_down_2(t_data *data, int x, int y);

//move_left.c
void	move_left(t_data *data);
void	move_left_1(t_data *data, int x, int y);
void	move_left_2(t_data *data, int x, int y);
void	enemy_left_1(t_data *data, int x, int y);
void	enemy_left_2(t_data *data, int x, int y);

//move_up.c
void	move_up(t_data *data);
void	move_up_1(t_data *data, int x, int y);
void	move_up_2(t_data *data, int x, int y);
void	enemy_up_1(t_data *data, int x, int y);
void	enemy_up_2(t_data *data, int x, int y);

#endif