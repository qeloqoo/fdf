/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:23:42 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/02/15 16:17:27 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

void	set_color(t_window *wnd)
{
	wnd->defr = DEFR;
	wnd->defg = DEFG;
	wnd->defb = DEFB;
}

void	reset_xyz(t_window *wnd)
{
	wnd->rotx = 0;
	wnd->roty = 0;
	wnd->rotz = 0;
	wnd->sclz = 1;
}

int		keyevent(int keycode, t_window *wnd)
{
	if (keycode == 53)
	{
		mlx_destroy_window(wnd->mlx, wnd->win);
		exit(0);
	}
	if (keycode == 44)
		wnd->legend = (wnd->legend == 0) ? 1 : 0;
	if (keycode == 75)
		wnd->diag = (wnd->diag == 0) ? 1 : 0;
	if (keycode == 67)
		wnd->proj = (wnd->proj == 0) ? 1 : 0;
	(keycode == 84) ? wnd->rotx += DEFROT : 0;
	(keycode == 91) ? wnd->rotx -= DEFROT : 0;
	(keycode == 88) ? wnd->roty += DEFROT : 0;
	(keycode == 86) ? wnd->roty -= DEFROT : 0;
	(keycode == 89) ? wnd->rotz += DEFROT : 0;
	(keycode == 92) ? wnd->rotz -= DEFROT : 0;
	(keycode == 83) ? wnd->sclz -= 0.2 : 0;
	(keycode == 85) ? wnd->sclz += 0.2 : 0;
	if (keycode == 87)
		reset_xyz(wnd);
	mlx_clear_window(wnd->mlx, wnd->win);
	print_map(wnd);
	return (0);
}

int		mouseevent(int button, int x, int y, t_window *wnd)
{
	if (button == 1)
	{
		wnd->orig.x = x;
		wnd->orig.y = y;
	}
	if (button == 4)
		(wnd->scl <= 30) ? wnd->scl += DEFSTEP : 0;
	if (button == 5)
		(wnd->scl >= 2) ? wnd->scl -= DEFSTEP : 0;
	mlx_clear_window(wnd->mlx, wnd->win);
	print_map(wnd);
	return (0);
}

int		main(int argc, char **argv)
{
	t_window	*wnd;

	if (argc < 2 && argc > 5)
		endwitherror(6);
	if (!(wnd = (t_window*)malloc(sizeof(t_window))))
		endwitherror(5);
	if (argc < 3)
		set_color(wnd);
	if (argc > 2)
		wnd->defr = ((ft_atoi(argv[2]) >= 0 && (ft_atoi(argv[2]) <= 255))) ?
			ft_atoi(argv[2]) : 255;
	if (argc > 3)
		wnd->defg = ((ft_atoi(argv[3]) >= 0 && (ft_atoi(argv[3]) <= 255))) ?
			ft_atoi(argv[3]) : 255;
	if (argc > 4)
		wnd->defb = ((ft_atoi(argv[4]) >= 0 && (ft_atoi(argv[4]) <= 255))) ?
			ft_atoi(argv[4]) : 255;
	create_map(argv[1], wnd);
	wnd->mlx = mlx_init();
	wnd->win = mlx_new_window(wnd->mlx, 2000, 1500, "Fukken Windaw!");
	print_map(wnd);
	mlx_key_hook(wnd->win, keyevent, wnd);
	mlx_mouse_hook(wnd->win, mouseevent, wnd);
	mlx_loop(wnd->mlx);
	return (0);
}
