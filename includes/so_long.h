/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:21:35 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/07 13:11:43 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <get_next_line.h>
#include <stdbool.h>

typedef	struct pics
{
	void	*wall;
	void	*floor;
	void	*coll;
	void	*door;
	void	*player;
	int		img_width;
	int		img_height;
}			t_pics;

typedef struct t_tuple
{
	int row;
	int col;
}			t_tuple;

typedef struct t_mlx
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	t_pics	images;
	char	**map;
	t_tuple coordinates;
	int		row;
	int		col;
}			t_mlx;

typedef struct file_read
{
	char	*line;
	int		fd;
}			t_file_read;

typedef struct map
{
	char	new_square;
	char	last_square;
} t_map;

typedef struct bullshit
{
	int		rows;
	int		columns;
	char	**map;
	int		fd;
	int		i;
}	t_data;

enum {
	DOWN = 125,
	UP = 126,
	LEFT = 123,
	RIGHT = 124,
	ESC = 53,
	W = 13,
	S = 1,
	A = 0,
	D = 2,
	X_CLOSE = 17,
};


void	ft_putstr_fd(char *s, int fd);
void	number_of_columns_rows(int *x, int *y, char *map);
t_pics	load_images(t_mlx *mlx_s);
void	window_dimensions(t_mlx *mlx_s);
int		handle_keys(int keycode, t_mlx *mlx_s);
char	**string_to_matrix(char *map);
void	free_all(char **map);
void	render_map(t_mlx *mlx_s);
char	*ft_strrchr(const char *s, int c);
int valid_borders(char **map, char *map_path);
/////MATRIX
t_tuple player_position(t_mlx mlx_s);
void change_map(t_mlx *mlx_s, int row, int col);
int item(char **map, char c);

//////ON CLICK
int	on_destroy(int key, t_mlx *mlx_s);

////VALIDATIONS
char *map_is_valid(t_mlx *mlx_s, char *map_path);
int	is_ber_file(char *map);
int	checks(int argc, char *argv[], t_mlx *mlx_s);
int multiple_players(char **map);
int only_allowed_chars(char **map);

int	x_close(void);

void render_map_with_moves_count (t_mlx *mlx_s);

void	set_coordinates(t_mlx *mlx_s, int *row, int *col, t_map	*map);

////////VALIDATIONS
int	map_is_rectangular(char *map_path);
int	file_exists(char *map_path);
// static int	ft_count_positions(int n);
// static void	ft_add_to_list(char *lst_chars, unsigned int number, int count);
char	*ft_itoa(int n);
#endif 
