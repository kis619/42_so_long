/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:17:28 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/06 13:02:02 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>




//Returns a string with an error message if the item is not present on the map, 0 if everything is fine
char *map_is_valid(mlx_shit *mlx_s, char *map_path)
{
	mlx_s->map = string_to_matrix(map_path); //need to free it, but when? - on exit
	if (!item(mlx_s->map, 'C'))
		return ("Error: there are no collectibles on the map.\n");
	if (!item(mlx_s->map, 'P'))
		return ("Error: there is no player on the map.\n");
	if (!item(mlx_s->map, 'E'))
		return ("Error: there is no exit on the map.\n");
	if (multiple_players(mlx_s->map))
		return ("Error: there is more than 1 player on the map.\n");
	return (0);
}

//Returns 1 if it is a .ber file, 0 if not
int is_ber_file(char *map)
{
	int len;
	
	len = ft_strlen(map);
	if (len < 5)
		return (0);
	if (map[len - 1] != 'r')
		return (0);
	if (map[len - 2] != 'e')
		return (0);
	if (map[len - 3] != 'b')
		return (0);
	if (map[len - 4] != '.')
		return (0);
	return (1);
}

//Retruns 1 if map is valid, 0 if not
int checks(int argc, char *argv[], mlx_shit *mlx_s)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error: wrong amount of arguments.\n", 1);
		ft_putstr_fd("The programme requires two arguments: ./so_long + file_name.ber\n", 1);
		return (0);
	}
	 
	if (is_ber_file(argv[1]) != 1)
	{	
		ft_putstr_fd("Error: the programme only accepts .ber files\n", 1);
		return (0);
	}
	if (map_is_valid(mlx_s, argv[1]) != 0)
	{
		ft_putstr_fd(map_is_valid(mlx_s, argv[1]), 1);
		return (0);
	}
	return (1);
}