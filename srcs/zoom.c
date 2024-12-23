/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:26:47 by tnolent           #+#    #+#             */
/*   Updated: 2024/12/21 14:24:58by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	zoom(t_fractal *fractal, double m_r, double m_i, double zoom)
// {
// 	fractal->max_x *= 1.1;
// 	fractal->min_x *= 1.1;
// 	fractal->max_y *= 1.1;
// 	fractal->min_y *= 1.1;
// }

// void	de_zoom(t_fractal *fractal, double m_r, double m_i, double zoom)
// {
// 	fractal->min_x /= 1.1;
// 	fractal->max_x /= 1.1;
// 	fractal->min_y /= 1.1;
// 	fractal->max_y /= 1.1;
// }

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	applyZoom(t_fractal *e, double mouseRe, double mouseIm,
		double zoomFactor)
{
	double interpolation;

	interpolation = 1.0 / zoomFactor;
	e->min_x = interpolate(mouseRe, e->min_x, interpolation);
	e->min_y = interpolate(mouseIm, e->min_y, interpolation);
	e->max_x = interpolate(mouseRe, e->max_x, interpolation);
	e->max_y = interpolate(mouseIm, e->max_y, interpolation);
}