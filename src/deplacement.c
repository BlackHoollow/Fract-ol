/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:20:11 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/18 15:40:40 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_left(t_param *param)
{
	param->zoom.x1 = param->zoom.x1 / 1.1;
	if (param->wich == 1)
		mandel_iter(param, &param->zoom);
	if (param->wich  == 2)
		julia_iter(param, &param->zoom);
}

void	draw_right(t_param *param)
{
	param->zoom.x1 = param->zoom.x1 * 1.1;
	if (param->wich == 1)
		mandel_iter(param, &param->zoom);
	if (param->wich == 2)
	   julia_iter(param, &param->zoom);	
}

void	draw_up(t_param *param)
{
	param->zoom.y1 = param->zoom.y1 / 1.1;
	if (param->wich == 1)
		mandel_iter(param, &param->zoom);
	if (param->wich == 2)
		julia_iter(param, &param->zoom);
}

void	draw_down(t_param *param)
{
	param->zoom.y1 = param->zoom.y1 * 1.1;
	if (param->wich == 1)
		mandel_iter(param, &param->zoom);
	if (param->wich == 2)
		julia_iter(param, &param->zoom);
}
