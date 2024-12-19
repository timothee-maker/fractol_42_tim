#ifndef FRACTOL_H
# define FRACTOL_H

// #include <unistd.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>

# define HAUTEUR 1050
# define LARGEUR 1080

typedef struct s_coordonee
{
	int			size_x;
	int			size_y;
	int			border;
}				t_size_img;

typedef struct s_fractal
{
	double		x;
	double		c_i;
	double		c_r;
	double		z_i;
	double		z_r;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int			image_x;
	int			image_y;
	int			iter_max;
	int			zoom_x;
	int			zoom_y;
	int			zoom;
}				t_fractal;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_size_img	rond;
	t_fractal	fractal;
}				t_data;

static int		in_circle(t_size_img *app, int x, int y);
void			circle(t_size_img *app, t_data img);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				create_trgb(int t, int r, int g, int b);
void			destroy_win(t_data *data);
int				printf_carre(t_data img);
int				create_trgb(int t, int r, int g, int b);
void			set_mlx(t_size_img *point);
int				key_hook(int keycode, t_data *data);
int				zoom(int event, int x, int y, t_data *img);
void			fractal(t_fractal *point, t_data img);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			set_fractal(t_fractal *fractal);
void			set_fractalv2(t_fractal *fractal);

#endif