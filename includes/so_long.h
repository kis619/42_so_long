/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:21:35 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/04 18:45:39 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef	struct pics
{
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	int		img_width;
	int		img_height;
}			t_pics;

typedef struct mlx_shit
{
	void	*mlx;
	void	*window;
	int		*width_height;
	int		width;
	int		height;
	t_pics	images;
}			mlx_shit;

typedef struct t_indeces
{
	int		fd;
	int		x;
	int		y;
}			t_indeces;

enum {
	ON_KEYDOWN = 125,
	ON_KEYUP = 126,
	ON_KEYLEFT = 123,
	ON_KEYRIGHT = 124,
	// ON_MOUSEDOWN = 4,
	// ON_MOUSEUP = 5,
	// ON_MOUSEMOVE = 6,
	// ON_EXPOSE = 12,
	ON_DESTROY = 53,
};



int *read_map();
#endif 
