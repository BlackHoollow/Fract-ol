/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:56:58 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/17 19:49:51 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit(char *str)
{
	ft_putendl(str);
	exit(1);
}

int		my_key_func(int keycode, void *param)
{
	param = param + 0;
	if (keycode == 53)
		ft_exit("quit");
	return (0);
}

void	draw_px(int x, int y, int color, t_param *param)
{
	*(int *)(unsigned long)(param->str_img + (param->size_line * y) +
			(x * param->bits / 8)) = color;
}

void	wich_one(char *argv, t_param *param)
{
	int		arg;

	arg = ft_atoi(argv);
	if (arg != 1 && arg != 2)
		ft_exit("Erreur");
	if (arg == 1)
	{
		mandel_iter(param);
	}
	else if (arg == 2)
	{
		julia_iter(param);
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
	mlx_key_hook(param.win, my_key_func, &param);
	wich_one(argv[1], &param);
	mlx_loop(param.mlx);
}
