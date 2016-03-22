/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 18:42:05 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/22 12:29:32 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		get_data(t_param *param)
{
	param->str_img = mlx_get_data_addr(param->img, &param->bits,
			&param->size_line, &param->endian);
}

int			get_color(int color)
{
	if (color == 0)
		color = 8;
	else if (color == 8)
		color = 16;
	else if (color == 16)
		color = 0;
	return (color);
}

void		change_color(t_param *param)
{
	param->color = get_color(param->color);
	if (param->wich == 1)
		mandel_iter(param, &param->zoom);
	if (param->wich == 2)
		julia_iter(param, &param->zoom);
}

void		mandel_iter(t_param *param, t_zoom *zoom)
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
				draw_px(x, y, (i * 255 / zoom->iter_max) << param->color, param);
			y = y + 1;
		}
		x = x + 1;
	}
/*	//attention ici
	int a;
	int j;
	for (a = 0; a < HAUTEUR; a++)
		draw_px(500, a, 0xFF0000, param);
	for (j = 0; j < LARGEUR; j++)
		draw_px(j, 500, 0xFF0000, param);
	//oui ici*/
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}
