/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:39:34 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/18 16:40:32 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_iter(t_param *param, t_zoom *zoom)
{
	float	x;
	float	y;
	int		i;
	float	img_x;
	float	img_y;
	t_iter	iter;

	img_x = (zoom->x2 - zoom->x1) * zoom->zoom;
	img_y = (zoom->x2 - zoom->x1) * zoom->zoom;
	get_data(param);
	x = 0;
	while (x < LARGEUR)
	{
		y = 0;
		while (y < HAUTEUR)
		{
			iter.c_r = 0.285;
			iter.c_i = 0.01;
			iter.z_r = x / zoom->zoom + zoom->x1;
			iter.z_i = y / zoom->zoom + zoom->y1;
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
				draw_px(x,y, i * 255 / zoom->iter_max, param);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}
