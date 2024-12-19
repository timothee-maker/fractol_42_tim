/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:22:13 by tnolent           #+#    #+#             */
/*   Updated: 2024/12/19 12:30:46 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_mlx(t_size_img *point)
{
	point->size_x = LARGEUR;
	point->size_y = HAUTEUR;
	point->border = 100;
}

void	set_fractalv2(t_fractal *fractal)
{	
	fractal->z_i = 0;
	fractal->z_r = 0;
	fractal->zoom = 400;
	fractal->iter_max = 50;
	fractal->image_x = (fractal->x2 - fractal->x1) * fractal->zoom;
	fractal->image_y = (fractal->y2 - fractal->y1) * fractal->zoom;
	fractal->x1 = -2.1;
	fractal->x2 = 0.6;
	fractal->y1 = -1.2;
	fractal->y2 = 1.2;
}

void	set_fractal(t_fractal *fractal)
{	
	fractal->z_i = 0;
	fractal->z_r = 0;
	fractal->iter_max = 100;
	fractal->image_x = LARGEUR;
	fractal->image_y = HAUTEUR;
	fractal->x1 = -2.1;
	fractal->x2 = 0.6;
	fractal->y1 = -1.2;
	fractal->y2 = 1.2;
	fractal->zoom_x = fractal->image_x / (fractal->x2 - fractal->x1);
	fractal->zoom_y = fractal->image_y / (fractal->y2 - fractal->y1);
}