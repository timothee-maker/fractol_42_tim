/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:12:04 by tnolent           #+#    #+#             */
/*   Updated: 2024/12/23 17:11:54 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal(t_fractal *point, int number_fractal)
{
	int		y;
	int		x;
	double	c_r;
	double	c_i;

	mlx_clear_window(point->mlx, point->win);
	y = 0;
	while (y < LARGEUR)
	{
		x = 0;
		while (x < HAUTEUR)
		{	
			c_r = point->min_x + (double)x * (point->max_x - point->min_x) / LARGEUR;
			c_i = point->max_y + (double)y * (point->min_y - point->max_y) / HAUTEUR;
			if (number_fractal == 1)
				my_mlx_pixel_put(point, x, y, mandelbrot(point, c_r, c_i));
			else if (number_fractal == 2)
				my_mlx_pixel_put(point, x, y, julia(point, x, y));
			x++;
		}
		y++;
	}
}
