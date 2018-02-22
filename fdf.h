/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:00:05 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/01/27 16:00:07 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define DEFR 255
# define DEFG 255
# define DEFB 255
# define DEFSTEP 1
# define DEFROT 0.1
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

typedef struct	s_color
{
	int	r;
	int g;
	int b;
}				t_color;

typedef struct	s_grad
{
	double r;
	double g;
	double b;
}				t_grad;

typedef struct	s_coord
{
	int		x;
	int		y;
	int		z;
	t_color	c;
}				t_coord;

typedef struct	s_line
{
	t_grad	grad;
	int		deltax;
	int		deltay;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		i;
	int		x;
	int		y;

}				t_line;

typedef struct	s_window
{
	void	*mlx;
	void	*win;
	int		max_x;
	int		max_y;
	int		diag;
	int		defr;
	int		defg;
	int		defb;
	double	rotx;
	double	roty;
	double	rotz;
	double	sclz;
	double	scl;
	int		hx;
	int		hy;
	int		proj;
	int		legend;
	t_coord orig;
	t_coord	**p;
}				t_window;

int				ft_atoi_base(char *str, int base);
int				rgb2hex(int r, int g, int b);
t_color			hex2rgb(int num);
void			create_map(char *file, t_window *wnd);
void			print_map(t_window *wnd);
void			endwitherror(int num);
void			brezen_line(t_coord beg, t_coord end, t_window *wnd);

#endif
