/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:28:28 by aamirkha          #+#    #+#             */
/*   Updated: 2024/01/29 20:09:06 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_lstmap(t_list *other, t_list **head,
				void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;

	head = NULL;
	if (!lst || !f || !del)
		return (NULL);
	_lstmap(lst, &head, f, del);
	return (head);
}

static void	_lstmap(t_list *other, t_list **head,
				void *(*f)(void *), void (*del)(void *))
{
	if (!other)
		return ;
	*head = ft_lstnew(f(other->content));
	if (!head)
	{
		ft_lstclear(head, del);
		return ;
	}
	_lstmap(other->next, &((*head)->next), f, del);
}
