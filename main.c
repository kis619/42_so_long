/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:51:32 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/05 19:10:03 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

//Retruns 1 if map is valid, 0 if not
int checks(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr_fd("Error: wrong amount of arguments.\n", 1);
		ft_putstr_fd("The programme requires two arguments: ./so_long + file_name.ber\n", 1);
		return (0);
	}
	return (1);
}


int	main(int argc, char *argv[])
{
	mlx_shit	mlx_s;

	if (checks(argc, argv) == 0)
		return (1);
	////////////////Initial Setup  - no validations yet
	mlx_s.mlx = mlx_init();
	number_of_columns_rows(&(mlx_s.height), &(mlx_s.width));
	mlx_s.images = load_images(&mlx_s);
	window_dimensions(&mlx_s);
	
	////////////////first read of the map and rendering
	mlx_s.map = string_to_matrix(); //need to free it, but when? - on exit
	render_map(&mlx_s);
	

	///////////////
	mlx_key_hook(mlx_s.window, handle_keys, &mlx_s);	
	mlx_loop(mlx_s.mlx);
	return (0);
}