/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:35:22 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/18 14:13:21 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define HAUTEUR 1000
# define LARGEUR 1000
# define ITERMAX 50

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*str_img;
	int			bits;
	int			size_line;
	int			endian;
}				t_param;

typedef struct	s_iter
{
	float		c_r;
	float		c_i;
	float		z_r;
	float		z_i;
	float		tmp;
}				t_iter;

/*
**	core.c
*/

void			ft_exit(char *str);
int				my_key_func(int keycode, void *param);
int				my_mouse_func(int button, void *param);
void			draw_px(int x, int y, int color, t_param *param);
void			wich_one(char *argv, t_param *param);
int				main(int argc, char **argv);

/*
**	mandelbrot.c
*/

void			get_data(t_param *param);
void			mandel_iter(t_param *param);

/*
**	julia.c
*/

void			julia_iter(t_param *param);

#endif
