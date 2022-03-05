/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:51:32 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/05 11:51:49 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(void)
{
	mlx_shit	mlx_s;
	t_pics		images;

	////////////////Initial Setup  - no validations yet
	mlx_s.mlx = mlx_init();
	rows_columns(&(mlx_s.width), &(mlx_s.height));
	images = load_images(&mlx_s);
	window_dimensions(&mlx_s, &images);
	images_to_screen(&mlx_s, &images);

	///////////////Managing events
	mlx_key_hook(mlx_s.window, handle_keys, &mlx_s);
	mlx_loop(mlx_s.mlx);
	return (0);
}