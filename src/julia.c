/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:39:34 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/22 17:25:47 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_iter(t_param *param, t_zoom *zoom)
{
	double	x;
	double	y;
	int		i;
	t_iter	iter;

	get_data(param);
	x = 0;
	while (x < LARGEUR)
	{
		y = 0;
		while (y < HAUTEUR)
		{
			iter.c_r = param->itera.c_r;
			iter.c_i = param->itera.c_i;
			iter.z_r = x / zoom->zoom + zoom->x1;
			iter.z_i = y / zoom->zoom + zoom->y1;
			i = 0;
			while ((iter.z_r * iter.z_r + iter.z_i * iter.z_i) < 4 &&
					i < zoom->iter_max)
			{
				iter.tmp = iter.z_r;
				iter.z_r = iter.z_r * iter.z_r - iter.z_i * iter.z_i +
					iter.c_r;
				iter.z_i = 2 * iter.z_i * iter.tmp + iter.c_i;
				i++;
			}
			if (i == zoom->iter_max)
				draw_px(x, y, 0xFFFFFF, param);
			else
				draw_px(x, y, (i * 255 / zoom->iter_max) << param->color,
					param);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}
