/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:00:35 by tnolent           #+#    #+#             */
/*   Updated: 2024/12/23 16:52:36 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_fractal *fractal, double c_r, double c_i)
{
	int		i;
	double	tmp;

	i = 0;
	fractal->z_r = 0;
	fractal->z_i = 0;
	while (fractal->z_r * fractal->z_r < 4 && i < ITER_MAX)
	{
		tmp = fractal->z_r;
		fractal->z_r = (fractal->z_r * fractal->z_r) - (fractal->z_i * fractal->z_i)
		 + c_r;
		fractal->z_i = (2 * fractal->z_i * tmp) + c_i;
		i++;
	}
	if (i == ITER_MAX)
		return (0);
	else
		return (create_trgb(0, i * 255 / ITER_MAX, 0, i * 255 / ITER_MAX));
}

/*
static int	in_fractal(t_fractal *fractal, double c_r, double y)
{
	int		i;
	double	tmp;
	fractal->c_r = c_r / fractal->zoom_x + fractal->x1;
	fractal->c_i = y / fractal->zoom_y + fractal->y1;
	i = 0;
	// printf("{%d, %d}", fractal->zoom_x, fractal->zoom_y);
	while (fractal->z_r * fractal->z_r < 4 && i < fractal->iter_max)
	{
		tmp = fractal->z_r;
		fractal->z_r = (fractal->z_r * fractal->z_r) - (fractal->z_i
				* fractal->z_i)
			+ fractal->c_r;
		fractal->z_i = (2 * fractal->z_i * tmp) + fractal->c_i;
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