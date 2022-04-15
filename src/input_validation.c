/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:17:28 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/07 13:26:30 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

//Retruns 1 if map is valid, 0 if not
int	checks(int argc, char *argv[], t_mlx *mlx_s)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong amount of arguments. ", 1);
		ft_putstr_fd("The programme requires two arguments: ", 1);
		ft_putstr_fd("./so_long + file_name.ber\n", 1);
		return (0);
	}
	if (!file_exists(argv[1]))
	{
		ft_putstr_fd("Error\nThe file does not exist.\n", 1);
		return (0);
	}
	if (is_ber_file(argv[1]) != 1)
	{	
		ft_putstr_fd("Error\nThe programme only accepts .ber files.\n", 1);
		return (0);
	}
	if (map_is_valid(mlx_s, argv[1]) != 0)
	{
		ft_putstr_fd(map_is_valid(mlx_s, argv[1]), 1);
		return (0);
	}
	return (1);
}

//Returns 1 if the file doesn't exist, 0 if not
int	file_exists(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	close(fd);
	if (fd == -1)
		return (0);
	return (1);
}

//Returns 1 if it is a .ber file, 0 if not
int	is_ber_file(char *map)
{
	int	len;

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

//Returns 1 if the map is rectangular, 0 if not
int	map_is_rectangular(char *map_path)
{
	t_file_read	data;
	int			last_len;
	int			curr_len;

	data.fd = open(map_path, O_RDONLY);
	data.line = get_next_line(data.fd);
	last_len = ft_strlen(data.line);
	free(data.line);
	while (data.line)
	{
		data.line = get_next_line(data.fd);
		if (!data.line)
			break ;
		curr_len = ft_strlen(data.line);
		if (!ft_strchr(data.line, '\n'))
			curr_len += 1;
		if (last_len != curr_len)
		{
			free(data.line);
			return (0);
		}
		free(data.line);
		last_len = curr_len;
	}
	return (1);
}
