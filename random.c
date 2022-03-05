/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:42:03 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/05 11:42:21 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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

void	paint_it_COLOUR(mlx_shit *mlx_s, int colour)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x++ <= mlx_s->width)
	{
		while (y++ <= mlx_s->height)
		{
			mlx_pixel_put(mlx_s->mlx, mlx_s->window, x, y, colour);
		}
		y = 0;
	}
}