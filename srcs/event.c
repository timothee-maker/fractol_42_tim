/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:23:57 by tnolent           #+#    #+#             */
/*   Updated: 2024/12/23 17:27:06 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractal *f)
{
	if (keycode == 65307 || keycode == 13)
		destroy_win(f);
	return (0);
}

int	mouse_hook(int event, int x, int y, t_fractal *f)
{
	double	mouse_re;
	double	mouse_im;

	// mouse_re = f->min_x + (x / (double)LARGEUR) * (f->max_x - f->min_x);
	// mouse_im = f->min_y + ((double)HAUTEUR - y) * (f->max_y - f->min_y);
	mouse_re = (double)x / (LARGEUR / (f->max_x - f->min_x)) + f->min_x;
	mouse_im = (double)y / (HAUTEUR / (f->max_y - f->min_y)) + f->min_y;
	if (event == DEZOOM)	
		applyZoom(f, mouse_re, mouse_im, 0.9);
	else if (event == ZOOM)
		applyZoom(f, mouse_re, mouse_im, 1.1);
	else if (event == 1)
		
	fractal(f, f->nb_fractal);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}