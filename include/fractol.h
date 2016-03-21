/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:35:22 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/21 16:49:54 by nromptea         ###   ########.fr       */
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

typedef struct	s_zoom
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	int		zoom;
	int			iter_max;
}				t_zoom;

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*str_img;
	int			bits;
	int			size_line;
	int			endian;
	t_zoom		zoom;
	int			wich;
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
int				my_mouse_func(int button,int x, int y, void *param);
void			draw_px(int x, int y, int color, t_param *param);
void			init_zoom(t_zoom *zoom);
void			wich_one(char *argv, t_param *param);
int				main(int argc, char **argv);

/*
**	mandelbrot.c
*/

void			get_data(t_param *param);
void			mandel_iter(t_param *param, t_zoom *zoom);

/*
**	julia.c
*/

void			julia_iter(t_param *param, t_zoom *zoom);

/*
**	deplacements.c
*/

void	draw_left(t_param *param);
void	draw_right(t_param *param);
void	draw_up(t_param *param);
void	draw_down(t_param *param);

/*
**	iter.c
*/

void	iter_plus(t_param *param);
void	iter_moins(t_param *param);

/*
**	zoom.c
*/

void	zoom_in(t_param *param, int x, int y);
void	zoom_out(t_param *param, int x, int y);

#endif
