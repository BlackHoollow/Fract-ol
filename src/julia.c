/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:39:34 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/17 19:51:59 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define X1 -1.5
#define X2 1.5
#define Y1 -1.5
#define Y2 1.5
#define ZOOM 350

void	julia_iter(t_param *param)
{
	float	x;
	float	y;
	int		i;
	float	img_x;
	float	img_y;
	t_iter	iter;

	img_x = (X2 - X1) * ZOOM;
	img_y = (X2 - X1) * ZOOM;
	get_data(param);
	x = 0;
	while (x < LARGEUR)
	{
		y = 0;
		while (y < HAUTEUR)
		{
			iter.c_r = 0.285;
			iter.c_i = 0.01;
			iter.z_r = x / ZOOM + X1;
			iter.z_i = y / ZOOM + Y1;
			i = 0;
			while ((iter.z_r * iter.z_r + iter.z_i * iter.z_i) < 4 && i < ITERMAX)
			{
				iter.tmp = iter.z_r;
				iter.z_r = iter.z_r * iter.z_r - iter.z_i * iter.z_i + iter.c_r;
				iter.z_i = 2 * iter.z_i * iter.tmp + iter.c_i;
				i++;
			}
			if (i == ITERMAX)
				draw_px(x, y, 0xFFFFFF, param);
			else
				draw_px(x,y, i * 255 / ITERMAX, param);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}
