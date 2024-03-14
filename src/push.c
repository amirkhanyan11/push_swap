/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:15:40 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/14 20:39:30 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	push(int const val, t_stack *const obj)
{
	t_node	*new_node;

	new_node = node_init(val);
	new_node->m_next = obj->m_head;
	if (!empty(obj))
		obj->m_head->m_prev = new_node;
	obj->m_head = new_node;
	if (obj->m_tail == NULL)
		obj->m_tail = obj->m_head;
	obj->m_tail->m_next = obj->m_head;
	obj->m_head->m_prev = obj->m_tail;
}


void	push_a_b(t_stack *const lhv, t_stack *const rhv)
{
	int	val;

	val = pop(lhv);
	push(val, rhv);
}



