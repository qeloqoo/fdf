/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:33:28 by mdubrovs          #+#    #+#             */
/*   Updated: 2016/12/13 17:26:47 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tmp;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	if (!(tmp = ft_strnew(len)))
		return (NULL);
	i = -1;
	while ((++i < len) && s[start + i])
		tmp[i] = s[start + i];
	return (tmp);
}
