/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 18:42:05 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/22 18:39:16 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		burning2(t_iter iter, t_zoom *zoom, t_param *param, t_pnt *pnt)
{
	int		i;

	i = 0;
	while ((iter.z_r * iter.z_r + iter.z_i * iter.z_i) < 4 && i <
			zoom->iter_max)
	{
		iter.tmp = iter.z_r;
		iter.z_r = fabs(iter.z_r * iter.z_r - iter.z_i * iter.z_i +
				iter.c_r);
		iter.z_i = fabs(2 * iter.z_i * iter.tmp + iter.c_i);
		i++;
	}
	if (i == zoom->iter_max)
		draw_px(pnt->x, pnt->y, 0xFFFFFF, param);
	else
		draw_px(pnt->x, pnt->y, (i * 255 / zoom->iter_max) << param->color,
				param);
}

void		burning_iter(t_param *param, t_zoom *zoom)
{
	double	x;
	double	y;
	t_iter	iter;
	t_pnt	pnt;

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
			pnt.x = x;
			pnt.y = y;
			burning2(iter, zoom, param, &pnt);
			y = y + 1;
		}
		x = x + 1;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}
