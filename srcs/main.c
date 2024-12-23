/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:48:52 by tnolent           #+#    #+#             */
/*   Updated: 2024/12/20 10:24:08 tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/fractol.h"
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include "fractol.h"
#include <math.h>
#include <stdio.h>

void	take_args(char *av, t_fractal *f)
{
	if (strcmp(av, "Mandelbrot") == 0)
		f->nb_fractal = 1;
	else if (strcmp(av, "Julia") == 0)
		f->nb_fractal = 2;
	else
		not_enough_args();
}

int	main(int ac, char **av)
{
	t_fractal	fractol;

	if (ac < 2)
		not_enough_args();
	take_args(av[1], &fractol);
	set_mlx(&fractol);
	set_fractalv2(&fractol, 1);
	fractal(&fractol, fractol.nb_fractal);
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
	mlx_mouse_hook(fractol.win, mouse_hook, &fractol);
	mlx_key_hook(fractol.win, key_hook, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}

