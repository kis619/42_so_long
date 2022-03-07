/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:38:52 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/07 12:51:55 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	render_map(t_mlx *mlx_s)
{
	void	*img;

	mlx_s->row = 0;
	while (mlx_s->map[mlx_s->row] != NULL)
	{
		mlx_s->col = 0;
		while (mlx_s->map[mlx_s->row][mlx_s->col])
		{
			if (mlx_s->map[mlx_s->row][mlx_s->col] == '1')
				img = mlx_s->images.wall;
			else if (mlx_s->map[mlx_s->row][mlx_s->col] == '0')
				img = mlx_s->images.floor;
			else if (mlx_s->map[mlx_s->row][mlx_s->col] == 'C')
				img = mlx_s->images.coll;
			else if (mlx_s->map[mlx_s->row][mlx_s->col] == 'E')
				img = mlx_s->images.door;
			else if (mlx_s->map[mlx_s->row][mlx_s->col] == 'P')
				img = mlx_s->images.player;
			mlx_put_image_to_window(mlx_s->mlx, mlx_s->window, img,
				mlx_s->images.img_width * mlx_s->col,
				mlx_s->images.img_height * mlx_s->row);
			mlx_s->col++;
		}
		mlx_s->row++;
	}
}

t_pics	load_images(t_mlx *mlx_s)
{
	t_pics	images;

	images.wall = mlx_xpm_file_to_image(mlx_s->mlx,
			"images/size_w40_h40/wall.xpm",
			&images.img_width, &images.img_height);
	images.floor = mlx_xpm_file_to_image(mlx_s->mlx,
			"images/size_w40_h40/floor.xpm",
			&images.img_width, &images.img_height);
	images.coll = mlx_xpm_file_to_image(mlx_s->mlx,
			"images/size_w40_h40/collectible.xpm",
			&images.img_width, &images.img_height);
	images.door = mlx_xpm_file_to_image(mlx_s->mlx,
			"images/size_w40_h40/door.xpm",
			&images.img_width, &images.img_height);
	images.player = mlx_xpm_file_to_image(mlx_s->mlx,
			"images/size_w40_h40/player.xpm",
			&images.img_width, &images.img_height);
	return (images);
}
