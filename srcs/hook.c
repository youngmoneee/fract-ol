/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:52:40 by youngpar          #+#    #+#             */
/*   Updated: 2022/01/09 03:01:46 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		key_press(int code)
{
	printf("code : %02x\n", code);
	if (code == KEY_ESC)
	{
		//mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
	return (0);
}

int		mouse_press(int code, int x, int y, char *s)
{
	printf("code : %02x x : %d y : %d at %s\n", code, x, y, s);
	return (0);
}

int		test(char *s)
{
	printf("code : Null at %s", s);
	return (0);
}

int exit_event(void)
{
	exit(0);
}
