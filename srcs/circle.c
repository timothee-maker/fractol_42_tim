/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:47:21 by tnolent           #+#    #+#             */
/*   Updated: 2024/12/17 18:56:17 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// #include "../include/fractol.h"
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include <math.h>
#include <stdio.h>

static int	in_circle(t_size_img *point, int x, int y)
{
	static int i = 0;

	x = (x - (point->size_x / 2));
	y = ((point->size_y / 2) - y);
	if ((size_t)(x * x + y * y) < (point->border * point->border))
		return (create_trgb(0, 255, i++, 0));
	else
	{
		return (create_trgb(0, 255, 0, 255));
		i += 2;
	}
}

void	circle(t_size_img *point, t_data img)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < point->size_y)
	{
		x = 0;
		while (x < point->size_x)
		{
			my_mlx_pixel_put(&img, x, y, in_circle(point, x, y));
			x++;
		}
		y++;
	}
}
