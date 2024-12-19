/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:26:47 by tnolent           #+#    #+#             */
/*   Updated: 2024/12/19 12:40:28 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom(int event, int x, int y, t_data *img)
{
	if (event == 4)
	{
		img->fractal.zoom += 10;
	}
	else if (event == 5)
	{
		printf("%d", img->fractal.zoom);
		img->fractal.zoom = img->fractal.zoom - 10;

	}
	mlx_clear_window(img->mlx, img->win);
	fractal(&img->fractal, *img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}
