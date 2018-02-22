/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:01:38 by mdubrovs          #+#    #+#             */
/*   Updated: 2016/12/13 18:25:50 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_wspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*tmp;
	size_t	i;
	size_t	start;

	if (!s)
		return (NULL);
	start = 0;
	while (is_wspace(s[start]) && (s[start]))
		start++;
	i = ft_strlen(s);
	if (start != i)
		while ((i != 0) && is_wspace(s[i - 1]))
			i--;
	i = (i - start) > 0 ? (i - start) : 0;
	if (!(tmp = ft_strsub(s, start, i)))
		return (NULL);
	return (tmp);
}
