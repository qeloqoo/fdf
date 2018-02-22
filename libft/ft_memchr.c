/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:15:21 by mdubrovs          #+#    #+#             */
/*   Updated: 2016/11/30 17:42:28 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *stmp;

	stmp = (unsigned char*)s;
	while (n-- != 0)
	{
		if (*stmp == (unsigned char)c)
			return ((void*)stmp);
		stmp++;
	}
	return (NULL);
}
