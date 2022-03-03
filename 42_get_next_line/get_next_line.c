/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:46:15 by kmilchev          #+#    #+#             */
/*   Updated: 2021/12/13 12:46:15 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

char	*read_to_nl_or_eof(int fd, char *line)
{
	char	*buf;
	ssize_t	read_chars;

	read_chars = 69;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	while (read_chars != 0 && !(ft_strchr(line, '\n')))
	{
		read_chars = read(fd, buf, BUFFER_SIZE);
		if (read_chars == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_chars] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*trim_up_to_nl(char *line)
{
	char	*new;
	int		i;

	if (line[0] == '\0')
		return (NULL);
	new = (char *)malloc(ft_strlen(line) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		new[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*update_buffer(char *line)
{
	char	*new;
	int		i;
	int		idx;

	i = 0;
	idx = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	new = malloc(ft_strlen(line) + 1);
	if (new == NULL)
		return (NULL);
	while (line[++i])
		new[idx++] = line[i];
	new[idx] = '\0';
	free (line);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = read_to_nl_or_eof(fd, buf);
	if (buf == NULL)
		return (NULL);
	line = trim_up_to_nl(buf);
	buf = update_buffer(buf);
	return (line);
}
