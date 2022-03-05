/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:38:52 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/05 11:39:21 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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