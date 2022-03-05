/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:36:18 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/05 15:40:09 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_tuple player_position(mlx_shit mlx_s)
{
	int i;
	int j;
	bool found_p;
	t_tuple coordinates;

	i = 0;
	found_p = false;

	while (mlx_s.map[i])
	{
		j = 0;
		while (mlx_s.map[i][j])
		{
			if (mlx_s.map[i][j] == 'P')
			{
				found_p = true;
				break;
			}
			j++;
		}
		if (found_p)
			break;
		i++;
	}
	coordinates.row = i;
	coordinates.column = j;
	return (coordinates);
}

int collectibles(char **map)
{
	int i;
	int j;

	i = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}