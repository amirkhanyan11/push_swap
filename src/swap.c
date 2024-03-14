/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:18:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/14 20:39:30 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	swap(t_stack *const stack)
{
	t_node	*to_swap;

	to_swap = stack->m_head->m_next;
	if (to_swap == stack->m_tail)
		stack->m_tail = stack->m_head;
	else
		to_swap->m_next->m_prev = stack->m_head;
	to_swap->m_prev = stack->m_tail;
	stack->m_head->m_prev = to_swap;
	stack->m_head->m_next = to_swap->m_next;
	to_swap->m_next = stack->m_head;
	stack->m_head = to_swap;
	stack->m_tail->m_next = stack->m_head;
}

