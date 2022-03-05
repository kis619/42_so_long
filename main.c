/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:51:32 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/05 15:41:35 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(void)
{
	mlx_shit	mlx_s;

	////////////////Initial Setup  - no validations yet
	mlx_s.mlx = mlx_init();
	number_of_columns_rows(&(mlx_s.height), &(mlx_s.width));
	mlx_s.images = load_images(&mlx_s);
	window_dimensions(&mlx_s);
	
	////////////////first read of the map and rendering
	mlx_s.map = string_to_matrix(); //need to free it, but when? - on exit
	render_map(&mlx_s);
	// printf("Collectibles: %d\n", collectibles(mlx_s.map));
	

	///////////////
	mlx_key_hook(mlx_s.window, handle_keys, &mlx_s);	
	mlx_loop(mlx_s.mlx);
	return (0);
}