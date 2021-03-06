/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:51:32 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/07 13:15:23 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(int argc, char *argv[])
{
	t_mlx	mlx_s;

	if (checks(argc, argv, &mlx_s) == 0)
		return (1);
	mlx_s.mlx = mlx_init();
	number_of_columns_rows(&(mlx_s.height), &(mlx_s.width), argv[1]);
	mlx_s.images = load_images(&mlx_s);
	window_dimensions(&mlx_s);
	mlx_s.map = string_to_matrix(argv[1]);
	render_map(&mlx_s);
	mlx_key_hook(mlx_s.window, handle_keys, &mlx_s);
	mlx_hook(mlx_s.window, X_CLOSE, 0, x_close, 0);
	mlx_loop(mlx_s.mlx);
	return (0);
}
