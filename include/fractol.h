#ifndef FRACTOL_H
# define FRACTOL_H

// #include <unistd.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>

# define HAUTEUR 1050
# define LARGEUR 1080
# define ITER_MAX 100
# define ZOOM 4
# define DEZOOM 5

typedef struct s_coordonee
{
	int		size_x;
	int		size_y;
	int		border;
}			t_size_img;

typedef struct s_fractal
{
	int		nb_fractal;
	double	c_i;
	double	c_r;
	double	z_i;
	double	z_r;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	int		iter_max;
	int		zoom_x;
	int		zoom_y;
	int		zoom;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_fractal;

void		my_mlx_pixel_put(t_fractal *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
void		destroy_win(t_fractal *data);
int			create_trgb(int t, int r, int g, int b);
void		set_mlx(t_fractal *point);
int			key_hook(int keycode, t_fractal *data);
void		fractal(t_fractal *point, int number_fractal);
int			mandelbrot(t_fractal *fractal, double x, double y);
int			julia(t_fractal *fractal, double c_r, double c_i);
void		my_mlx_pixel_put(t_fractal *data, int x, int y, int color);
void		set_fractal(t_fractal *fractal);
void		set_fractalv2(t_fractal *fractal, int type);
int			pimp_my_fractal(int i);
static int	in_circle(t_size_img *app, int x, int y);
void		circle(t_size_img *app, t_fractal img);
int			mouse_hook(int event, int x, int y, t_fractal *fractal);
// void		de_zoom(t_fractal *fractal, double m_r, double m_i, double zoom);
// void		zoom(t_fractal *fractal, double m_r, double m_i, double zoom);
void 		applyZoom(t_fractal* e, double mouseRe, double mouseIm, double zoomFactor);
void 		not_enough_args(void);

#endif