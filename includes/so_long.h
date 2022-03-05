/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:21:35 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/05 19:00:56 by kmilchev         ###   ########.fr       */
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
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	int		img_width;
	int		img_height;
}			t_pics;

typedef struct t_tuple
{
	int row;
	int column;
}			t_tuple;

typedef struct mlx_shit
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	t_pics	images;
	char	**map;
	t_tuple coordinates;
}			mlx_shit;

typedef struct t_indeces
{
	int		fd;
	int		x;
	int		y;
}			t_indeces;


enum {
	ON_KEYDOWN = 125,
	ON_KEYUP = 126,
	ON_KEYLEFT = 123,
	ON_KEYRIGHT = 124,
	// ON_MOUSEDOWN = 4,
	// ON_MOUSEUP = 5,
	// ON_MOUSEMOVE = 6,
	// ON_EXPOSE = 12,
	ON_DESTROY = 53,
};


void	ft_putstr_fd(char *s, int fd);
void	number_of_columns_rows(int *x, int *y);
void	images_to_screen(mlx_shit *m, t_pics *images);
t_pics	load_images(mlx_shit *mlx_s);
void	window_dimensions(mlx_shit *mlx_s);
int		handle_keys(int keycode, mlx_shit *mlx_s);
char	**string_to_matrix();
void	free_all(char **map);
void	render_map(mlx_shit *mlx_s);

/////MATRIX
t_tuple player_position(mlx_shit mlx_s);
void change_map(mlx_shit *mlx_s, int row, int col);
int collectibles(char **map);

//////ON CLICK
int	on_destroy(int key, mlx_shit *mlx_s);
#endif 
