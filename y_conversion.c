
// #include <so_long.h>
#include <stdio.h>
#include <unistd.h>
#include <get_next_line.h>

void	read_map(int *x, int *y)
{
	char			*line;
	int				fd;
	int num;

	fd = open("text_file.txt", O_RDONLY);
	line = get_next_line(fd);
	*y = (int)ft_strlen(line) - 1;
	*x = 0;
	while (line)
	{
		line = get_next_line(fd);
		(*x)++;
	}
	close(fd);
}

int main (void)
{
	int		x;
	int		y;
	char	**map; 
	char	c[1];
	int		fd;
	int 	i = 0;
	int 	num;

	fd = open("text_file.txt", O_RDONLY);
	read_map(&x, &y);
	printf("Columns: %d, rows: %d\n", y, x);

	map = malloc(sizeof(char *) * x + 1);
	while(i < x)
	{
		map[i] = malloc(sizeof(char) * y + 1);
		read(fd, map[i], y);
		read(fd, c, 1);
		i++;
	}
	printf("Row 1, column 2 = %c\n", map[3][1]);
	map[3][1] = 'y';
	printf("Row 1, column 2 = %c\n", map[3][1]);
	map[3][1] = '8';
	printf("Row 1, column 2 = %c\n", map[3][1]);
}