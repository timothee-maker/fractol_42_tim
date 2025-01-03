/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:20:06 by tnolent           #+#    #+#             */
/*   Updated: 2024/12/23 17:08:45 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

# define GREN create_trgb(0, 0, 255, 0)
# define BLUE create_trgb(0, 0, 0, 255)
# define RED create_trgb(0, 255, 0, 0)
# define WHITE create_trgb(0, 255, 255, 255)

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	pimp_my_fractal(int i)
{
	return (create_trgb(0, 0, 0, i * 255 / ITER_MAX));
}