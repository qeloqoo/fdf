/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:41:31 by mdubrovs          #+#    #+#             */
/*   Updated: 2016/12/01 16:46:29 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;
	char		chr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd(('-'), fd);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr_fd((nbr / 10), fd);
	chr = nbr % 10 + '0';
	ft_putchar_fd(chr, fd);
}
