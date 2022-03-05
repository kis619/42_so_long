/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:55:34 by kmilchev          #+#    #+#             */
/*   Updated: 2022/03/05 19:00:42 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void free_all(char **map)
{
	int i = 0;

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