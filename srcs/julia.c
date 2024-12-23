/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:47:35 by tnolent           #+#    #+#             */
/*   Updated: 2024/12/23 17:05:40 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_fractal *fractal, double c_r, double c_i)
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
		return (create_trgb(0, c_r, c_i, i * 255 / ITER_MAX));
}

