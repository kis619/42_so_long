/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:41:16 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/07 14:08:38 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	game_over(t_mlx *mlx_s)
{	
	mlx_s->map[mlx_s->coordinates.row][mlx_s->coordinates.col] = '0';
	render_map(mlx_s);
	mlx_string_put(mlx_s->mlx, mlx_s->window, 20, 20, 0x44FF0022, "Game over");
	mlx_string_put(mlx_s->mlx, mlx_s->window, 20, 40,
		0x44FF0022, "Press any key to exit");
	mlx_key_hook(mlx_s->window, on_destroy, mlx_s);
}

void	change_map(t_mlx *mlx_s, int row, int col, char new_square)
{
	static char	last_square;
	static bool	was_e = false;

	if (last_square == 'E')
		was_e = true;
	set_coordinates(mlx_s, &row, &col);
	new_square = mlx_s->map[row][col];
	if (new_square == '1')
		return ;
	if (new_square == 'E' && !(item(mlx_s->map, 'C')))
	{
		mlx_s->map[row][col] = 'P';
		game_over(mlx_s);
		return ;
	}
	last_square = mlx_s->map[row][col];
	mlx_s->map[row][col] = 'P';
	if (was_e == false)
		mlx_s->map[mlx_s->coordinates.row][mlx_s->coordinates.col] = '0';
	else
	{
		mlx_s->map[mlx_s->coordinates.row][mlx_s->coordinates.col] = 'E';
		was_e = false;
	}
	render_map_with_moves_count(mlx_s);
}

void	set_coordinates(t_mlx *mlx_s, int *row, int *col)
{
	mlx_s->coordinates = player_position(*mlx_s);
	*row += mlx_s->coordinates.row;
	*col += mlx_s->coordinates.col;
}

void	render_map_with_moves_count(t_mlx *mlx_s)
{
	static int	moves = 0;

	moves++;
	render_map(mlx_s);
	mlx_string_put(mlx_s->mlx, mlx_s->window, 20, 20,
		0x44FF0022, ft_itoa(moves));
}

void	window_dimensions(t_mlx *mlx_s)
{
	mlx_s->height *= mlx_s->images.img_height;
	mlx_s->width *= mlx_s->images.img_width;
	mlx_s->window = mlx_new_window(mlx_s->mlx, mlx_s->width,
			mlx_s->height, "Strangers");
}
