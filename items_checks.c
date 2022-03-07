/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:36:18 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/07 11:38:24 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_tuple	player_position(mlx_shit mlx_s)
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

//Returns 1 if the char is present on the map, 0 if not.
int	item(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	multiple_players(char **map)
{
	int	i;
	int	j;
	int	players;

	i = 0;
	players = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				players++;
				if (players > 1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	only_allowed_chars(char **map)
{
	int		i;
	int		j;
	char	*allowed_chars;

	allowed_chars = "10EPC";
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(allowed_chars, map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_borders(char **map, char *map_path)
{
	int	i;
	int	j;
	int	row;
	int	col;

	number_of_columns_rows(&row, &col, map_path);
	row--;
	col--;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && (i == 0 || i == row || j == 0 || j == col))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
