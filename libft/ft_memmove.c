/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:21:34 by mdubrovs          #+#    #+#             */
/*   Updated: 2016/12/09 15:36:11 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (dst < src)
		while (++i < n)
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
	else
		while (++i < n)
			((unsigned char*)dst)[n - i - 1] = ((unsigned char*)src)[n - i - 1];
	return (dst);
}
