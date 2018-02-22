/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:44:23 by mdubrovs          #+#    #+#             */
/*   Updated: 2016/11/30 14:17:32 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
	{
		write(2, "ENOMEM\n", 7);
		return (NULL);
	}
	ft_strcpy(res, s1);
	return (res);
}
