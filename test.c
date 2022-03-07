/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:00:36 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/07 12:01:54 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	window_dimensions(mlx_shit *mlx_s)
{
	mlx_s->height *= mlx_s->images.img_height;
	mlx_s->width *= mlx_s->images.img_width;
	mlx_s->window = mlx_new_window(mlx_s->mlx, mlx_s->width,
			mlx_s->height, "Strangers");
}

void	number_of_columns_rows(int *rows, int *columns, char* map_path)
{
	char	*line;
	int		fd;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	*columns = (int)ft_strlen(line) - 1;
	*rows = 0;
	while (line)
	{
		if (*rows == 0)
			free(line);
		line = get_next_line(fd);
		free(line);
		(*rows)++;
	}
	close(fd);
}

int	handle_keys(int keycode, mlx_shit *mlx_s)
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

char	**string_to_matrix(char *map_path)
{
	int		rows;
	int		columns;
	char	**map;
	int		fd;
	int 	i = 0;

	fd = open(map_path, O_RDONLY);
	number_of_columns_rows(&rows, &columns, map_path);
	map = malloc(sizeof(char *) * rows + 1);
	if (!map)
		exit(EXIT_FAILURE);
	while(i < rows)
	{
		map[i] = malloc(sizeof(char) * columns + 1);
		if (!map[i])
		{
			free(map[i]);
			return (0);
		}
		read(fd, map[i], columns + 1);
		map[i][columns] = '\0';
		i++;
	}

	map[i] = NULL;
	return (map);
}
