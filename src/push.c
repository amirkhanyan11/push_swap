/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:15:40 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/26 16:07:17 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int const val, t_stack *const stack)
{
	t_node	*new_node;

	new_node = node_init(val);
	new_node->m_next = stack->m_head;
	if (empty(stack))
	{
		stack->m_head = new_node;
		stack->m_head->m_next = new_node;
		stack->m_head->m_prev = new_node;
		return ;
	}
	stack->m_head->m_prev->m_next = new_node;
	new_node->m_prev = stack->m_head->m_prev;
	stack->m_head->m_prev = new_node;
	stack->m_head = new_node;
}

void	push_a_b(t_stack *const lhv, t_stack *const rhv)
{
	int	val;

	val = pop(lhv);
	push(val, rhv);
	ft_printf("p%c\n", rhv->m_name);
}
