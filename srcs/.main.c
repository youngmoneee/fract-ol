#include "../include/fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

void	create_img(t_game *solong, t_img *i);
int	main(void)
{
	// procedure
	t_game	solong;
	t_img	img, pla;

	solong.mlxptr = mlx_init();
	solong.winptr = mlx_new_window(solong.mlxptr, 600, 600, "so long");

	solong.user.img.imgptr = mlx_xpm_file_to_image(solong.mlxptr, ITEM_PATH, &solong.user.img.w, &solong.user.img.h);
	img.data = (int *)mlx_get_data_addr(solong.user.img.imgptr, &solong.user.img.bpp, &solong.user.img.lsize, &solong.user.img.endian);
	for (int i = 0; i < img.h; i++)
	{
		for (int j = 0; j < img.w / 2; j++)
		{
			if (j % 2)
				img.data[i * img.w + j] = 0xFFFFFF;
			else
				img.data[i * img.w + j] = 0xFF0000;
			//my_mlx_pixel_put(img.img, 0, 0, 0xf0f0f0f0);
		}
	}
	mlx_put_image_to_window(solong.mlxptr, solong.winptr, solong.user.img.imgptr, 50, 50);
	mlx_key_hook(solong.winptr, &key_press, solong.mlxptr);
	mlx_mouse_hook(solong.winptr, &mouse_press, "mouse");
	mlx_expose_hook(solong.winptr, &test, "expose");
	mlx_hook(solong.winptr, 17, 0, exit_event, 0);
	mlx_loop(solong.mlxptr);		//	int mlx_loop(void *mlx_ptr); - no return value

	return (0);
}
