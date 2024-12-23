/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failure.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:52:56 by tnolent           #+#    #+#             */
/*   Updated: 2024/12/21 15:18:46 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void not_enough_args(void)
{
    printf("Not enough args\n voici les fractales que Timothee vous propose :\n");
    printf("   =====Mandelbrot======Julia========Burning Ship");
    exit(0);
}