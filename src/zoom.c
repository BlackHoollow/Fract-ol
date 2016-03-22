/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:36:08 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/22 12:28:56 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	zoom_in(t_param *param, int x, int y)
{
	float	xp;
	float	yp;
	float	amp;
	float	h;
	float	z;

	if (x < 0 || x > LARGEUR || y < 0 || y > HAUTEUR)
		return ;
	h = HAUTEUR;
	z = param->zoom.zoom;
	amp = h / z;
	xp = (x * (amp / LARGEUR));
	yp = (y * (amp / HAUTEUR));
	xp = xp - fabs(param->zoom.x1);
	yp = yp - fabs(param->zoom.y1);
	amp = amp / 2;
	param->zoom.x1 = xp - amp;
	param->zoom.y1 = yp - amp;
	param->zoom.zoom = param->zoom.zoom + 50;
	if (param->wich == 1)
		mandel_iter(param, &param->zoom);
	if (param->wich == 2)
		julia_iter(param, &param->zoom);
}

void	zoom_out(t_param *param, int x, int y)
{
/*	param->zoom.x1 = x + H;
	param->zoom.y1 = y + H;*/
	x = x + 0;
	y = y + 0;
	param->zoom.zoom = param->zoom.zoom - 50;
	if (param->wich == 1)
		mandel_iter(param, &param->zoom);
	if (param->wich == 2)
		julia_iter(param, &param->zoom);
}
