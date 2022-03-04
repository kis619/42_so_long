/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:00:36 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/04 17:39:18 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <so_long.h>
#include <stdio.h>
#include <unistd.h>
#include <get_next_line.h>

t_pics	load_images(mlx_shit *mlx_s)
{
	t_pics	images;

	images.img1 = mlx_xpm_file_to_image(mlx_s->mlx,
			"images/size_w22_h24/1.xpm", &images.img_width, &images.img_height);
	images.img2 = mlx_xpm_file_to_image(mlx_s->mlx,
			"images/size_w22_h24/2.xpm", &images.img_width, &images.img_height);
	images.img3 = mlx_xpm_file_to_image(mlx_s->mlx,
			"images/size_w22_h24/3.xpm", &images.img_width, &images.img_height);
	images.img4 = mlx_xpm_file_to_image(mlx_s->mlx,
			"images/size_w22_h24/4.xpm", &images.img_width, &images.img_height);
	images.img5 = mlx_xpm_file_to_image(mlx_s->mlx,
			"images/size_w22_h24/5.xpm", &images.img_width, &images.img_height);
	return (images);
}

void	paint_it_red(mlx_shit *mlx_s)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x++ <= mlx_s->width)
	{
		while (y++ <= mlx_s->height)
		{
			mlx_pixel_put(mlx_s->mlx, mlx_s->window, x, y, 0x44FF0022);
		}
		y = 0;
	}
}

void	window_dimensions(mlx_shit *mlx_s, t_pics *images)
{
	mlx_s->height = mlx_s->width_height[1] * images->img_height;
	mlx_s->width = mlx_s->width_height[0] * images->img_width;
	mlx_s->window = mlx_new_window(mlx_s->mlx, mlx_s->width,
			mlx_s->height, "Hello world!");
}

void	images_to_screen(mlx_shit *m, t_pics *images)
{
	t_indeces	idx;
	char		c[1];
	void		*img;

	idx.fd = open("map_good.ber", O_RDONLY);
	idx.y = 0;
	while (images->img_height * idx.y <= m->height)
	{
		idx.x = 0;
		while (images->img_width * idx.x <= m->width)
		{
			read(idx.fd, c, 1);
			if (c[0] == '1')
				img = images->img1;
			else if (c[0] == '0')
				img = images->img2;
			else if (c[0] == 'C')
				img = images->img3;
			else if (c[0] == 'E')
				img = images->img4;
			else if (c[0] == 'P')
				img = images->img5;
			mlx_put_image_to_window(m->mlx, m->window, img,
				images->img_width * idx.x, images->img_height * idx.y);
			idx.x++;
		}
		idx.y++;
	}
}

int	*read_map(void)
{
	char			*line;
	int				fd;
	static int		x_y[2];

	fd = open("map_good.ber", O_RDONLY);
	line = get_next_line(fd);
	x_y[0] = ft_strlen(line) - 1;
	x_y[1] = 0;
	while (line)
	{
		line = get_next_line(fd);
		x_y[1]++;
	}
	printf("Descriptor: %d\n", fd);
	printf("Columns: %d, rows: %d\n", x_y[1], x_y[0]);
	close(fd);
	return (x_y);
}

char	read_shit(void)
{
	int		fd;
	char	c[1];
	int		r;

	fd = open("map_good.ber", O_RDONLY);
	r = read(fd, c, 1);
	while (r)
	{
		if (c[0] == '1')
			printf("wall\n");
		else if (c[0] == '0')
			printf("empty\n");
		else if (c[0] == 'C')
			printf("collectible\n");
		else if (c[0] == 'E')
			printf("exit\n");
		else if (c[0] == 'P')
			printf("player\n");
		r = read(fd, c, 1);
	}
	return (c[0]);
}

void	whatever(void)
{
	mlx_shit	mlx_s;
	t_pics		images;

	mlx_s.mlx = mlx_init();
	mlx_s.width_height = read_map();
	images = load_images(&mlx_s);
	window_dimensions(&mlx_s, &images);
	paint_it_red(&mlx_s);
	images_to_screen(&mlx_s, &images);
	mlx_loop(mlx_s.mlx);
}

int	main(void)
{
	whatever();
	return (0);
}
