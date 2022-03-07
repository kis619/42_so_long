/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:55:34 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/07 13:27:11 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_all(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

char	*ft_strrchr(const char *s, int c)
{	
	char	*last;

	last = 0;
	while (*s)
	{
		if (*s == c)
			last = (char *)s;
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (last);
}

void	number_of_columns_rows(int *rows, int *columns, char *map_path)
{
	char	*line;
	int		fd;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	*columns = (int)ft_strlen(line) - 1;
	*rows = 0;
	while (line)
	{
		if (*rows == 0)
			free(line);
		line = get_next_line(fd);
		free(line);
		(*rows)++;
	}
	close(fd);
}

char	**string_to_matrix(char *map_path)
{
	t_data	d;

	d.i = 0;
	d.fd = open(map_path, O_RDONLY);
	number_of_columns_rows(&d.rows, &d.columns, map_path);
	d.map = malloc(sizeof(char *) * d.rows + 1);
	if (!d.map)
		exit(EXIT_FAILURE);
	while (d.i < d.rows)
	{
		d.map[d.i] = malloc(sizeof(char) * d.columns + 1);
		if (!d.map[d.i])
		{
			free(d.map[d.i]);
			return (0);
		}
		read(d.fd, d.map[d.i], d.columns + 1);
		d.map[d.i][d.columns] = '\0';
		d.i++;
	}
	d.map[d.i] = NULL;
	return (d.map);
}
