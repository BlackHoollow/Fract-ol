/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:56:58 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/22 17:46:51 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		my_key_func(int keycode, void *param)
{
	param = param + 0;
	if (keycode == 53)
		ft_exit("quit");
	if (keycode == 123)
		draw_left(param);
	if (keycode == 124)
		draw_right(param);
	if (keycode == 126)
		draw_up(param);
	if (keycode == 125)
		draw_down(param);
	if (keycode == 69)
		iter_plus(param);
	if (keycode == 78)
		iter_moins(param);
	if (keycode == 82)
		change_color(param);
	return (0);
}

int		my_mouse_func(int button, int x, int y, t_param *param)
{
	if (button == 4 || button == 1)
		zoom_in(param, x, y);
	if (button == 5 || button == 2)
		zoom_out(param, x, y);
	if (button == 3)
	{
		if (param->mouse == 0)
			param->mouse = 1;
		else
			param->mouse = 0;
	}
	return (0);
}

int		func_mouse(int x, int y, t_param *param)
{
	if (param->mouse == 1)
	{
		param->itera.c_r = (double)x / param->zoom.zoom + param->zoom.x1;
		param->itera.c_i = (double)y / param->zoom.zoom + param->zoom.y1;
		julia_iter(param, &param->zoom);
	}
	return (0);
}

void	wich_one(char *argv, t_param *param)
{
	int		arg;
	t_zoom	zoom;

	arg = ft_atoi(argv);
	init_zoom(&zoom);
	param->color = 0;
	param->zoom = zoom;
	param->mouse = 0;
	if (arg != 1 && arg != 2 && arg != 3)
		ft_exit("Erreur");
	if (arg == 1)
	{
		param->wich = 1;
		mandel_iter(param, &param->zoom);
	}
	else if (arg == 2)
	{
		param->wich = 2;
		param->itera.c_r = -0.8;
		param->itera.c_i = 0.156;
		julia_iter(param, &zoom);
	}
	else if (arg == 3)
	{
		param->wich = 3;
		burning_iter(param, &zoom);
	}
}

int		main(int argc, char **argv)
{
	t_param		param;

	argv = argv + 0;
	if (argc != 2)
		ft_exit("Erreur");
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, LARGEUR, HAUTEUR, "fractol");
	param.img = mlx_new_image(param.mlx, LARGEUR, HAUTEUR);
	mlx_mouse_hook(param.win, my_mouse_func, &param);
	mlx_key_hook(param.win, my_key_func, &param);
	mlx_hook(param.win, 6, 0, func_mouse, &param);
	wich_one(argv[1], &param);
	mlx_loop(param.mlx);
}
