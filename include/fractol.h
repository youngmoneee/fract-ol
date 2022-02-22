#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

# define TRUE		1
# define FALSE		0

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_MOTION	6

# define KEY_UP		0x7e
# define KEY_DOWN	0x7d
# define KEY_LEFT	0x7b
# define KEY_RIGHT	0x7c
# define KEY_SPACE	0x31

# define KEY_ESC	0x35
# define RED_DOT	0xA1

# define WIN_WIDTH	800
# define WIN_HEIGHT	600

# define RGB_OFFSET 0.333333
# define COLOR_MAX	255.999999

typedef unsigned int	uint;

typedef struct	s_img
{
	void	*imgptr;
	char	*data;
	int		lsize;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_mlx;

int		key_press(int code);
int		mouse_press(int code, int x, int y, char *s);
int		test(char *s);
int 	exit_event(void);
void	error_msg(char *msg);
int		close_mlx(t_mlx *mlx);

int		init_win(t_mlx *mlx);
int 	close(int code);
void 	print_px(int px, int py, int color, t_img *img);
void	print_img(t_img *img);

#endif
