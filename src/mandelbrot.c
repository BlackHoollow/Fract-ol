/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 18:42:05 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/21 16:19:47 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		get_data(t_param *param)
{
	param->str_img = mlx_get_data_addr(param->img, &param->bits,
			&param->size_line, &param->endian);
}

void		mandel_iter(t_param *param, t_zoom *zoom)
{
	float	x;
	float	y;
	int		i;
	float	img_x;
	float	img_y;
	t_iter	iter;

	img_x = (zoom->x2 - zoom->x1) * zoom->zoom;
	img_y = (zoom->y2 - zoom->y1) * zoom->zoom;
	get_data(param);
	x = 0;
	while (x < LARGEUR)
	{
		y = 0;
		while (y < HAUTEUR)
		{
			iter.c_r = x / zoom->zoom + zoom->x1;
			iter.c_i = y / zoom->zoom + zoom->y1;
			iter.z_r = 0;
			iter.z_i = 0;
			i = 0;
			while ((iter.z_r * iter.z_r + iter.z_i * iter.z_i) < 4 && i < zoom->iter_max)
			{
				iter.tmp = iter.z_r;
				iter.z_r = iter.z_r * iter.z_r - iter.z_i * iter.z_i + iter.c_r;
				iter.z_i = 2 * iter.z_i * iter.tmp + iter.c_i;
				i++;
			}
			if (i == zoom->iter_max)
				draw_px(x, y, 0xFFFFFF, param);
			else
				draw_px(x, y, i * 255 / zoom->iter_max, param);
			y = y + 1;
		}
		x = x + 1;
	}
	draw_px(600, 500, 0xFF3030, param);
	draw_px(400, 500, 0xFF3030, param);
	draw_px(500, 400, 0xFF3030, param);
	draw_px(500, 500, 0xFF3030, param);
	draw_px(500, 600, 0xFF3030, param);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}
