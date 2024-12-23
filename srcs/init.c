/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:22:13 by tnolent           #+#    #+#             */
/*   Updated: 2024/12/21 14:44:54 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_mlx(t_fractal *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, LARGEUR, HAUTEUR, "PUTAIN DE FRACTOL DE MERDE");
	mlx->img = mlx_new_image(mlx->mlx, LARGEUR, HAUTEUR);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
}

void	set_fractalv2(t_fractal *fractal, int type)
{
	if (type == 1)
	{
		fractal->iter_max = 100;
		fractal->min_x = -2.1;
		fractal->max_x = 0.6;
		fractal->min_y = -1.2;
		fractal->max_y = 1.2;
	}
}
