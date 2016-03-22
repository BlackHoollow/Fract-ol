/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:35:22 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/22 19:09:35 by nromptea         ###   ########.fr       */
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

typedef struct	s_pnt
{
	double	x;
	double	y;
}				t_pnt;

typedef struct	s_iter
{
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
}				t_iter;

typedef struct	s_zoom
{
	double		x1;
	double		y1;
	int			zoom;
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
	int			color;
	int			mouse;
	t_iter		itera;
}				t_param;

/*
**	core.c
*/

int				my_key_func(int keycode, void *param);
int				my_mouse_func(int button, int x, int y, t_param *param);
int				func_mouse(int x, int y, t_param *param);
void			wich_one(char *argv, t_param *param);
int				main(int argc, char **argv);

/*
**	utility.c
*/

void			ft_exit(void);
void			draw_px(int x, int y, int color, t_param *param);
void			init_zoom(t_param *param);

/*
**	mandelbrot.c
*/

int				get_color(int color);
void			change_color(t_param *param);
void			get_data(t_param *param);
void			mandel2(t_iter iter, t_zoom *zoom, t_param *param, t_pnt *pnt);
void			mandel_iter(t_param *param, t_zoom *zoom);

/*
**	julia.c
*/

void			julia2(t_iter iter, t_zoom *zoom, t_param *param, t_pnt *pnt);
void			julia_iter(t_param *param, t_zoom *zoom);

/*
**	deplacements.c
*/

void			draw_left(t_param *param);
void			draw_right(t_param *param);
void			draw_up(t_param *param);
void			draw_down(t_param *param);

/*
**	iter.c
*/

void			iter_plus(t_param *param);
void			iter_moins(t_param *param);

/*
**	zoom.c
*/

void			zoom_in(t_param *param, int x, int y);
void			zoom_out(t_param *param, int x, int y);

/*
**	burning.c
*/

void			burning2(t_iter iter, t_zoom *zoom, t_param *param, t_pnt *pnt);
void			burning_iter(t_param *param, t_zoom *zoom);

#endif
