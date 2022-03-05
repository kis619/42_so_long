/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:00:36 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/05 13:16:13 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	window_dimensions(mlx_shit *mlx_s, t_pics *images)
{
	mlx_s->height *= images->img_height;
	mlx_s->width *= images->img_width;
	mlx_s->window = mlx_new_window(mlx_s->mlx, mlx_s->width,
			mlx_s->height, "Strangers");
	mlx_s->images = *images;
}

void	number_of_columns_rows(int *x, int *y)
{
	char	*line;
	int		fd;
	int		num;

	fd = open("map_good.ber", O_RDONLY);
	line = get_next_line(fd);
	*y = (int)ft_strlen(line) - 1;
	*x = 0;
	while (line)
	{
		if (*x == 0)
			free(line);
		line = get_next_line(fd);
		free(line);
		(*x)++;
	}
	close(fd);
}

int	handle_keys(int keycode, mlx_shit *mlx_s)
{
	if (keycode == ON_DESTROY)
		on_destroy(mlx_s);
	else if (keycode == ON_KEYDOWN)
	{
		// check_borders();
		// change_map();
		// new_render_map();
		printf("Key code: %d\n", keycode);
	}
	else if (keycode == ON_KEYUP)
		printf("Key code: %d\n", keycode);
	else if (keycode == ON_KEYLEFT)
		printf("Key code: %d\n", keycode);
	else if (keycode == ON_KEYRIGHT)
		printf("Key code: %d\n", keycode);
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
	printf("Columns: %d, rows: %d\n", columns, rows);

	map = malloc(sizeof(char *) * rows + 1);
	while(i < rows)
	{
		map[i] = malloc(sizeof(char) * columns + 1);
		read(fd, map[i], columns + 1);
		map[i][columns] = '\0';
		i++;
	}

	map[i] = NULL;
	// printf("Row 1, column 2 = %c\n", map[4][4]);
	return (map);
}