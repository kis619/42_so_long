/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:36:18 by kmilchev          #+#    #+#             */
/*   Updated: 2022/04/03 18:17:00 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

//Returns a string with an error message if the item is not present on the map,
//0 if everything is fine
int free_and_return(t_mlx *mlx_all, char *message)
{
	free_all(mlx_all->map);
	return(message);
}

char	*map_is_valid(t_mlx *mlx_s, char *map_path)
{
	if (!map_is_rectangular(map_path))
		return ("Error\nMap is not rectangular.\n");
	mlx_s->map = string_to_matrix(map_path);
	if (!only_allowed_chars(mlx_s->map))
	free_and_return(mlx_s, "Error\nThe map contains forbidden characters.\n");
	if (!valid_borders(mlx_s->map, map_path))
	free_and_return(mlx_s, "Error\nThe map is not enclosed by borders.\n");
	if (!item(mlx_s->map, 'C'))
	free_and_return(mlx_s, "Error\nThere are no collectibles on the map.\n");
	if (!item(mlx_s->map, 'P'))
	free_and_return(mlx_s, "Error\nThere is no player on the map.\n");
	if (!item(mlx_s->map, 'E'))
	free_and_return(mlx_s, "Error\nThere is no exit on the map.\n");
	if (multiple_players(mlx_s->map))
	free_and_return(mlx_s, "Error\nThere is more than 1 player on the map.\n");
	free_all(mlx_s->map);
	return (0);
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
