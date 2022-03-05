/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_click.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:41:16 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/05 16:41:24 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void on_destroy(mlx_shit *mlx_s)
{
	// mlx_destroy_window(mlx_s->mlx, mlx_s->window);
	free_all(mlx_s->map);
	exit(1);
}

void game_over(mlx_shit *mlx_s)
{
	char *string = "Game over";
	mlx_s->map[mlx_s->coordinates.row][mlx_s->coordinates.column] = '0';
	
	render_map(mlx_s);
	free_all(mlx_s->map);
	mlx_string_put(mlx_s->mlx, mlx_s->window, 20, 20, 0x44FF0022, string);
	
}

void change_map(mlx_shit *mlx_s, int row, int col)
{
	char new_square;
	static char last_square;
	bool was_E = false;
	
	printf("Last %c\n", last_square);
	if (last_square == 'E')
	{
		was_E = true;
	}
	mlx_s->coordinates = player_position(*mlx_s);
	row += mlx_s->coordinates.row;
	col += mlx_s->coordinates.column;
	new_square = mlx_s->map[row][col];
	if (new_square == '1')
		return ;
	
	if (new_square == 'E' && !(collectibles(mlx_s->map)))
	{
		mlx_s->map[row][col] = 'P';
		game_over(mlx_s);
		return ;
	}  
	last_square = mlx_s->map[row][col];
	mlx_s->map[row][col] = 'P';
	if (was_E == false)
		mlx_s->map[mlx_s->coordinates.row][mlx_s->coordinates.column] = '0';
	else
	{
		mlx_s->map[mlx_s->coordinates.row][mlx_s->coordinates.column] = 'E';
		was_E = false;
	}
	render_map(mlx_s);

}


//printf("Row: %d, column %d\n", mlx_s->coordinates.row, mlx_s->coordinates.column);