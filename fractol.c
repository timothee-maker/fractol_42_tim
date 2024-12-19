/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:47:25 by tnolent           #+#    #+#             */
/*   Updated: 2024/12/17 11:42:23 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:52:22 by tnolent           #+#    #+#             */
/*   Updated: 2024/12/04 10:50:17 tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/fractol.h"
#include "fractol.h"
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include <math.h>
#include <stdio.h>

void	fractal(t_coordonee *point, t_data img);
static int	in_fractal(t_coordonee *point, double x, double y);

int	main(void)
{
	t_data	img;
	int		mask;

	mask = (1L << 0) | (1L << 2);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, LARGEUR, HAUTEUR, "Hello world!");
	img.img = mlx_new_image(img.mlx, LARGEUR, HAUTEUR);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	// printf_carre(img);
	set_mlx(&img.rond);
	// circle(&img.rond, img);
	// fractal(&img.rond, img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_mouse_hook(img.win, zoom, &img);
	mlx_key_hook(img.win, key_hook, &img);
	// mlx_hook(img.win, 4, mask, printf_molette, &img);
	// mlx_hook(img.win, 4, mask, zoom, &rond);
	mlx_loop(img.mlx);
	return (0);
}



void	fractal(t_coordonee *point, t_data img)
{
	double	x;
	double	y;
	int	color;

	y = 0;
	while (y < point->size_y)
	{
		x = 0;
		while (x < point->size_x)
		{
			my_mlx_pixel_put(&img, x, y, in_fractal(point, x, y));
			x++;
		}
		y++;
	}
	// mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
}

static int	in_fractal(t_coordonee *point, double x, double y)
{
	static int i = 0;

	x = (x - (point->size_x / 2));
	y = (y - (point->size_y / 2));
	if (fabs(x) <= point->border && fabs(y) <= point->border)
		return (create_trgb(0, 255, 255, 255));
	else
	{
		return (create_trgb(0, 0, 0, 0));
	}
}