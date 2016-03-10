/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:56:58 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/10 17:28:10 by nromptea         ###   ########.fr       */
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
	ft_putstr("keycode = ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	draw_pixel(param);
	if (keycode == 53)
		ft_exit("quit");
	return (0);
}
void		draw_px(char *s, int x, int y, const int color, int bpp, int size_line)
{
	*(int *)(unsigned long)(s + (size_line * y) +
			(x * bpp / 8)) = color;
}
void	draw_pixel(t_param *param)
{
	char	*str;
	int		bits;
	int		size_line;
	int		endian;

	str = mlx_get_data_addr(param->img, &bits, &size_line, &endian);
	draw_px(str, 999, 200, 0xFF0000, bits, size_line);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
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
	mlx_loop(param.mlx);
}
