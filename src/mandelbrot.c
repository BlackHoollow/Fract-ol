/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 18:42:05 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/17 13:03:47 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

# define X1 -2.1
# define X2 0.6
# define Y1 -1.2
# define Y2 1.2
# define ZOOM 100

float		get_x_img(int zoom)
{
	float	img_x;

	img_x = (X2 - X1) * zoom;
	return (img_x);
}

float		get_y_img(int zoom)
{
	float	img_y;

	img_y = (Y2 - Y1) * zoom;
	return (img_y);
}

void		mandel_iter(t_param *param)
{
	float	x;
	float	y;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	float	tmp;
	int		i;

	x = 0;
	while (x < get_x_img(ZOOM))
	{
		y = 0;
		while (y < get_y_img(ZOOM))
		{
			c_r = x / ZOOM + X1;
			c_i = y / ZOOM + Y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while ((z_r * z_r + z_i * z_i) < 4 && i < ITER)
			{	
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == ITER)
				draw_pixel(x, y, 0xFFFFFF, param);
			y = y + 1;
		}
		x = x + 1;
	}
}
