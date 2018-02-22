/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:48:33 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/02/13 18:26:38 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		check_line(char *s)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == 44 || s[i] == 45 || s[i] == 32 || ft_isdigit(s[i]) ||
			(ft_toupper(s[i]) >= 65 && ft_toupper(s[i]) <= 70) || s[i] == 'x')
		{
			if ((s[i] != 32) && ((s[i + 1] == 32) || (s[i + 1] == '\0')))
				cnt++;
			i++;
		}
		else
			endwitherror(1);
	}
	return (cnt);
}

static void		scan_lines(int fd, t_window *wnd)
{
	int		cnt;
	int		curlen;
	int		flag;
	char	*str;

	cnt = 0;
	while ((flag = get_next_line(fd, &str)) == 1)
	{
		if ((curlen = check_line(str)) == 0)
			endwitherror(2);
		(wnd->max_x == 0) ? wnd->max_x = curlen : wnd->max_x;
		if (curlen < wnd->max_x)
			endwitherror(3);
		free(str);
		cnt++;
	}
	if (flag == -1)
		endwitherror(4);
	wnd->max_y = cnt;
	wnd->hx = (wnd->max_x >> 1);
	wnd->hy = (wnd->max_y >> 1);
	close(fd);
}

static t_coord	scncell(char *s, int y, int x, t_window *wnd)
{
	int		k;
	char	*tmp;
	t_coord	point;

	k = 0;
	while (s[k] != '\0' && s[k] != ',')
		k++;
	tmp = ft_strsub(s, 0, k);
	point.z = ft_atoi(tmp);
	point.y = y;
	point.x = x;
	point.c.r = wnd->defr;
	point.c.g = wnd->defg;
	point.c.b = wnd->defb;
	if (s[k] == ',')
	{
		free(tmp);
		tmp = ft_strsub(s, k + 3, ft_strlen(s) - (k + 2));
		point.c = hex2rgb(ft_atoi_base(tmp, 16));
		wnd->diag = 1;
	}
	free(tmp);
	return (point);
}

static void		map_split(int fd, t_window *wnd)
{
	int		i;
	int		j;
	char	*str;
	char	**tmp;
	t_coord	**pts;

	if (!(pts = (t_coord**)malloc(sizeof(t_coord*) * wnd->max_y)))
		endwitherror(5);
	i = -1;
	while (++i < wnd->max_y)
		if (get_next_line(fd, &str) == 1)
		{
			tmp = ft_strsplit(str, ' ');
			pts[i] = (t_coord*)malloc(sizeof(t_coord) * wnd->max_x);
			j = -1;
			while (++j < wnd->max_x)
				pts[i][j] = scncell(tmp[j], (i - wnd->hy), (j - wnd->hx), wnd);
			j = -1;
			while (tmp[++j] != NULL)
				free(tmp[j]);
			free(tmp);
		}
	wnd->p = pts;
}

void			create_map(char *file, t_window *wnd)
{
	int		fd;

	wnd->rotx = 0;
	wnd->roty = 0;
	wnd->rotz = 0;
	wnd->max_x = 0;
	wnd->diag = 0;
	wnd->sclz = 1;
	wnd->scl = 5;
	wnd->orig.x = 1000;
	wnd->orig.y = 700;
	wnd->proj = 0;
	wnd->legend = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		endwitherror(4);
	else
		scan_lines(fd, wnd);
	if ((fd = open(file, O_RDONLY)) == -1)
		endwitherror(4);
	map_split(fd, wnd);
	close(fd);
}
