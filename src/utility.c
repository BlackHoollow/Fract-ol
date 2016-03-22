/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:26:51 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/22 18:56:09 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit(char *str)
{
	ft_putendl(str);
	exit(1);
}

void	draw_px(int x, int y, int color, t_param *param)
{
	*(int *)(unsigned long)(param->str_img + (param->size_line * y) +
			(x * param->bits / 8)) = color;
}

void	init_zoom(t_param *param)
{
	t_zoom	zoom;

	zoom.x1 = -2.2;
	zoom.y1 = -1.65;
	zoom.zoom = 300;
	zoom.iter_max = 50;
	param->color = 0;
	param->zoom = zoom;
	param->mouse = 0;
}
