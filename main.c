#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
void whatever()
{
	void	*mlx;
	void	*window;
	void	*img;
	int		img_width;
	int		img_height;
	int		screen_width;
	int		screen_height;
	
	screen_width = 600;
	screen_height = 600;
	mlx = mlx_init();
	window = mlx_new_window(mlx, screen_width, screen_height, "Hello world!");

	int i = 0;
	int y = 0;
	while (i++ < 1920)
	{
		while (y++ < 1080)
		{
			mlx_pixel_put(mlx, window, i, y, 0x44FF0022);
		}
		y = 0;
	}
	img = mlx_xpm_file_to_image(mlx, "2.xpm", &img_width, &img_height);
	printf("Width = %d, height = %d", img_width, img_height);
	int j = 0;
	while(img_height * j < screen_height)
	{
		i = 0;
		while (img_width * i < screen_width)
		{
			mlx_put_image_to_window(mlx, window, img, img_width * i, img_height * j++);
			i++;
		}
		// j++;
	}
	mlx_loop(mlx);
}

int main(void)
{
	whatever();
	return (0);
}
