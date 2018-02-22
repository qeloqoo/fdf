/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:57:18 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/02/13 17:58:46 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	endwitherror(int num)
{
	if (num == 1)
		ft_putstr("Illegal symbol found in file\n");
	if (num == 2)
		ft_putstr("Empty line found\n");
	if (num == 3)
		ft_putstr("Not enough data in one of the lines\n");
	if (num == 4)
		ft_putstr("Error while reading file\n");
	if (num == 5)
		ft_putstr("Could not allocate memory\n");
	if (num == 6)
		ft_putstr("Not enough or too many parameters specified");
	exit(0);
}
