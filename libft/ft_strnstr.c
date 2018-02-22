/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:19:26 by mdubrovs          #+#    #+#             */
/*   Updated: 2016/12/09 15:57:48 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *ltl, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ltl[0] == '\0')
		return ((char*)&big[0]);
	while ((big[i] != '\0') && (i < len))
	{
		j = 0;
		while ((big[i + j] == ltl[j]) && ltl[j] && big[i + j] && (i + j < len))
			j++;
		if (ltl[j] == '\0')
			return ((char*)&big[i]);
		i++;
	}
	return (NULL);
}
