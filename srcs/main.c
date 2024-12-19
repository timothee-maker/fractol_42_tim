/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:48:52 by tnolent           #+#    #+#             */
/*   Updated: 2024/12/19 12:08:52 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/fractol.h"
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include "fractol.h"
#include <math.h>
#include <stdio.h>

int	main(void)
{
	t_data		img;
	t_fractal	fractol;
	int			mask;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, LARGEUR, HAUTEUR, "Hello world!");
	img.img = mlx_new_image(img.mlx, LARGEUR, HAUTEUR);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	set_mlx(&img.rond);
	set_fractalv2(&fractol);
	fractal(&fractol, img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_mouse_hook(img.win, &zoom, &img);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_loop(img.mlx);
	return (0);
}

