/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_click.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:41:16 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/05 15:11:53 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void on_destroy(mlx_shit *mlx_s)
{
	// mlx_destroy_window(mlx_s->mlx, mlx_s->window);
	free_all(mlx_s->map);
	exit(1);
}

// void on_

void change_map(mlx_shit *mlx_s, int row, int col)
{
	// int cur_row;
	// int cur_col;
	// check_borders();
	mlx_s->coordinates = player_position(*mlx_s);
	printf("Row: %d, columns %d\n", mlx_s->coordinates.row, mlx_s->coordinates.column);
	
	row += mlx_s->coordinates.row;
	col += mlx_s->coordinates.column;
	mlx_s->map[row][col] = 'P';
	mlx_s->map[mlx_s->coordinates.row][mlx_s->coordinates.column] = '0';
	
	mlx_s->coordinates = player_position(*mlx_s);
	printf("Row: %d, columns %d\n", mlx_s->coordinates.row, mlx_s->coordinates.column);
	render_map(mlx_s);
}