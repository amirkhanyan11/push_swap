/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:16:18 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/25 19:23:50 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	_print(t_node *node)
{
	printf("%d  ", node->m_val);
}

void	_clear(t_node *const node)
{
	free(node);
}

void	traverse(t_fptr f, t_node *head)
{
	t_node	*end;
	t_node	*tmp;

	if (NULL == head)
		return ;
	end = head->m_prev;
	while (head != end)
	{
		tmp = head->m_next;
		f(head);
		head = tmp;
	}
	f(head);
}

t_node	*traverse_binary_predicate(t_cmp f, t_node *head)
{
	t_node	*end;
	t_node	*target;

	if (NULL == head)
		return (NULL);
	end = head->m_prev;
	target = head;
	while (head != end)
	{
		target = f(head, target);
		head = head->m_next;
	}
	target = f(head, target);
	return (target);
}

int	traverse_unary_predicate(t_unary_predicate f, t_stack *const stack,
		t_node *start, t_node *end)
{
	t_node	*tmp;

	if (NULL == start || start->m_next == end)
		return (1);
	while (start->m_next != end)
	{
		tmp = start->m_next;
		if (f(start))
		{
			if (start == stack->m_head
				&& (start->m_val < start->m_next->m_next->m_val
					|| (start->m_prev == start->m_next->m_next
						&& start->m_next->m_val > start->m_prev->m_val))
				&& traverse_unary_predicate(f, stack, start->m_next->m_next,
					stack->m_head))
			{
				swap(stack, visible);
				return (fullsorted(stack));
			}
			return (0);
		}
		start = tmp;
	}
	return (1);
}
