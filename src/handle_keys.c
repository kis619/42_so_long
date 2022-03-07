/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:00:36 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/07 13:20:31 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	handle_keys(int keycode, t_mlx *mlx_s)
{
	if (keycode == ESC)
		on_destroy(0, mlx_s);
	else if (keycode == DOWN || keycode == S)
		change_map(mlx_s, 1, 0);
	else if (keycode == UP || keycode == W)
		change_map(mlx_s, -1, 0);
	else if (keycode == LEFT || keycode == A)
		change_map(mlx_s, 0, -1);
	else if (keycode == RIGHT || keycode == D)
		change_map(mlx_s, 0, 1);
	return (0);
}

int	on_destroy(int keycode, t_mlx *mlx_s)
{
	if (!keycode)
		return (0);
	mlx_destroy_window(mlx_s->mlx, mlx_s->window);
	free_all(mlx_s->map);
	exit(EXIT_SUCCESS);
}

int	x_close(void)
{
	exit(EXIT_SUCCESS);
}

t_tuple	player_position(t_mlx mlx_s)
{
	t_tuple	idx;
	bool	found_p;
	t_tuple	coordinates;

	idx.row = 0;
	found_p = false;
	while (mlx_s.map[idx.row])
	{
		idx.col = 0;
		while (mlx_s.map[idx.row][idx.col])
		{
			if (mlx_s.map[idx.row][idx.col] == 'P')
			{
				found_p = true;
				break ;
			}
			idx.col++;
		}
		if (found_p)
			break ;
		idx.row++;
	}
	coordinates.row = idx.row;
	coordinates.col = idx.col;
	return (coordinates);
}
