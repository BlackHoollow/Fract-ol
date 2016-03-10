/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:35:22 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/10 14:43:44 by nromptea         ###   ########.fr       */
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

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_param;

/*
**	core.c
*/

void			ft_exit(char *str);
int				my_key_func(int keycode, void *param);
void			draw_pixel(t_param *param);
int				main(int argc, char **argv);

#endif
