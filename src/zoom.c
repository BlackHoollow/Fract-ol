/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:36:08 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/22 18:14:07 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	zoom_in(t_param *param, int x, int y)
{
	double	xp;
	double	yp;
	double	amp;
	double	h;
	double	z;

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
	if (param->zoom.zoom <= 10000)
		param->zoom.zoom = param->zoom.zoom + 150;
	else
		param->zoom.zoom = param->zoom.zoom * 1.3;
	if (param->wich == 1)
		mandel_iter(param, &param->zoom);
	else if (param->wich == 2)
		julia_iter(param, &param->zoom);
	else if (param->wich == 3)
		burning_iter(param, &param->zoom);
}

void	zoom_out(t_param *param, int x, int y)
{
	double	xp;
	double	yp;
	double	amp;
	double	h;
	double	z;

	if (x < 0 || x > LARGEUR || y < 0 || y > HAUTEUR)
		return ;
	if (param->zoom.zoom <= 150)
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
	if (param->zoom.zoom <= 10000)
		param->zoom.zoom = param->zoom.zoom - 150;
	else
		param->zoom.zoom = param->zoom.zoom / 1.3;
	if (param->wich == 1)
		mandel_iter(param, &param->zoom);
	else if (param->wich == 2)
		julia_iter(param, &param->zoom);
	else if (param->wich == 3)
		burning_iter(param, &param->zoom);
}
