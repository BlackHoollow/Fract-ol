/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:36:08 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/21 20:20:08 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_param *param, int x, int y)
{
	float	xp;
	float	yp;

	if (x < 0 || x > LARGEUR || y < 0 || y > HAUTEUR)
		return ;
	xp = (x * (fabs(param->zoom.x1) * 2) / LARGEUR);
	yp = (y * (fabs(param->zoom.y1) * 2) / HAUTEUR);
	xp = xp - fabs(param->zoom.x1);
	yp = yp - fabs(param->zoom.y1);
	param->zoom.x1 = (param->zoom.x1) + xp;
	param->zoom.y1 = (param->zoom.y1) + yp;
//	param->zoom.zoom = param->zoom.zoom + 50;
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
