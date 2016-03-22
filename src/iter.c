/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:38:35 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/22 18:11:24 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter_plus(t_param *param)
{
	param->zoom.iter_max = param->zoom.iter_max + 5;
	if (param->wich == 1)
		mandel_iter(param, &param->zoom);
	else if (param->wich == 2)
		julia_iter(param, &param->zoom);
	else if (param->wich == 3)
		burning_iter(param, &param->zoom);
}

void	iter_moins(t_param *param)
{
	param->zoom.iter_max = param->zoom.iter_max - 5;
	if (param->wich == 1)
		mandel_iter(param, &param->zoom);
	else if (param->wich == 2)
		julia_iter(param, &param->zoom);
	else if (param->wich == 3)
		burning_iter(param, &param->zoom);
}
