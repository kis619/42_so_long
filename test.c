/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:00:36 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/05 15:12:51 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	window_dimensions(mlx_shit *mlx_s)
{
	mlx_s->height *= mlx_s->images.img_height;
	mlx_s->width *= mlx_s->images.img_width;
	// printf("Img height: %d\nImg width: %d\n", mlx_s->images.img_height, mlx_s->images.img_width);
	mlx_s->window = mlx_new_window(mlx_s->mlx, mlx_s->width,
			mlx_s->height, "Strangers");
}

void	number_of_columns_rows(int *rows, int *columns)
{
	char	*line;
	int		fd;
	int		num;

	fd = open("map_good.ber", O_RDONLY);
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
	if (keycode == ON_DESTROY)
		on_destroy(mlx_s);
	else if (keycode == ON_KEYDOWN)
	{
		change_map(mlx_s, 1, 0);
			// check_borders();
	}
	else if (keycode == ON_KEYUP)
	{
		change_map(mlx_s, -1, 0);
	}
	else if (keycode == ON_KEYLEFT)
	{
		change_map(mlx_s, 0, -1);
	}
	else if (keycode == ON_KEYRIGHT)
	{
		change_map(mlx_s, 0, 1);
	}
	else
		printf("Key code: %d\n", keycode);
	return (0);
}

char	**string_to_matrix()
{
	int		rows;
	int		columns;
	char	**map;
	int		fd;
	int 	i = 0;

	fd = open("map_good.ber", O_RDONLY);
	number_of_columns_rows(&rows, &columns);
	map = malloc(sizeof(char *) * rows + 1);
	while(i < rows)
	{
		map[i] = malloc(sizeof(char) * columns + 1);
		read(fd, map[i], columns + 1);
		map[i][columns] = '\0';
		i++;
	}

	map[i] = NULL;
	printf("Row 16= %s\n", map[i]);
	return (map);
}

// int *player_position()