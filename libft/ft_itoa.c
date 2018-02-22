/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:46:48 by mdubrovs          #+#    #+#             */
/*   Updated: 2016/12/06 16:19:25 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cnt_chrs(int n)
{
	size_t	cnt;

	cnt = 0;
	if (n <= 0)
		cnt++;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	i;

	if (!(str = ft_strnew(ft_cnt_chrs(n))))
		return (NULL);
	i = ft_cnt_chrs(n);
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		if (n > 0)
			str[--i] = n % 10 + '0';
		else if (n < 0)
			str[--i] = '0' - (n % 10);
		n /= 10;
	}
	return (str);
}
