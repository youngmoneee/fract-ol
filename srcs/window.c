#include "../include/fractol.h"

int		init_win(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "./fractol");
	mlx->img.imgptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.data = mlx_get_data_addr(mlx->img.imgptr, &mlx->img.bpp, &mlx->img.lsize, &mlx->img.endian);
	printf("mlx ptr : %p\n", mlx->mlx_ptr);
	printf("win ptr : %p\n", mlx->win_ptr);
	printf("img ptr : %p\n", mlx->img.imgptr);
	printf("img data : %p\n", mlx->img.data);
	if (!(mlx->mlx_ptr && mlx->win_ptr && mlx->img.imgptr && mlx->img.data))
		return (0);
	return (1);
}

int	close_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
	return (0);
}

int 	close(int code)
{
	exit(0);
}

void	error_msg(char *msg)
{
	//ft_putstr_fd(msg, 1);
	printf("%s\n", msg);
	exit(1);
}