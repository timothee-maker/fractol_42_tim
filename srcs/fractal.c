/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:12:04 by tnolent           #+#    #+#             */
/*   Updated: 2024/12/19 12:12:42 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	in_fractal(t_fractal *fractal, double x, double y);

void	fractal(t_fractal *point, t_data img)
{
	double		y;
	double		x;

	y = 0;
	// point->image_x = LARGEUR;
	// point->image_y = HAUTEUR;
	point->image_x = (point->x2 - point->x1) * point->zoom;
	point->image_y = (point->y2 - point->y1) * point->zoom;
	while (y < point->image_y)
	{
		x = 0;
		while (x < point->image_x)
		{
			// set_fractal(point);
			set_fractalv2(point);
			my_mlx_pixel_put(&img, x, y, in_fractal(point, x, y));
			x++;
		}
		y++;
	}
}

static int	in_fractal(t_fractal *fractal, double x, double y)
{
	int		i;
	double	tmp;

	fractal->c_r = x / fractal->zoom + fractal->x1;
	fractal->c_i = y / fractal->zoom + fractal->y1;

	i = 0;
	// printf("{%d, %d}", fractal->zoom_x, fractal->zoom_y);
	while (fractal->z_r * fractal->z_r < 4 && i < fractal->iter_max)
	{
		tmp = fractal->z_r;
		fractal->z_r = (fractal->z_r * fractal->z_r) - (fractal->z_i * fractal->z_i)
		 + fractal->c_r;
		fractal->z_i = (2 * fractal->z_i * tmp) + fractal->c_i;
		i++;
	}
	if (i == fractal->iter_max)
		return (create_trgb(0, 0, 0, 0));
	else if (i <= fractal->iter_max && i > 45)
		return (create_trgb(0, 0, 255, 255));
	else if (i <= 45 && i > 30)
		return (create_trgb(0, 255, 0, 255));
	else
		return (create_trgb(0, 0, 0, 0));
}
/*
static int	in_fractal(t_fractal *fractal, double x, double y)
{
	int		i;
	double	tmp;

	fractal->c_r = x / fractal->zoom_x + fractal->x1;
	fractal->c_i = y / fractal->zoom_y + fractal->y1;
	i = 0;
	// printf("{%d, %d}", fractal->zoom_x, fractal->zoom_y);
	while (fractal->z_r * fractal->z_r < 4 && i < fractal->iter_max)
	{
		tmp = fractal->z_r;
		fractal->z_r = (fractal->z_r * fractal->z_r) - (fractal->z_i * fractal->z_i)
		 + fractal->c_r;
		fractal->z_i = (2 * fractal->z_i * tmp) + fractal->c_i;
		i++;
	}
	if (i == fractal->iter_max)
		return (create_trgb(0, 0, 0, 0));
	else if (i <= fractal->iter_max && i > 49)
		return (create_trgb(0, 0, 255, 255));
	else if (i <= 48 && i > 30)
		return (create_trgb(0, 255, 255, 255));
	else
		return (create_trgb(0, 0, 0, 0));
}
*/