/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:12:55 by aamirkha          #+#    #+#             */
/*   Updated: 2024/01/29 20:09:06 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_deallocate(t_list **lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !(*lst) || !del)
		return ;
	_deallocate(lst, del);
	lst = NULL;
}

static void	_deallocate(t_list **lst, void (*del)(void *))
{
	if (!(*lst))
		return ;
	_deallocate(&((*lst)->next), del);
	ft_lstdelone((*lst), del);
	(*lst) = NULL;
}
