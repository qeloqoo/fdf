/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:50:11 by mdubrovs          #+#    #+#             */
/*   Updated: 2016/12/08 17:46:44 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur;
	t_list	*nxt;

	if (alst && *alst && *del)
	{
		cur = *alst;
		while (cur)
		{
			nxt = cur->next;
			del(cur->content, cur->content_size);
			free(cur);
			cur = nxt;
		}
	}
	*alst = NULL;
}
