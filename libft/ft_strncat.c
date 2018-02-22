/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:54:25 by mdubrovs          #+#    #+#             */
/*   Updated: 2016/12/09 17:58:47 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	s1len;
	size_t	i;

	i = -1;
	s1len = ft_strlen(s1);
	while ((++i < n) && (s2[i] != '\0'))
		s1[s1len + i] = s2[i];
	s1[s1len + i] = '\0';
	return (s1);
}
