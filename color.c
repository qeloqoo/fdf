/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:00:11 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/02/13 18:05:04 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				rgb2hex(int r, int g, int b)
{
	r = ((r << 16) & 0xFF0000);
	g = ((g << 8) & 0x00FF00);
	b = (b & 0x000FF);
	return (r | g | b);
}

t_color			hex2rgb(int num)
{
	t_color col;

	col.r = ((num >> 16) & 0xFF);
	col.g = ((num >> 8) & 0xFF);
	col.b = ((num) & 0xFF);
	return (col);
}

static t_grad	gradient(t_coord b, t_coord e, int dx, int dy)
{
	t_grad grad;

	if ((dx >= dy) && (dx != 0))
	{
		grad.r = ((e.c.r - b.c.r) != 0) ? (double)((e.c.r - b.c.r) / dx) : 0;
		grad.g = ((e.c.g - b.c.g) != 0) ? (double)(e.c.g - b.c.g) / dx : 0;
		grad.b = ((e.c.b - b.c.b) != 0) ? (double)(e.c.b - b.c.b) / dx : 0;
	}
	else if ((dy > dx) && (dy != 0))
	{
		grad.r = ((e.c.r - b.c.r) != 0) ? (double)((e.c.r - b.c.r) / dy) : 0;
		grad.g = ((e.c.g - b.c.g) != 0) ? (double)(e.c.g - b.c.g) / dy : 0;
		grad.b = ((e.c.b - b.c.b) != 0) ? (double)(e.c.b - b.c.b) / dy : 0;
	}
	else
	{
		grad.r = 0;
		grad.g = 0;
		grad.b = 0;
	}
	return (grad);
}

static t_line	line_set(t_coord beg, t_coord end)
{
	t_line line;

	line.i = 0;
	line.deltax = abs(end.x - beg.x);
	line.deltay = -abs(end.y - beg.y);
	line.x = beg.x;
	line.y = beg.y;
	line.sx = beg.x < end.x ? 1 : -1;
	line.sy = beg.y < end.y ? 1 : -1;
	line.err = line.deltax + line.deltay;
	line.grad = gradient(beg, end, abs(end.x - beg.x), abs(end.y - beg.y));
	return (line);
}

void			brezen_line(t_coord beg, t_coord end, t_window *wnd)
{
	t_line	line;

	line = line_set(beg, end);
	while (1)
	{
		mlx_pixel_put(wnd->mlx, wnd->win, line.x, line.y,
			rgb2hex(beg.c.r + line.grad.r * line.i, beg.c.g +
				line.grad.g * line.i, beg.c.b + line.grad.b * line.i));
		if (line.x == end.x && line.y == end.y)
			break ;
		line.e2 = line.err * 2;
		if (line.e2 > line.deltay)
		{
			line.err += line.deltay;
			line.x += line.sx;
		}
		if (line.e2 < line.deltax)
		{
			line.err += line.deltax;
			line.y += line.sy;
		}
		line.i++;
	}
}
