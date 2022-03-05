/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:00:36 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/05 11:51:58 by kmilchev         ###   ########.fr       */
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

void	rows_columns(int *x, int *y)
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
	printf("Columns: %d, rows: %d\n", *y, *x);
	close(fd);
}

int	handle_keys(int keycode, mlx_shit *mlx_s)
{
	if (keycode == ON_DESTROY)
		printf("Key code: %d\n", keycode);
	else if (keycode == ON_KEYDOWN)
		printf("Key code: %d\n", keycode);
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
