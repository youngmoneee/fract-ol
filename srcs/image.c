#include "../include/fractol.h"

int		mandelbrot(int h, int w, int idx) {
	double	real;
	double	imagin;
	double	px;
	double	py;
	double	px_new;

	real = ((w - WIN_WIDTH / 2) * 3.0 / WIN_WIDTH) - 0.5;
	imagin = ((WIN_HEIGHT / 2) - h) * 2.0 / WIN_HEIGHT;
	px = 0;
	py = 0;
	while ((pow(px, 2.0) + pow(py, 2.0) < 4) && (idx < 100))
	{
		px_new = pow(px, 2.0) - pow(py, 2.0) + real;
		py = 2 * px * py + imagin;
		px = px_new;
		idx++;
	}
	return (idx);
}

int		cal_colour(int idx)
{
	double 	r;
	double 	g;
	double 	b;
	int 	color;

	r = sin(RGB_OFFSET * (double)idx);
	g = sin(RGB_OFFSET * (double)idx) * 127 +128;
	b = sin(RGB_OFFSET * (double)idx) * 127 + 128;
	color = ((int)(COLOR_MAX * r) << 16) | ((int)(COLOR_MAX * g) << 8) | (int)(COLOR_MAX * b);
	return (color);
}

void 	print_px(int px, int py, int color, t_img *img)
{
	char	*pixel;

	pixel = img->data + (px * img->bpp / 8) + (py * img->lsize);
	*(unsigned int *)pixel = color;
}

void	print_img(t_img *img)
{
	int 	idx;
	int 	w;
	int 	h;
	int 	color;

	h = -1;
	while (++h <= WIN_HEIGHT)
	{
		w = -1;
		while (++w <= WIN_WIDTH) {
			idx = mandelbrot(h, w, 0);
			if (idx < 100)
			{
				color = cal_colour(idx);
				print_px(w, h, color, img);
			}
			else
			{
				print_px(w, h, 0x00000000, img);
			}
		}
	}
}
