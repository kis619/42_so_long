
// #include <so_long.h>
#include <stdio.h>
#include <unistd.h>
#include <get_next_line.h>

void	read_map(int *x, int *y)
{
	char	*line;
	int		fd;
	int		num;

	fd = open("text_file.txt", O_RDONLY);
	line = get_next_line(fd);
	*y = (int)ft_strlen(line) - 1;
	*x = 0;
	while (line)
	{
		if (*x == 0)
			free(line);
		line = get_next_line(fd);
		free(line);
		(*x)++;
	}
	close(fd);
}
char	**string_to_matrix()
{
	int		rows;
	int		columns;
	char	**map;
	int		fd;
	int 	i = 0;

	fd = open("text_file.txt", O_RDONLY);
	read_map(&rows, &columns);
	printf("Columns: %d, rows: %d\n", columns, rows);

	map = malloc(sizeof(char *) * rows + 1);
	while(i < rows)
	{
		map[i] = malloc(sizeof(char) * columns + 1);
		read(fd, map[i], columns + 1);
		map[i][columns + 1] = '\0';
		i++;
	}

	map[i] = NULL;
	printf("Row 1, column 2 = %c\n", map[3][1]);
	map[3][1] = 'y';
	printf("Row 1, column 2 = %c\n", map[3][1]);
	map[3][1] = '8';
	printf("Row 1, column 2 = %s\n", map[5]);
	return (map);
}

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

int main (void)
{
	char **map;

	map = string_to_matrix();
	free_all(map);
	return (0);
}