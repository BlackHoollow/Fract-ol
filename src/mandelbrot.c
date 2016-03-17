/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 18:42:05 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/17 17:03:16 by nromptea         ###   ########.fr       */
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

void		get_data(t_param *param)
{
	param->str_img = mlx_get_data_addr(param->img, &param->bits, &param->size_line, &param->endian);
}

void		mandel_iter(t_param *param)
{
	float	x;
	float	y;
	int		i;
	t_iter	iter;

	get_data(param);
	x = 0;
	while (x < get_x_img(ZOOM))
	{
		y = 0;
		while (y < get_y_img(ZOOM))
		{
			iter.c_r = x / ZOOM + X1;
			iter.c_i = y / ZOOM + Y1;
			iter.z_r = 0;
			iter.z_i = 0;
			i = 0;
			while ((iter.z_r * iter.z_r + iter.z_i * iter.z_i) < 4 && i < ITERMAX)
			{	
				iter.tmp = iter.z_r;
				iter.z_r = iter.z_r * iter.z_r - iter.z_i * iter.z_i + iter.c_r;
				iter.z_i = 2 * iter.z_i * iter.tmp + iter.c_i;
				i++;
			}
			if (i == ITERMAX)
				draw_pixel(x, y, 0xFFFFFF, param);
			else
				draw_pixel(x, y, i * 255 / ITERMAX, param);
			y = y + 1;
		}
		x = x + 1;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}
