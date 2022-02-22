/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:32:25 by youngpar          #+#    #+#             */
/*   Updated: 2022/02/03 19:05:56 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		main(int argc, char **argv)
{
	t_mlx	mlx;

	//if (argc != 2)
	//	error_msg("Usage: ./so_long [mandelbrot] OR [julia set]\n");
	if (!init_win(&mlx))
		return (0);
	print_img(&mlx.img);
	printf("dddd\n");
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.imgptr, 0, 0);
	printf("ffff\n");
	mlx_hook(mlx.win_ptr, X_EVENT_KEY_PRESS, 0, (*key_press), 0);
	printf("gggg\n");
	mlx_hook(mlx.win_ptr, X_EVENT_KEY_EXIT, 0, (*close_mlx), 0);
	printf("qqqq\n");
	mlx_loop(mlx.mlx_ptr);

    return (0);
}
