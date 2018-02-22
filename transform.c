/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:56:31 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/02/15 16:18:36 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	set_iso(double tx, double ty, double tz, t_window *wnd)
{
	t_coord tmp;

	tmp.x = round(wnd->orig.x + (tx * 0.707) - (ty * 0.707));
	tmp.y = round(wnd->orig.y + (tx * 0.409) + (ty * 0.409) - (tz * 0.816));
	return (tmp);
}

static t_coord	set_par(double tx, double ty, double tz, t_window *wnd)
{
	t_coord tmp;

	tmp.x = round(wnd->orig.x + ((ty + tz) * 0.5 + tx));
	tmp.y = round(wnd->orig.y + ((ty - tz) * 0.866));
	return (tmp);
}

static t_coord	trans_point(t_coord p, t_window *wnd)
{
	t_coord	tmp;
	double	tx;
	double	ty;
	double	tz;

	tx = ((wnd->scl * p.x * cos(wnd->roty) + (wnd->scl * wnd->sclz * p.z *
		cos(wnd->rotx) - wnd->scl * p.y * sin(wnd->rotx)) * sin(wnd->roty)) *
		cos(wnd->rotz) + (wnd->scl * p.y * cos(wnd->rotx) + wnd->scl *
		wnd->sclz * p.z * sin(wnd->rotx)) * sin(wnd->rotz));
	ty = ((wnd->scl * p.y * cos(wnd->rotx) + wnd->scl * wnd->sclz * p.z *
		sin(wnd->rotx)) * cos(wnd->rotz) - (wnd->scl * p.x * cos(wnd->roty) +
		(wnd->scl * wnd->sclz * p.z * cos(wnd->rotx) - wnd->scl * p.y *
		sin(wnd->rotx)) * sin(wnd->roty)) * sin(wnd->rotz));
	tz = ((wnd->scl * wnd->sclz * p.z * cos(wnd->rotx) - wnd->scl * p.y *
		sin(wnd->rotx)) * cos(wnd->roty) - wnd->scl * p.x * sin(wnd->roty));
	if (wnd->proj == 0)
		tmp = set_iso(tx, ty, tz, wnd);
	else
		tmp = set_par(tx, ty, tz, wnd);
	tmp.c = p.c;
	return (tmp);
}

static void		print_legend(t_window *wnd)
{
	if (wnd->proj == 0)
		mlx_string_put(wnd->mlx, wnd->win, 10, 5, 0x00FF00, "ISO PROJECTION");
	else
		mlx_string_put(wnd->mlx, wnd->win,
			10, 5, 0x00FF00, "PARALLEL PROJECTION");
	mlx_string_put(wnd->mlx, wnd->win,
		10, 20, 0xFF0000, "CONTROLS");
	mlx_string_put(wnd->mlx, wnd->win,
		10, 35, 0xFFFFFF, "Rot. X Axis +/-   : Num_2 / Num_8");
	mlx_string_put(wnd->mlx, wnd->win,
		10, 50, 0xFFFFFF, "Rot. Y Axis +/-   : Num_6 / Num_4");
	mlx_string_put(wnd->mlx, wnd->win,
		10, 65, 0xFFFFFF, "Rot. Z Axis +/-   : Num_9 / Num_7");
	mlx_string_put(wnd->mlx, wnd->win,
		10, 80, 0xFFFFFF, "Reset             : Num_5");
	mlx_string_put(wnd->mlx, wnd->win,
		10, 95, 0xFFFFFF, "Zoom +/-          : Mouse Wheel");
	mlx_string_put(wnd->mlx, wnd->win,
		10, 110, 0xFFFFFF, "Toggle diagonals  : Num_/");
	mlx_string_put(wnd->mlx, wnd->win,
		10, 125, 0xFFFFFF, "Toggle projection : Num_*");
	mlx_string_put(wnd->mlx, wnd->win,
		10, 140, 0xFFFFFF, "Scale Z +/-       : Num_3 / Num_1");
}

void			print_map(t_window *wnd)
{
	int		i;
	int		j;
	t_coord tmp1;

	i = 0;
	if (wnd->legend == 1)
		print_legend(wnd);
	while (i < wnd->max_y)
	{
		j = 0;
		while (j < wnd->max_x)
		{
			tmp1 = trans_point(wnd->p[i][j], wnd);
			if (j - 1 >= 0)
				brezen_line(tmp1, trans_point(wnd->p[i][j - 1], wnd), wnd);
			if (i + 1 < wnd->max_y)
				brezen_line(tmp1, trans_point(wnd->p[i + 1][j], wnd), wnd);
			if ((i + 1 < wnd->max_y) && (j - 1 >= 0) && (wnd->diag == 1))
				brezen_line(tmp1, trans_point(wnd->p[i + 1][j - 1], wnd), wnd);
			if (j == 0 && i == 0)
				brezen_line(tmp1, tmp1, wnd);
			j++;
		}
		i++;
	}
}
