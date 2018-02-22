/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:14:19 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/01/18 15:00:16 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_fdlist	*list_edit(const int fd)
{
	static t_fdlist	*lst;
	t_fdlist		*cur;

	cur = lst;
	while (1)
	{
		if (cur == NULL)
		{
			if (!(cur = (t_fdlist*)malloc(sizeof(t_fdlist))))
				return (NULL);
			cur->fd = fd;
			cur->txt = ft_strnew(0);
			cur->next = lst;
			lst = cur;
			return (cur);
		}
		else if (cur->fd == fd)
			return (cur);
		else
			cur = cur->next;
	}
	return (cur);
}

static int		scan_txt(t_fdlist *curr, char **line)
{
	size_t	i;
	char	*tmp;

	if (curr == NULL || curr->txt == NULL)
		return (0);
	i = -1;
	while ((curr->txt)[++i] != '\0')
	{
		if ((curr->txt)[i] == '\n')
		{
			*line = ft_strsub(curr->txt, 0, i);
			if ((i + 1) < ft_strlen(curr->txt))
				tmp = ft_strsub(curr->txt, (i + 1),
					(ft_strlen(curr->txt) - i - 1));
			else
				tmp = ft_strnew(0);
			free(curr->txt);
			curr->txt = tmp;
			return (1);
		}
	}
	return (0);
}

static int		scan_buff(char *buf, t_fdlist *curr, char **line)
{
	size_t	i;
	char	*tmp;
	size_t	len;

	i = -1;
	len = ft_strlen(buf);
	while (buf[++i] != '\0')
	{
		if (buf[i] == '\n')
		{
			tmp = ft_strsub(buf, 0, i);
			*line = ft_strjoin(curr->txt, tmp);
			free(tmp);
			free(curr->txt);
			if (i + 1 < len)
				curr->txt = ft_strsub(buf, (i + 1), (len - i - 1));
			else
				curr->txt = ft_strnew(0);
			return (1);
		}
	}
	tmp = curr->txt;
	curr->txt = ft_strjoin(curr->txt, buf);
	free(tmp);
	return (0);
}

static int		cleanup(t_fdlist *curr, char **line)
{
	size_t	len;

	len = ft_strlen(curr->txt);
	if (len > 0)
	{
		*line = ft_strsub(curr->txt, 0, len);
		free(curr->txt);
		curr->txt = ft_strnew(0);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	t_fdlist		*curr;
	int				flag;

	if (!(flag = 1) || fd < 0 || BUFF_SIZE == 0)
		return (-1);
	curr = list_edit(fd);
	if (scan_txt(curr, line) == 1)
		return (1);
	while (flag != 0)
	{
		if ((flag = read(curr->fd, buf, BUFF_SIZE)) > -1)
		{
			buf[flag] = '\0';
			if (scan_buff(buf, curr, line) && flag != 0)
				return (1);
		}
		else
			return (-1);
	}
	if (cleanup(curr, line))
		return (1);
	return (0);
}
